#pragma once
#include "../Core/HandGenerator.h"
#include "../Core/HandPlayer.h"
#include "../Core/BlindRule.h"
#include "../Core/RewardRule.h"
#include "../Core/Joker.h"
#include "ScoringRule.h"
#include "ShopManager.h"
#include <vector>
#include <memory>

class GameManager {
private:
    HandGenerator handGenerator;
    HandPlayer handPlayer;
    ScoringRule scoringRule;
    BlindRule blindRule;
    RewardRule rewardRule;
    ShopManager shopManager;

    int playerMoney = 10; // Uang awal
    std::vector<std::unique_ptr<Joker>> ownedJokers;
    const int MAX_JOKERS = 5;

public:
    void runSession();
    void shopPhase();
};