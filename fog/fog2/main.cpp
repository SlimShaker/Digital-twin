//Created by Hussein 2026-04-16
#include "../fog.hpp"
#include "../../common/config.hpp"

int main() {
    fogNode node(config::FOG2_ID, config::FOG2_BROKER);
    node.start();
    return 0;
}