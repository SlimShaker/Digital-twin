#include "cloudCallBack.hpp"

void cloudCallBack::message_arrived(mqtt::const_message_ptr msg) {
    std::string payload = msg->to_string();
    try {
        auto j = nlohmann::json::parse(payload);
        if (!j.contains("trace")) {
            std::cerr << "Missing trace field\n";
            return;
        }
        auto trace = j["trace"];
        long long edgeSent = trace.value("edge_sent",0LL);
        long long fogReceived = trace.value("fog_received",0LL);
        long long fogForwarded = trace.value("fog_forwarded",0LL);
        long long cloudReceived = rep.getEpochMs();
        long long edgeToFog = j["trace"].value("fog_forwarded", j["timeSentRaw"]);
        long long fogProcess = fogForwarded - fogReceived;
        long long fogToCloud = cloudReceived - fogForwarded;
        long long total = cloudReceived - edgeSent;
        int id = j["id"];
        float weight = j["weight"];
        std::string edgeNode = j.value("edgeNode", "unknown");
        std::string fogNode = j.value("fogNode", "direct");
        std::cout << "[CLOUD] "
              << "edge=" << edgeNode
              << " -> fog=" << fogNode
              << " | total=" << total << " ms"
              << " (e2f=" << edgeToFog
              << ", proc=" << fogProcess
              << ", f2c=" << fogToCloud
              << ")"
              << std::endl;
        rep.report(id,edgeSent,cloudReceived,edgeToFog,fogProcess,fogToCloud,total,weight,edgeNode);
    } catch (const std::exception& e) {
        std::cerr << "json parse error: " << e.what() << std::endl;
    }
}