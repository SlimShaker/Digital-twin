#pragma once
#include <iosfwd>
#include <mqtt/async_client.h>
#include "../common/digital_human.hpp"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include "../logger/reporter.hpp"

class fogCallBack : public mqtt::callback {
    digital_human& twin;
    reporter rep;
public:
    fogCallBack(digital_human& t);
    void message_arrived(mqtt::const_message_ptr msg) override;
};
