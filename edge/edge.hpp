#pragma once
#include <mqtt/async_client.h>
#include <nlohmann/json.hpp>
#include <string>
#include <iostream>
#include <thread>
#include <cstdlib>
#include <mqtt/async_client.h>
#include <nlohmann/json.hpp>
#include <string>
#include <iostream>
#include <thread>
#include <atomic>
#include <random>
#include "../common/config.hpp"
#include "../logger/reporter.hpp"
#include "edgeCallback.hpp"

class edgeNode {
    std::unique_ptr<mqtt::async_client> client;
    std::unique_ptr<mqtt::async_client> laneClient;
    std::string edge_type;
    std::string topic_name;
    int counter;
    reporter rep;
    edgeCallback cb;
    std::atomic<bool> active{false};


public:
    edgeNode(const std::string& broker, const std::string& type, const std::string& topic);
    void start();
    void setActive(bool a);
};