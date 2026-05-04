#include "twinCallback.hpp"
void twinCallback::message_arrived(mqtt::const_message_ptr msg) {
    try {
        auto j = nlohmann::json::parse(msg->to_string());

        if (j.contains("edgeNode")) {
            twin.handleMessage(j);
        }

    } catch (const std::exception& e) {
        std::cerr << "[TWIN ERROR] " << e.what() << std::endl;
    }
}