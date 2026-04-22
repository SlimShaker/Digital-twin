//Created by Hussein 2026-04-17
#pragma once
#include "digital_human.hpp"
#include <string>
#include <iostream>

class migration_manager {
    digital_human& twin;
    std::string location{};

public:
    migration_manager(digital_human& t, const std::string& loc) : twin(t), location(loc) {}
    std::string decideNode(const std::string& location);
};
