//Created by Hussein 2026-05-01
#include "twin.hpp"

twinService::twinService(const std::string& broker, const std::string& device)
    : client(broker, "twin_controller"), device(device), cb(*this){}

void twinService::start() {
    client.set_callback(cb);
    client.connect()->wait();
    std::cout << "[TWIN] Running on " << device << std::endl;
    if (device == "home") currentPhase = 0;
    else if (device == "mobile") currentPhase = 1;
    else currentPhase = 2;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    broadcastActive(device);
    std::thread([this]() {
        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(60));
            currentPhase = (currentPhase + 1) % 3;
            switchPhase(currentPhase);
        }
    }).detach();
    while (true)
        std::this_thread::sleep_for(std::chrono::seconds(5));
}

void twinService::broadcastActive(const std::string& activeEdge) {
    for (auto& type : {"home", "work", "mobile"}) {
        nlohmann::json msg;
        msg["edgeNode"]=type;
        msg["active"]=(type==activeEdge);
        client.publish(config::TOPIC_LANE, msg.dump().c_str(), msg.dump().size(), 1, false);
        std::cout<<"[TWIN]" << type << " active=" << (type==activeEdge) << std::endl;
    }
}

void twinService::switchPhase(int phase) {
    std::string activeEdge;
    std::string targetNode;
    if (phase == 0) {
        activeEdge = "home";
        targetNode = "Ehome";
        std::cout << "[TWIN] Phase 0: hemma" << std::endl;
    } else if (phase == 1) {
        activeEdge = "mobile";
        targetNode = "Emob";
        std::cout << "[TWIN] Phase 1: resande" << std::endl;
    } else {
        activeEdge = "work";
        targetNode = "Ework";
        std::cout << "[TWIN] Phase 2: jobbet" << std::endl;
    }
    nlohmann::json migrate;
    migrate["action"]="migrate";
    migrate["target"] = targetNode;
    migrate["role"] = activeEdge;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    client.publish("system/migrate", migrate.dump().c_str(), migrate.dump().size(), 1, false);
    broadcastActive(activeEdge);
}