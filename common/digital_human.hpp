#pragma once
class digital_human {
    float weight;
public:
    digital_human(float w) : weight(w) {};
    void updateWeight(float newWeight);
    float getWeight() const;
};