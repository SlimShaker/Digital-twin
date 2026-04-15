// Created by Hussein on 2026-04-12.
#include "edge.hpp"
int nsample = 0;

edgeNode::edgeNode(const std::string& address, const std::string& id, const std::string& topic) : client(address, id), topic(topic) {}

void edgeNode::start() {
    client.connect()->wait();
    reporter rep;
    while (true) {
        float value = rand() % 100;
        auto now = std::chrono::system_clock::now();
        auto ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
        long timeSentRaw = ms.time_since_epoch().count();
        nlohmann::json j;
        j["id"] = ++nsample;
        j["timeSentRaw"] = timeSentRaw;
        j["timeSent"] = rep.currentTime();;
        j["weight"] = value;

        std::string payload = j.dump();
        client.publish(topic, payload.c_str(), payload.size(), 1, false);
        std::cout << "Sent: " << payload << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
