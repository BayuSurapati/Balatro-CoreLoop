#include "RewardRule.h"
#include <iostream>

int RewardRule::earnMoney(bool win, int score) {
    if (!win) return 0;
    int baseReward = 5;
    int bonus = score / 500; // Bonus kecil dari skor
    return baseReward + bonus;
}