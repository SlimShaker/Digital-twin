#pragma once
#include <mqtt/async_client.h>
#include <nlohmann/json.hpp>
#include <iostream>

class twinService;

class twinCallback : public mqtt::callback {
    twinService& twin;
    
public:
    twinCallback(twinService& t) : twin(t) {}
    void message_arrived(mqtt::const_message_ptr msg) override;
};