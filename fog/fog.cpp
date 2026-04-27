// Created by Hussein on 2026-04-12.
#include "fog.hpp"

fogNode::fogNode(const std::string& nId, const std::string& broker) : nodeId(nId), brokerAddress(broker), client(broker, nId), cloudClient(config::CLOUD_BROKER, nId + "_cloud"), twin(70.0), cb(twin, nId){
    cb.setForwarder([this](const std::string& msg) {
        forwardToCloud(msg);
    });
}

void fogNode::start(){
    std::cout<<"Fog node running..."<<std::endl;
    client.set_callback(cb);
    while (!client.is_connected()) {
        try {
            client.connect()->wait();
        }catch (std::exception& e) {
            std::cout << "Retry cloud MQTT...\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
    while (!cloudClient.is_connected()) {
        try {
            cloudClient.connect()->wait();
        }catch (std::exception& e) {
            std::cout << "Retry cloud MQTT...\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
    client.start_consuming();
    std::string topic;
    if (nodeId==config::FOG1_ID)
        topic=config::TOPIC_HOME;
    else if (nodeId==config::FOG2_ID)
        topic=config::TOPIC_WORK;
    while (true) {
        try {
            client.subscribe(topic, 1)->wait();
            std::cout<<"Subscribed på topic: " << topic << std::endl;
            break;
        } catch (...) {
            std::cout<<"Retry subscribe...\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
void fogNode::forwardToCloud(const std::string& msg) {
    std::cout << "FOG RECEIVED: " << msg << std::endl;
    cloudClient.publish("cloud/data", msg.c_str(), msg.size(), 1, false);
}
