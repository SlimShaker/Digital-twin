//Created by Hussein 2026-04-17
#include "migration_manager.hpp"
void migration_manager::moveTwin(const std::string& targetNode) {
    std::string constraint;
    if (targetNode == "smart_router")
        constraint = "node.labels.role==smart_router";
    else if (targetNode == "local_server")
        constraint = "node.labels.role==local_server";
    else
        constraint = "node.labels.role==cloud";
    std::string cmd =
        "docker service update "
        "--constraint-rm 'node.labels.role==smart_router' "
        "--constraint-rm 'node.labels.role==local_server' "
        "--constraint-rm 'node.labels.role==cloud' "
        "--constraint-add '" + constraint + "' "
        "project_twin";
    std::cout << "[MIGRATION] Moving twin to: " << targetNode << std::endl;
    system(cmd.c_str());
}