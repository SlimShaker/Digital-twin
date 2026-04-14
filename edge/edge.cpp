// Created by Hussein on 2026-04-12.
#include "edge.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
int nsample = 0;

edgeNode::edgeNode(const std::string& address, const std::string& id, const std::string& topic) : client(address, id), topic(topic) {}

void edgeNode::start() {
    client.connect()->wait();

    while (true) {
        float value = rand() % 100;

        json j;
        j["id"] = ++nsample;
        j["time"] = "2026-04-14T12:00:00";
        j["weight"] = value;

        std::string payload = j.dump();
        client.publish(topic, payload.c_str(), payload.size(), 1, false);
        std::cout << "Sent: " << payload << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
