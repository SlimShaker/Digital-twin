#pragma once
#include <mqtt/async_client.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include <functional>

class edgeCallback : public mqtt::callback {
    std::function<void(const std::string&)> onRoute;
    std::string myEdgeType;
public:
    edgeCallback(const std::string& myEdgeType) : myEdgeType(myEdgeType) {}
    void setRouteHandler(std::function<void(const std::string&)> handler) {
        onRoute=handler;
    }
    void message_arrived(mqtt::const_message_ptr msg) override;
};