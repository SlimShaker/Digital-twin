#include "twinCallback.hpp"
void twinCallback::message_arrived(...) {
    auto j = nlohmann::json::parse(msg->to_string());
    if (j.contains("edgeNode")) {
        twin.handleMessage(j);
    }
    else if (j.contains("activeEdge")) {
        twin.setActiveLane(j["activeEdge"]);
    }
}