#pragma once
#include "../Models/ChosenHand.h"
#include "../Models/HandRank.h"
#include "../HandChecker/FlushFiveChecker.h"
#include "../HandChecker/FlushHouseChecker.h"
#include "../HandChecker/FiveOfAKindChecker.h"
#include "../HandChecker/RoyalFlushChecker.h"
#include "../HandChecker/StraightFlushChecker.h"
#include "../HandChecker/FourOfAKindChecker.h"
#include "../HandChecker/FullHouseChecker.h"
#include "../HandChecker/FlushChecker.h"
#include "../HandChecker/StraightChecker.h"
#include "../HandChecker/ThreeOfAKindChecker.h"
#include "../HandChecker/TwoPairChecker.h"
#include "../HandChecker/PairChecker.h"
#include "../HandChecker/HighCardChecker.h"

class ScoringRule {
private:
    FlushFiveChecker flushFive;
    FlushHouseChecker flushHouse;
    FiveOfAKindChecker fiveOfAKind;
    RoyalFlushChecker royalFlush;
    StraightFlushChecker straightFlush;
    FourOfAKindChecker fourOfAKind;
    FullHouseChecker fullHouse;
    FlushChecker flush;
    StraightChecker straight;
    ThreeOfAKindChecker threeOfAKind;
    TwoPairChecker twoPair;
    PairChecker pair;
    HighCardChecker highCard;

public:
    ScoringRule();
    int scoreHand(const ChosenHand& chosen);
    int convertRankToScore(HandRank rank);
};