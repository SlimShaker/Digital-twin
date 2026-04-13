// Created by Hussein on 2026-04-12.
#include "fog.hpp"
#include "../common/digital_human.hpp"
#include <iostream>

void fogNode::start() {
    std::cout << "fogNode running..." << std::endl;
    digital_human twin(70.0f);
    while (true) {
        twin.updateWeight(78.63);
        std::cout <<"Twin Weight: " << twin.getWeight() << std::endl;
    }
}