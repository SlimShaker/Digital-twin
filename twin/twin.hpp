//Created by Hussein 2026-05-01
#pragma once
#include <mqtt/async_client.h>
#include <nlohmann/json.hpp>
#include <string>
#include <iostream>
#include <thread>

class twinService {
    mqtt::async_client client;
    std::string nodeRole;
    std::string activeEdge;
    int counter;

public:
    twinService(const std::string& broker, const std::string& role);
    void start();
    void setActiveLane(const std::string& edge);
    void handleMessage(const nlohmann::json& j);
    std::string resolveRoute(const std::string& edge);
};