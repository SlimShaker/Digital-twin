//Created by Hussein 2026-04-16
#include "cloud.hpp"
int main() {
    const char* broker_env=std::getenv("BROKER");
    std::string broker = broker_env ? broker_env : "tcp://host.docker.internal:1883";
    cloud node(broker);
    node.start();
    return 0;
}