#include "cloudCallBack.hpp"

void cloudCallBack::message_arrived(mqtt::const_message_ptr msg) {
    std::string payload = msg->to_string();
    try {
        auto j = nlohmann::json::parse(payload);
        if (!j.contains("trace")) {
            std::cerr << "[CLOUD] Missing trace\n";
            return;
        }
        auto trace = j["trace"];

        long long edgeSent = trace.value("edge_sent", 0LL);
        long long fogReceived = trace.value("fog_received", edgeSent);
        long long fogForwarded = trace.value("fog_forwarded", fogReceived);
        long long cloudReceived = rep.getEpochMs();

        long long e2f = fogReceived - edgeSent;
        long long proc = fogForwarded - fogReceived;
        long long f2c = cloudReceived - fogForwarded;
        long long total = cloudReceived - edgeSent;

        std::string edgeNode = j.value("edgeNode", "unknown");
        std::string fogNode = j.value("fogNode", "none");

        std::cout << "[CLOUD] "<< edgeNode << " -> " << fogNode << " | total=" << total << " ms" << std::endl;
        rep.report(j.value("id", -1), edgeSent, cloudReceived, e2f, proc, f2c, total, j.value("weight", 0.0f), edgeNode);
    } catch (const std::exception& e) {
        std::cerr << "[CLOUD ERROR] " << e.what() << std::endl;
    }
}