// Created by Hussein on 2026-04-12.
#include "fog.hpp"

fogNode::fogNode(const std::string& broker, const std::string& id)
    : client(broker, id),
      cloudClient(broker, "fog_cloud"),
      cb(id) {

    cb.setForwarder([this](const std::string& msg) {
        forward(msg);
    });
}

void fogNode::start() {
    while (!client.is_connected()) {
        try {
            client.connect()->wait();
        } catch (...) {
            std::cout << "[FOG] retrying broker connection...\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
    while (!cloudClient.is_connected()) {
        try {
            cloudClient.connect()->wait();
        } catch (...) {
            std::cout << "[FOG] retrying cloud connection...\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }

    client.subscribe("human/#", 1)->wait();
    client.set_callback(cb);
    std::cout << "[FOG] running...\n";
    while (true)
        std::this_thread::sleep_for(std::chrono::seconds(10));
}

void fogNode::forward(const std::string& msg) {
    cloudClient.publish("twin/data",
        msg.c_str(),
        msg.size(),
        1,
        false);
}