//Created by Hussein 2026-05-01
#include "twin.hpp"

twinService::twinService(const std::string& broker, const std::string& role)
    : client(broker, "twin_controller"), nodeRole(role), cb(*this){}

void twinService::start() {
    const char* file_env=std::getenv("ROUTING_FILE");
    std::string file=file_env ? file_env : "/app/common/routing.json";
    loadRoutingConfig(file);
    client.set_callback(cb);
    client.connect()->wait();
    client.subscribe(config::TOPIC_TWIN, 1)->wait();
    std::cout << "[TWIN] Running on " << nodeRole << std::endl;
    while (true)
        std::this_thread::sleep_for(std::chrono::seconds(5));
}

std::string twinService::resolveRoute(const std::string& edge) {
    auto it=routingTable.find(edge);
    if (it != routingTable.end())
        return it->second;
    return defaultRoute;
}

void twinService::handleMessage(const nlohmann::json& j) {
    std::string edge = j.value("edgeNode", "");
    std::string route = resolveRoute(edge);
    nlohmann::json msg;
    msg["edgeNode"]=edge;
    msg["route"]=route;
    msg["id"]=j.value("id",-1);
    client.publish(config::TOPIC_LANE, msg.dump().c_str(), msg.dump().size(), 1, false);
    std::cout<<"[TWIN]" << edge << "->" << route << std::endl;
}
void twinService::loadRoutingConfig(const std::string& file) {
    std::ifstream f(file);
    nlohmann::json j;
    f >> j;
    for (auto& r : j["routes"]) {
        routingTable[r["edge"]] = r["target"];
    }
    if (j.contains("default"))
        defaultRoute=j["default"];
}