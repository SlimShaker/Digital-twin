#include "edgeCallback.hpp"

void edgeCallback::message_arrived(mqtt::const_message_ptr msg) {
    try {
        auto j=nlohmann::json::parse(msg->to_string());
        if (!j.contains("route") || !j.contains("edgeNode"))
            return;
        std::string route=j["route"];
        std::string edge=j["edgeNode"];
        if (edge!=myEdgeType) return;
        if (onRoute)
            onRoute(route);
    }catch (...) {
        std::cerr << "edge route parse error" << std::endl;
    }
}