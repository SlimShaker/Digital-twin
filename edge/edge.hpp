#pragma once
#include <mqtt/async_client.h>
#include <nlohmann/json.hpp>
#include <string>
#include <iostream>
#include <thread>
#include <cstdlib>
#include <random>
#include "../common/config.hpp"
#include "../logger/reporter.hpp"

class edgeNode {
    mqtt::async_client client;
    std::string edge_type;
    std::string topic_name;
    int counter;
    reporter rep;

public:
    edgeNode(const std::string& broker, const std::string& type, const std::string& topic);
    void start();
};