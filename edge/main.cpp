//Created by Hussein 2026-04-22
#include "edge.hpp"
int main() {
    const char* type_env = std::getenv("EDGE_TYPE");
    std::string type=type_env ? type_env : "unknown";
    std::string broker;
    if (type==config::HOME_EDGE_TYPE)
        broker=config::FOG1_BROKER;
    else if (type==config::WORK_EDGE_TYPE)
        broker=config::FOG2_BROKER;
    else
        broker = config::CLOUD_BROKER;
    std::cout << "EDGE STARTED: " << type << " -> " << broker << "\n";
    edgeNode edge(broker, type, "");
    edge.start();
    return 0;
}