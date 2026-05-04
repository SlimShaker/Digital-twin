// Created by Hussein on 2026-04-12.
#include "edge.hpp"

edgeNode::edgeNode(const std::string& broker, const std::string& type, const std::string& topic) : client(broker, "edge_" + type), edge_type(type),topic_name(topic), counter(0) {}

void edgeNode::start() {
    while (!client.is_connected()) {
        try {
            client.connect()->wait();
        } catch (...) {
            std::cout << "[EDGE] retrying broker...\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
    std::cout << "[EDGE] started: " << edge_type << std::endl;
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dist(0, 100);
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        nlohmann::json j;
        j["edgeNode"] = edge_type;
        j["id"] = counter++;
        j["weight"] = dist(gen);
        j["trace"]["edge_sent"]=rep.getEpochMs();

        client.publish(config::TOPIC_TWIN, j.dump().c_str(), j.dump().size(), 1, false);
        std::cout << "[EDGE] sent from " << edge_type << "\n";
    }
}
