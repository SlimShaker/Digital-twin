//Created by Hussein 2026-04-22
#include "edge.hpp"
#include "../common/config.hpp"
int main() {
    const char* type_env = std::getenv("EDGE_TYPE");
    const char* topic_env = std::getenv("TOPIC");
    const char* broker_env = std::getenv("BROKER");
    std::string type = type_env ? type_env : "mobile";
    std::string topic = topic_env ? topic_env : "human/mobile";
    std::string broker = broker_env ? broker_env : config::CLOUD_BROKER;
    std::cout << "EDGE STARTED: " << type << " -> " << broker << std::endl;
    edgeNode edge(broker, "edge_" + type, topic, type);
    edge.start();

    return 0;
}