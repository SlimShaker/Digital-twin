#include "twinCallback.hpp"
void twinCallback::message_arrived(mqtt::const_message_ptr msg) {
    auto j = nlohmann::json::parse(msg->to_string());
    std::string type = j.value("type", "");
    if (type == "data")
        twin.updateFromData(j);
    else if (type == "migration")
        twin.applyMigration(j);
}