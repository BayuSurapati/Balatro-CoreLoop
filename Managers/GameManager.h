#pragma once
#include "../Core/HandGenerator.h"
#include "../Core/HandPlayer.h"
#include "../Core/BlindRule.h"
#include "../Core/RewardRule.h"
#include "../Core/Joker.h"
#include "../Core/BlindState.h"
#include "../Core/SkipCommand.h"
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

    int playerMoney = 10;
    int currentAnte = 1;
    int baseScore = 300;
    std::unique_ptr<BlindState> currentBlind;

    void processBlind();
    void executeSkipReward();

public:
    GameManager();
    void runSession();
    void shopPhase();
};