#include "fogCallBack.hpp"


fogCallBack::fogCallBack(digital_human& t) : twin(t) {}

void fogCallBack::message_arrived(mqtt::const_message_ptr msg) {
    std::string payload = msg->to_string();
    std::cout<<"Received payload: " <<payload<<std::endl;
    try {
        nlohmann::json j = nlohmann::json::parse(payload);
        int id = j["id"];
        long timeSentRaw = j["timeSentRaw"];
        std::string timeSent = j["timeSent"];
        auto now = std::chrono::system_clock::now();
        auto ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
        long timeReceivedRaw = ms.time_since_epoch().count();
        std::string timeReceived = rep.currentTime();
        float weight = j["weight"];
        twin.updateWeight(weight);
        long delay = timeReceivedRaw - timeSentRaw;
        std::cout << "Delay: " << delay << " sec" << std::endl;
        rep.report(id,timeSentRaw,timeReceivedRaw, timeSent,timeReceived,weight);
    } catch (const std::exception& e) {
        std::cerr<<"JSON parse error: "<<e.what()<<std::endl;
    }
}