#pragma once
#include "../Models/ChosenHand.h"
#include "../Models/HandRank.h"
#include <string>

class Score; // Forward declaration

class Joker {
protected:
    std::string name;
    int price;
    std::string description;

public:
    Joker(std::string name, int price, std::string description) 
        : name(name), price(price), description(description) {}
    virtual ~Joker() = default;

    std::string getName() const { return name; }
    int getPrice() const { return price; }
    std::string getDescription() const { return description; }

    // Efek Joker: Memodifikasi chips dan mult secara langsung
    virtual void applyEffect(long long& chips, double& mult, const ChosenHand& hand, HandRank rank) = 0;
};