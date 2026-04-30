#include "twin.hpp"
int main() {
    const char* broker_env = std::getenv("BROKER");
    const char* role_env   = std::getenv("NODE_ROLE");

    std::string broker = broker_env ? broker_env : "tcp://cloud_broker:1883";
    std::string role   = role_env ? role_env : "cloud";

    twinService twin(broker, role);
    twin.start();

    return 0;
}