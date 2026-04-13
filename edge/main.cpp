#include "edge.hpp"
int main() {
    edgeNode edge("tcp://XXXX", "edgeNode", "sensor/ata");
    edge.start();
    return 0;
}