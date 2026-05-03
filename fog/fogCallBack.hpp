#pragma once
#include <mqtt/async_client.h>
#include <nlohmann/json.hpp>
#include <functional>
#include <iostream>
#include <chrono>
#include "../logger/reporter.hpp"

class fogCallBack : public mqtt::callback {
    std::function<void(const std::string&)> forward;
    std::string fogId;
    reporter rep;

public:
    fogCallBack(const std::string& id);
    void setForwarder(std::function<void(const std::string&)> f);
    void message_arrived(mqtt::const_message_ptr msg) override;
};