//Created by Hussein 2026-04-22
#include "edge.hpp"
#include "../common/config.hpp"
int main() {
    std::string type = std::getenv("EDGE_TYPE");
    std::string topic = std::getenv("TOPIC");
    edgeNode edge(config::CLOUD_BROKER, "edge_" + type,topic,type);
    edge.start();
    return 0;
}