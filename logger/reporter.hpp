// Created by Hussein on 2026-04-14.
#pragma once
#include <string>
#include <chrono>
#include <ctime>
#include <fstream>
#include <sstream>
#include <iomanip>

class reporter {
public:
    void report(int id, long long edgeSent, long long cloudReceived, long long edgeToFog, long long fogProcess, long long fogToCloud, long long total, float weight, const std::string& edgeNode);
    std::string getTimestampWithMs();
    long long getEpochMs();
};