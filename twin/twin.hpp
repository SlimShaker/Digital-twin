#pragma once
#include "../common/digital_human.hpp"
#include <mqtt/async_client.h>
#include <string>
#include <iostream>
#include <thread>
#include "../common/config.hpp"
#include <cstdlib>

class twinService {
    digital_human twin;
    mqtt::async_client client;
    std::string nodeRole;

public:
    twinService(const std::string& broker, const std::string& id);
    void start();
    void updateFromData(const nlohmann::json& j);
    void applyMigration(const nlohmann::json& j);
    void migrate(const std::string& target);
    nlohmann::json exportState();
    std::string getNodeId()const;
};