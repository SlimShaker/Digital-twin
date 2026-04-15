// Created by Hussein on 2026-04-14.
#include "reporter.hpp"

void reporter::report(int id, long timeSentRaw, long timeReceivedRaw, const std::string& timeSent, const std::string& timeReceived, float weight) {
    std::ofstream file("data/received_data.json", std::ios::app);
    long delay = timeReceivedRaw - timeSentRaw;
    file << id << "," << timeSentRaw << "," << timeReceivedRaw<< "," << delay << "," << "," << timeSent << "," << timeReceived << "," << weight << "\n";
}

std::string reporter::currentTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm* tm = std::localtime(&t);
    std::stringstream ss;
    ss << std::put_time(tm, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}