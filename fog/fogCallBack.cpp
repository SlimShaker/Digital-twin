#include "fogCallBack.hpp"
#include <iostream>

fogCallBack::fogCallBack(digital_human& t) : twin(t) {}

void fogCallBack::message_arrived(mqtt::const_message_ptr msg) {
    std::string payload = msg->to_string();
    std::cout << "Received payload: " << payload << std::endl;
    float value = std::stof(payload);
    twin.updateWeight(value);

    std::cout << "Twin weight updated to: " << twin.getWeight() << std::endl;
}