#include "edgeCallback.hpp"
void edgeCallback::message_arrived(mqtt::const_message_ptr msg) {
    try {
        auto j = nlohmann::json::parse(msg->to_string());
        if (!j.contains("edgeNode") || !j.contains("active"))
            return;
        if (j["edgeNode"] != myEdgeType)
            return;
        if (onActive)
            onActive(j["active"].get<bool>());
    } catch (std::exception& e) {
        std::cerr << "[EDGE ERROR] " << e.what() << std::endl;
    }
}