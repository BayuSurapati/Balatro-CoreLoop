#pragma once
#include "../Core/HandGenerator.h"
#include "../Core/HandPlayer.h"
#include "../Core/BlindRule.h"
#include "../Core/RewardRule.h"
#include "ScoringRule.h"

class GameManager {
private:
    HandGenerator handGenerator;
    HandPlayer handPlayer;
    ScoringRule scoringRule;
    BlindRule blindRule;
    RewardRule rewardRule;

public:
    void runSession();
};