#pragma once
#include <iostream>
#include <nlohmann/json.hpp>
#include "../logger/reporter.hpp"
#include <mqtt/async_client.h>
#include <thread>
#include "cloudCallBack.hpp"

class cloud {
    mqtt::async_client client;
    reporter rep;

    public:
    cloud();
    void start();
};