#pragma once
class digital_human {
private:
    float weight;
public:
    digital_human(float w) : weight(w) {};
    void updateWeight(float newWeight);
    float getWeight() const;
};