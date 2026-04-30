#include "twin.hpp"
#include "twinCallback.hpp"
#include <iostream>

twinService::twinService(const std::string& broker, const std::string& role)
    : client(broker, "twin_" + role), twin(70.0f), nodeRole(role) {}

void twinService::start() {
    twinCallback cb(*this);
    client.set_callback(cb);

    client.connect()->wait();

    client.subscribe("twin/data", 1)->wait();
    client.subscribe("twin/migrate", 1)->wait();

    std::cout << "[TWIN] Running on " << nodeRole << std::endl;
    while (true)
        std::this_thread::sleep_for(std::chrono::seconds(5));
}

void twinService::updateFromData(const nlohmann::json& j) {
    float weight = j.value("weight", 0.0f);
    std::string edgeNode = j.value("edgeNode", "");
    twin.updateWeight(weight);
    std::cout << "[TWIN] weight=" << twin.getWeight() << std::endl;
    if (edgeNode == "home" && nodeRole != "smart_router")
        migrate("smart_router");
    else if (edgeNode == "work" && nodeRole != "local_server")
        migrate("local_server");
}

void twinService::applyMigration(const nlohmann::json& j) {
    std::string target = j.value("target", "");
    if (target != nodeRole) return;
    std::cout << "[TWIN] Applying migrated state...\n";
    twin.from_json(j["state"]);
}

nlohmann::json twinService::exportState() {
    return twin.to_json();
}

void twinService::migrate(const std::string& target) {
    std::cout << "[TWIN] Migrating to " << target << std::endl;
    nlohmann::json msg;
    msg["type"] = "migration";
    msg["state"] = exportState();
    msg["target"] = target;

    client.publish("twin/migrate", msg.dump().c_str(), msg.dump().size(), 1, true);
    std::string cmd =
        "docker service update "
        "--constraint-rm 'node.labels.role==smart_router' "
        "--constraint-rm 'node.labels.role==local_server' "
        "--constraint-add 'node.labels.role==" + target + "' "
        "project_twin";

    system(cmd.c_str());
    std::cout << "[TWIN] Migration triggered\n";
}
std::string twinService::getNodeId() const {
    return nodeId;
}