//Created by Hussein 2026-04-17
#include "migration_manager.hpp"

std::string migration_manager::decideNode(const std::string& loc) {
    if (loc == "home")
        return "fog_one";
    if (loc =="work")
        return "fog_two";
    return "cloud";
}
void migration_manager::moveTwin(const std::string& targetNode) {
    std::string stopTwinCMD="docker compose stop twin";
    std::string startTwinCMD="docker compose up -d " + targetNode;
    system(stopTwinCMD.c_str());
    system(startTwinCMD.c_str());
}
