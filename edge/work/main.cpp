//Created by Hussein 2026-04-16
#include "../edge.hpp"
#include "../../common/config.hpp"
int main() {
    edgeNode edge(config::FOG2_BROKER, config::WORK_EDGE_ID, config::TOPIC_WORK, config::WORK_NODE);
    edge.start();
    return 0;
}