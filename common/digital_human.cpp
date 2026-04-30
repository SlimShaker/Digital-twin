// Created by Hussein on 2026-04-12.
#include "digital_human.hpp"

void digital_human::updateWeight(float newWeight) {
    weight = newWeight;
}
float digital_human::getWeight() const {
    return weight;
}
nlohmann::json digital_human::toJson() const{
    return{{"weight", weight}};
}
void digital_human::from_json(const nlohmann::json& j) {
    weight=j.value("weight", 0.0f);
}