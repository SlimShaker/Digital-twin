//Created by Hussein 2026-04-16
#include "../edge.hpp"
#include "../../common/config.hpp"
int main() {
    edgeNode edge(config::FOG1_BROKER, config::HOME_EDGE_ID, config::TOPIC_HOME, config::HOME_NODE);
    edge.start();
    return 0;
}