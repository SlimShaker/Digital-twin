#pragma once
#include <mqtt/async_client.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include <functional>

class edgeCallback : public mqtt::callback {
    std::string myEdgeType;
    std::function<void(bool)> onActive;
public:
    void message_arrived(mqtt::const_message_ptr msg) override;

    edgeCallback(const std::string& type) : myEdgeType(type) {}

    void setActiveHandler(std::function<void(bool)> handler) {
        onActive = handler;
    }
};