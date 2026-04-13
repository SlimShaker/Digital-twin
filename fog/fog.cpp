// Created by Hussein on 2026-04-12.
#include "fog.hpp"
#include "fogCallBack.hpp"
#include "../common/digital_human.hpp"
#include <iostream>
#include <thread>
#include <mqtt/async_client.h>

void fogNode::start() {
    std::cout << "fogNode running..." << std::endl;

    mqtt::async_client client("tcp://broker:1883", "fog");

    digital_human twin(70.0f);

    fogCallBack cb(twin);
    client.set_callback(cb);

    client.connect()->wait();
    client.start_consuming();
    client.subscribe("sensor/data", 1)->wait();

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}