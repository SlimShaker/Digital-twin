#pragma once
#include <mqtt/async_client.h>
#include "twin.hpp"
#include <nlohmann/json.hpp>
#include <iostream>

class twinCallback : public mqtt::callback {
    twinService& twin;
    
public:
    twinCallback(twinService& t) : twin(t) {}
    void message_arrived(mqtt::const_message_ptr msg) override;
};