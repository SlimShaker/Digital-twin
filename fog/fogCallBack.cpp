#include "fogCallBack.hpp"

fogCallBack::fogCallBack(const std::string& id)
    : fogId(id) {}

void fogCallBack::setForwarder(std::function<void(const std::string&)> f) {
    forward = f;
}

void fogCallBack::message_arrived(mqtt::const_message_ptr msg) {
    try {
        auto j = nlohmann::json::parse(msg->to_string());
        j["fogNode"] = fogId;
        j["trace"]["fog_received"] = rep.getEpochMs();
        if (forward)
            forward(j.dump());
    } catch (const std::exception& e) {
        std::cerr << "[FOG ERROR] " << e.what() << std::endl;
    }
}