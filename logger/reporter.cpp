// Created by Hussein on 2026-04-14.
#include "reporter.hpp"

void reporter::report(int id, long long edgeSent, long long cloudReceived, long long edgeToFog, long long fogProcess, long long fogToCloud, long long total, float weight, const std::string& edgeNode){
    std::ofstream file("data/received_data.csv", std::ios::app);
    file << id << "," << edgeSent << "," << cloudReceived<< "," << edgeToFog << "," << fogProcess << "," << fogToCloud << "," << total << "," << weight << "," << edgeNode<<"\n";
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
long reporter::getEpochMs() {
    auto now = std::chrono::system_clock::now();
    auto ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
    return ms.time_since_epoch().count();
}