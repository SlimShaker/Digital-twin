#include "fogCallBack.hpp"

fogCallBack::fogCallBack(const std::string& id)
    : fogId(id) {}

void fogCallBack::setForwarder(std::function<void(const std::string&)> f) {
    forward = f;
}

void fogCallBack::message_arrived(mqtt::const_message_ptr msg) {
    try {
        auto j = nlohmann::json::parse(msg->to_string());
        if (!j.contains("trace"))
            j["trace"] = nlohmann::json::object();
        long long now = rep.getEpochMs();
        j["trace"]["fog_received"] = now;
        now = rep.getEpochMs();
        j["trace"]["fog_forwarded"] = now;
        j["fogNode"] = fogId;
        if (forward)
            forward(j.dump());
    } catch (const std::exception& e) {
        std::cerr << "[FOG ERROR] " << e.what() << std::endl;
    }
}