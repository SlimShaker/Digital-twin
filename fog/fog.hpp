#include "fogCallBack.hpp"
#include "../common/digital_human.hpp"
#include <iostream>
#include <thread>
#include <mqtt/async_client.h>
#include "../common/config.hpp"
#pragma once
class fogNode {
    std::string nodeId;
    std::string brokerAddress;
    digital_human twin;
    fogCallBack cb;
    mqtt::async_client client;
    mqtt::async_client cloudClient;
public:
    fogNode(const std::string& nId, const std::string& broker);
    void start();
    void forwardToCloud(const std::string& msg);
};