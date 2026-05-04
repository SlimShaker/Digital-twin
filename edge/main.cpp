//Created by Hussein 2026-04-22
#include "edge.hpp"
int main() {
    const char* type_env = std::getenv("EDGE_TYPE");
    const char* topic_env = std::getenv("TOPIC");

    std::string type = type_env ? type_env : "unknown";
    std::string topic = topic_env ? topic_env : "human/#";
    std::string broker;
    if (type == config::MOBILE_EDGE_ID)
        broker = config::CLOUD_BROKER;
    else if (type == config::WORK_EDGE_ID)
        broker = config::FOG2_BROKER;
    else
        broker = config::FOG1_BROKER;
    std::cout << "EDGE STARTED: " << type << " -> " << broker << "\n";
    edgeNode edge(broker, type, topic);
    edge.start();
    return 0;
}