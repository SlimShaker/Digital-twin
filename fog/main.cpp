// Created by Hussein on 2026-04-12.
#include "fog.hpp"
int main() {
    const char* node_env = std::getenv("FOG_NODE");
    std::string node = node_env ? node_env : "smart_router";
    std::string id = (node == "smart_router") ? config::FOG1_ID : config::FOG2_ID;
    std::string broker = (node == "smart_router") ? config::FOG1_BROKER : config::FOG2_BROKER;
    std::cout << "FOG STARTED: " << node << std::endl;
    std::cout << "BROKER: " << broker << std::endl;
    fogNode n(broker, id);
    n.start();
}