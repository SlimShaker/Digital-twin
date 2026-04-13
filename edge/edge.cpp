// Created by Hussein on 2026-04-12.
#include "edge.hpp"
#include <iostream>
#include <chrono>
#include <thread>

edgeNode::edgeNode(const std::string& address, const std::string& id, const std::string& topic): client(address, id), topic(topic) {}

void edgeNode::start() {
    client.connect()->wait();
    while (true) {
        float value = rand() % 100;
        std::string payload = std::to_string(value);
        client.publish(topic, payload.c_str(), payload.size(), 1, false);
        std::cout<<"Sent: " << value << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
