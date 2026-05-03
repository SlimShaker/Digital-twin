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
        long long edgeSent     = trace.value("edge_sent", 0LL);
        long long fogReceived  = trace.value("fog_received", 0LL);
        long long fogForwarded = trace.value("fog_forwarded", 0LL);
        long long cloudReceived = rep.getEpochMs();

        long long e2f  = fogReceived - edgeSent;
        long long proc = fogForwarded - fogReceived;
        long long f2c  = cloudReceived - fogForwarded;
        long long total = cloudReceived - edgeSent;

        int id = j.value("id", -1);
        float weight = j.value("weight", 0.0f);
        std::string edgeNode = j.value("edgeNode", "unknown");
        std::string fogNode  = j.value("fogNode", "unknown");

        std::cout << "[CLOUD] "
                  << edgeNode << " → " << fogNode
                  << " | total=" << total << " ms"
                  << " (e2f=" << e2f
                  << ", proc=" << proc
                  << ", f2c=" << f2c
                  << ")"
                  << std::endl;

        rep.report(id, edgeSent, cloudReceived, e2f, proc, f2c, total, weight, edgeNode);

    } catch (const std::exception& e) {
        std::cerr << "[CLOUD ERROR] " << e.what() << std::endl;
    }
}