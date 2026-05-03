// Created by Hussein on 2026-04-14.
#include "reporter.hpp"

void reporter::report(int id, long long edgeSent, long long cloudReceived, long long e2f, long long proc, long long f2c, long long total, float weight, const std::string& edgeNode){
    std::ofstream file("data/latency.csv", std::ios::app);
    file << id << "," << edgeSent << "," << cloudReceived << "," << e2f << ","<< proc << "," << f2c << "," << total << "," << weight << "," << edgeNode << "\n";
    file.flush();
}

std::string reporter::getTimestampWithMs() {
    const auto now = std::chrono::system_clock::now();
    const auto nowAsTimeT = std::chrono::system_clock::to_time_t(now);
    const auto nowMs = std::chrono::duration_cast<std::chrono::milliseconds>(
        now.time_since_epoch()) % 1000;
    std::stringstream nowSs;
    nowSs
    << std::put_time(std::localtime(&nowAsTimeT), "%Y-%m-%d %H:%M:%S")
    << '.' << std::setfill('0') << std::setw(3) << nowMs.count();
    return nowSs.str();
}
//fix round trip timer
long long reporter::getEpochMs() {
    auto now = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(
        now.time_since_epoch()).count();
}