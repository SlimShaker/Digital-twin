#pragma once
#include <iosfwd>
#include <mqtt/async_client.h>
#include "../common/digital_human.hpp"
#include <fstream>
#include <functional>
#include <iostream>
#include <nlohmann/json.hpp>
#include "../logger/reporter.hpp"
class fogCallBack : public mqtt::callback {
    digital_human& twin;
    reporter rep;
    std::string fogId;
    std::function<void(const std::string&)> forward;
public:
    fogCallBack(digital_human& t, const std::string& id);
    void message_arrived(mqtt::const_message_ptr msg) override;
    void setForwarder(std::function<void(const std::string&)> f);
};