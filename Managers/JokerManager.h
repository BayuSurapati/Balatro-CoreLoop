#pragma once
#include "../Core/Joker.h"
#include "../Models/ChosenHand.h"
#include "../Models/HandRank.h"
#include <vector>
#include <memory>
#include <iostream>

class JokerManager {
private:
    std::vector<std::unique_ptr<Joker>> ownedJokers;
    const int MAX_JOKERS = 5;

public:
    bool addJoker(std::unique_ptr<Joker> joker);
    void removeJoker(int index);
    void applyAllEffects(long long& chips, double& mult, const ChosenHand& hand, HandRank rank);
    void displayJokers() const;
    bool isFull() const;
    int getCount() const;
    
    // Untuk fitur masa depan: reordering
    void swapJokers(int i, int j);
};