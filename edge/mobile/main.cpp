//Created by Hussein 2026-04-16
#include "../edge.hpp"
int main() {
    edgeNode edge("tcp://broker:1883", "edgeNode", "sensor/data");
    edge.start();
    return 0;
}