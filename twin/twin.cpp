//Created by Hussein 2026-05-01
#include "twin.hpp"
#include "twinCallback.hpp"

twinService::twinService(const std::string& broker, const std::string& role)
    : client(broker, "twin_controller"), nodeRole(role), activeEdge("home"), counter(0) {}

void twinService::start() {
    twinCallback cb(*this);
    client.set_callback(cb);
    client.connect()->wait();
    client.subscribe("twin/data", 1)->wait();
    client.subscribe("system/lane", 1)->wait();

    std::cout << "[TWIN] Running on " << nodeRole << std::endl;
    while (true)
        std::this_thread::sleep_for(std::chrono::seconds(5));
}

void twinService::setActiveLane(const std::string& edge) {
    std::string route = resolveRoute(edge);
    nlohmann::json msg;
    msg["type"]="route_update";
    msg["edge"]=edge;
    msg["route"]=route;
    client.publish("system/lane", msg.dump().c_str(), msg.dump().size(), 1, true);
    std::cout<<"[TWIN] "<< edge<< " ->" << route <<std::endl;
}
std::string twinService::resolveRoute(const std::string& edge) {
    if (edge == "home") return "fog1";
    if (edge == "work") return "fog2";
    return "cloud";
}

void twinService::handleMessage(const nlohmann::json& j) {
    std::string edge = j.value("edgeNode", "");
    if (edge != activeEdge) return;
    counter++;
    std::cout<<"[TWIN] data accepted from " << edge <<" counter =" << counter<<std::endl;
}