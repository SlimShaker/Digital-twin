//Created by Hussein 2026-04-17
#pragma once
#include "digital_human.hpp"
#include <string>
#include <iostream>

class migration_manager {
public:
    std::string decideNode(const std::string& location);
    void moveTwin(const std::string& targetNode);
};
