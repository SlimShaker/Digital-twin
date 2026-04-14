#pragma once
#include <iosfwd>
#include <mqtt/async_client.h>
#include "../common/digital_human.hpp"
#include <fstream>

class fogCallBack : public mqtt::callback {
    digital_human& twin;
    //std::ofstream file;
public:
    fogCallBack(digital_human& t);
    void message_arrived(mqtt::const_message_ptr msg) override;
};
