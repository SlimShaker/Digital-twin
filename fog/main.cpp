// Created by Hussein on 2026-04-22.
#include "fog.hpp"
int main() {
    const char* node_env = std::getenv("FOG_NODE");
    const char* broker_env = std::getenv("BROKER");
    std::string node = node_env ? node_env : "smart_router";
    std::string broker = broker_env ? broker_env : config::CLOUD_BROKER;
    std::string id = (node == "smart_router") ? config::FOG1_ID : config::FOG2_ID;
    std::cout << "FOG STARTED: " << node << std::endl;
    std::cout << "BROKER: " << broker << std::endl;
    fogNode n(id, broker);
    n.start();
}