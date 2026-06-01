#pragma once
#include "Joker.h"
#include <vector>
#include <map>

// 1. Joker sederhana: +4 Mult
class JollyJoker : public Joker {
public:
    JollyJoker() : Joker("Jolly Joker", 3, "+8 Mult jika tangan berisi Pair") {}
    void applyEffect(long long& chips, double& mult, const ChosenHand& hand, HandRank rank) override {
        if (rank == HandRank::PAIR) mult += 8;
    }
};

// 2. Joker Chips: +40 Chips
class SlyJoker : public Joker {
public:
    SlyJoker() : Joker("Sly Joker", 3, "+40 Chips jika tangan berisi Pair") {}
    void applyEffect(long long& chips, double& mult, const ChosenHand& hand, HandRank rank) override {
        if (rank == HandRank::PAIR) chips += 40;
    }
};

// 3. Joker Perkalian: X2 Mult
class TheDuo : public Joker {
public:
    TheDuo() : Joker("The Duo", 5, "X2 Mult jika tangan berisi Two Pair") {}
    void applyEffect(long long& chips, double& mult, const ChosenHand& hand, HandRank rank) override {
        if (rank == HandRank::TWO_PAIR) mult *= 2;
    }
};

// 4. Joker Global: +4 Mult selalu
class GrosMichel : public Joker {
public:
    GrosMichel() : Joker("Gros Michel", 5, "+15 Mult secara permanen") {}
    void applyEffect(long long& chips, double& mult, const ChosenHand& hand, HandRank rank) override {
        mult += 15;
    }
};

// 5. Joker Lusty: +4 Mult per kartu Heart
class LustyBat : public Joker {
public:
    LustyBat() : Joker("Lusty Bat", 4, "+4 Mult untuk setiap kartu Heart dimainkan") {}
    void applyEffect(long long& chips, double& mult, const ChosenHand& hand, HandRank rank) override {
        for(auto& c : hand.cards) {
            if(c.suit == 'H') mult += 4;
        }
    }
};