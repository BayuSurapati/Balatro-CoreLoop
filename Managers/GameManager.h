#pragma once
#include "../Core/HandGenerator.h"
#include "../Core/HandPlayer.h"
#include "../Core/BlindRule.h"
#include "../Core/RewardRule.h"
#include "../Core/Joker.h"
#include "ScoringRule.h"
#include "ShopManager.h"
#include "JokerManager.h"
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
    JokerManager jokerManager;

    int playerMoney = 10; // Uang awal

public:
    void runSession();
    void shopPhase();
};