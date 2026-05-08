//Created by Hussein 2026-05-01
#pragma once
#include <mqtt/async_client.h>
#include <nlohmann/json.hpp>
#include <string>
#include <iostream>
#include <thread>
#include <unordered_map>
#include <fstream>
#include "twinCallback.hpp"
#include "../common/config.hpp"


class twinService {
    mqtt::async_client client;
    std::string device;
    twinCallback cb;
    int currentPhase{0};
public:
    twinService(const std::string& broker, const std::string& device);
    void start();
    void switchPhase(int phase);
    void broadcastActive(const std::string& activeEdge);
};