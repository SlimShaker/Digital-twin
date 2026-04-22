// Created by Hussein on 2026-04-12.
#include "fog.hpp"

fogNode::fogNode(const std::string& nId, const std::string& broker) : nodeId(nId), brokerAddress(broker), client(broker, nId), twin(70.0), cb(twin, nId) {
    cb.setForwarder([this](const std::string& msg) {
        forwardToCloud(msg);
    });
}

void fogNode::start(){
    std::cout<<"Fog node running..."<<std::endl;
    client.set_callback(cb);
    client.connect()->wait();
    //client.start_consuming();
    client.subscribe("sensor/data", 1)->wait();
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
void fogNode::forwardToCloud(const std::string& msg) {
    mqtt::message_ptr pubmsg = mqtt::make_message("cloud/data", msg);
    pubmsg->set_qos(1);
    client.publish(pubmsg);
}
