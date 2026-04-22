#pragma once
#include <string>
#include <mqtt/async_client.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <nlohmann/json.hpp>
#include "../logger/reporter.hpp"
class edgeNode {
    mqtt::async_client client;
    std::string topic;
    public:
    edgeNode(const std::string& address, const std::string& id, const std::string& topic);
    void start();
};