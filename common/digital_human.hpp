#pragma once
#include <nlohmann/json.hpp>
class digital_human {
    float weight;
public:
    digital_human(float w) : weight(w) {};
    void updateWeight(float newWeight);
    float getWeight() const;

    nlohmann::json toJson() const;
    void from_json(const nlohmann::json& j);
};