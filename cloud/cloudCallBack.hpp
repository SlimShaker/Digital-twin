#pragma once
#include <mqtt/async_client.h>
#include "../logger/reporter.hpp"
#include <iostream>
#include <nlohmann/json.hpp>
class cloudCallBack : public mqtt::callback {
    reporter& rep;
public:
    cloudCallBack(reporter& rep) : rep(rep) {}
    void message_arrived(mqtt::const_message_ptr msg) override;
};