#include "fogCallBack.hpp"
#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

fogCallBack::fogCallBack(digital_human& t) : twin(t) {}

void fogCallBack::message_arrived(mqtt::const_message_ptr msg) {
    std::string payload = msg->to_string();
    std::cout<<"Received payload: " <<payload<<std::endl;
    try {
        json j = json::parse(payload);
        int id = j["id"];
        std::string time = j["time"];
        float weight = j["weight"];
        twin.updateWeight(weight);
        std::cout<<"Id: "<<id<< " Time: "<<time<<" Weight: "<<weight<<std::endl;
        std::ofstream file("data/received_data.csv", std::ios::app);
        file<<id<<","<<time<<","<<weight<<"\n";
    } catch (const std::exception& e) {
        std::cerr<<"JSON parse error: "<<e.what()<<std::endl;
    }
}