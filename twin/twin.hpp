//Created by Hussein 2026-05-01
#pragma once
#include <mqtt/async_client.h>
#include <nlohmann/json.hpp>
#include <string>
#include <iostream>
#include <thread>
#include "twinCallback.hpp"
#include "../common/config.hpp"
#include <unordered_map>
#include <fstream>


class twinService {
    mqtt::async_client client;
    std::string nodeRole;
    twinCallback cb;
    std::unordered_map<std::string, std::string> routingTable;
    std::string defaultRoute="cloud";

public:
    twinService(const std::string& broker, const std::string& role);
    void start();
    void handleMessage(const nlohmann::json& j);
    std::string resolveRoute(const std::string& edge);
    void loadRoutingConfig(const std::string& file);
};