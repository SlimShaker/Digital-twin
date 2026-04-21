//Created by Hussein 2026-04-17
#include "migration_manager.hpp"

std::string migration_manager::decideNode(const std::string& loc) {
    if (loc == "home")
        return "fog1";
    if (loc =="work")
        return "fog2";
    return "cloud";
}