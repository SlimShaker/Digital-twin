#pragma once
#include <string>
#include <mqtt/async_client.h>

class edgeNode {
    private:
    mqtt::async_client client;
    std::string topic;
    public:
    edgeNode(const std::string& address, const std::string& id, const std::string& topic);
    void start();
};