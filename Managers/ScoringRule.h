#pragma once
#include "../Models/Hand.h"
#include "../HandChecker/ConcreteChecker.h"

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
    int scoreHand(const Hand& hand);
    int convertRankToScore(HandRank rank);
};