// Created by Hussein on 2026-04-14.

#ifndef PROJECT_REPORTER_H
#define PROJECT_REPORTER_H
#include <fstream>
#include <string>
class reporter {
    std::ofstream file;
    std::string fileName;
    public:
    reporter(const std::string& fileName);
    void logger(size_t values_amount);
};



#endif //PROJECT_REPORTER_H
