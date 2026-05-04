#pragma once
#include <iostream>
#include <nlohmann/json.hpp>
#include "../logger/reporter.hpp"
#include "cloudCallBack.hpp"
#include <mqtt/async_client.h>
#include <thread>
#include "../common/config.hpp"

class cloud {
    mqtt::async_client client;
    reporter rep;

    public:
    cloud(const std::string& broker);
    void start();
};