#include "cloudCallBack.hpp"

void cloudCallBack::message_arrived(mqtt::const_message_ptr msg) {
    std::string payload = msg->to_string();
    try {
        auto j=nlohmann::json::parse(payload);
        int id=j["id"];
        long timeSentRaw=j["timeSentRaw"];
        long timeReceivedRaw=rep.getEpochMs();
        std::string timeSent=j["timeSent"];
        std::string timeReceived=rep.getTimestampWithMs();
        float weight=j["weight"];
        std::string edgeNode=j["edgeNode"];
        rep.report(id, timeSentRaw, timeReceivedRaw, timeSent, timeReceived, weight, edgeNode);
    } catch (const std::exception& e) {
        std::cerr << "json parse error: " << e.what() << std::endl;
    }
}