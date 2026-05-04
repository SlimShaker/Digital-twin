#pragma once
#include <mqtt/async_client.h>
#include <nlohmann/json.hpp>
#include "fogCallBack.hpp"
#include <iostream>
#include <thread>
#include "../common/config.hpp"
#include "../logger/reporter.hpp"

class fogNode {
    std::string nodeId;
    mqtt::async_client client;
    mqtt::async_client cloudClient;
    fogCallBack cb;
    reporter rep;

public:
    fogNode(const std::string& broker, const std::string& id);
    void start();
    void forward(const std::string& msg);
};