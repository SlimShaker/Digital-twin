#pragma once
#include <mqtt/async_client.h>
#include <nlohmann/json.hpp>
#include <string>
#include <iostream>
#include <thread>
#include <cstdlib>
#include <random>
#include "../common/config.hpp"

class edgeNode {
    mqtt::async_client client;
    std::string edge_type;
    int counter;

public:
    edgeNode(const std::string& broker, const std::string& type, const std::string& topic);
    void start();
};