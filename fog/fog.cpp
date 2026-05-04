// Created by Hussein on 2026-04-12.
#include "fog.hpp"

fogNode::fogNode(const std::string& broker, const std::string& id) : client(broker, id), cloudClient(config::CLOUD_BROKER, "fog_cloud"), cb(id), nodeId(id){
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
    client.set_callback(cb);
    std::string topic = (nodeId == config::FOG1_ID) ? config::TOPIC_HOME : config::TOPIC_WORK;
    client.subscribe(topic, 1)->wait();
    std::cout << "[FOG] running...\n";
    while (true)
        std::this_thread::sleep_for(std::chrono::seconds(10));
}

void fogNode::forward(const std::string& msg) {
    auto j = nlohmann::json::parse(msg);
    j["trace"]["fog_forwarded"] = rep.getEpochMs();
    if (j.contains("weight")) {
        int w = j["weight"];
        j["fog_score"] = w * 2;
    }
    cloudClient.publish(
        config::TOPIC_TWIN,
        j.dump().c_str(),
        j.dump().size(),
        1,
        false
    );
}