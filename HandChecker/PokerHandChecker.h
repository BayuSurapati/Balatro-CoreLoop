#pragma once
#include "../Models/Hand.h"

class PokerHandChecker
{
protected:
    PokerHandChecker* nextChecker = nullptr;
public:
    virtual ~PokerHandChecker() = default;

    void setNext(PokerHandChecker* next){
        nextChecker = next;
    }

    virtual HandRank check(const Hand& hand) = 0;
};

