#pragma once
#include "PokerHandChecker.h"
class FlushFiveCheker : public PokerHandChecker{
    public: HandRank check(const Hand& hand) override;
};