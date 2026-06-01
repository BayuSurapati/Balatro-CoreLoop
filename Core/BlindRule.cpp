#include "BlindRule.h"
#include <iostream>

bool BlindRule::checkBlind(int score) {
    int target = 300; // Target sederhana
    std::cout << "[Blind] Target Skor: " << target << " | Skor Kamu: " << score << "\n";
    return score >= target;
}