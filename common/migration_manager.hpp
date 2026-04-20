//Created by Hussein 2026-04-17
#pragma once
#include <string>

class migration_manager {
public:
    std::string deciceNode(const std::string& location);
    void moveTwin(const std::string& currentNode, const std::string& nextNode);

};
