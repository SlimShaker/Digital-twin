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
    void report(int id, long timeSentRaw, long timeReceivedRaw, const std::string& timeSent, const std::string& timeReceived, float weight);
    std::string getTimestampWithMs();
    long getEpochMs();
};