#include "twin.hpp"
int main() {
    const char* role_env = std::getenv("NODE_ROLE");
    std::string role = role_env ? role_env : "home";
    std::cout << "TWIN STARTED on: " << role << std::endl;
    twinService twin(config::CLOUD_BROKER, role);
    twin.start();
    return 0;
}