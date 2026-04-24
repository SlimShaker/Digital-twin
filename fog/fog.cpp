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
    client.connect()->wait();
    cloudClient.connect()->wait();
    client.start_consuming();
    client.subscribe("human/#", 1)->wait();
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
void fogNode::forwardToCloud(const std::string& msg) {
    std::cout << "FOG RECEIVED: " << msg << std::endl;
    cloudClient.publish("cloud/data", msg.c_str(), msg.size(), 1, false);
}
