//Created by Hussein 2026-04-22
#include "edge.hpp"
#include "../common/config.hpp"
int main() {
    edgeNode edge(config::CLOUD_BROKER, config::MOBILE_EDGE_ID, config::TOPIC_MOBILE, config::MOBILE_NODE);
    edge.start();
    return 0;
}