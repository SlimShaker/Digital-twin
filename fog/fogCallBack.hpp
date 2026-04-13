#pragma once
#include <mqtt/async_client.h>
#include "../common/digital_human.hpp"

class fogCallBack : public mqtt::callback {
private:
    digital_human& twin;

public:
    fogCallBack(digital_human& t);
    void message_arrived(mqtt::const_message_ptr msg) override;
};
