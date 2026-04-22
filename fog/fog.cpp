// Created by Hussein on 2026-04-12.
#include "fog.hpp"


void fogNode::start() {
    std::cout<<"Fog node running..."<<std::endl;
    mqtt::async_client client("tcp://broker:1883", "fog");
    digital_human twin(70.0);
    fogCallBack cb(twin);
    client.set_callback(cb);
    client.connect()->wait();
    client.start_consuming();
    client.subscribe("sensor/data", 1)->wait();
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}