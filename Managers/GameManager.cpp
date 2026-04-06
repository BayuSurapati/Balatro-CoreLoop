#include "GameManager.h"
#include <iostream>

void GameManager::runSession() {
    std::cout << "=== MEMULAI CORE LOOP ===\n\n";

    Hand hand = handGenerator.generateHand();
    handPlayer.playHand();
    
    int score = scoringRule.scoreHand(hand);
    std::cout << "[System] Skor didapatkan: " << score << "\n";

    bool win = blindRule.checkBlind(score);
    std::cout << "[System] Apakah mencapai target poin? " << (win ? "Ya" : "Tidak") << "\n";

    int reward = rewardRule.earnMoney(win, score);
    std::cout << "[System] Mendapatkan uang (Reward): $" << reward << "\n\n";

    std::cout << "=== CORE LOOP SELESAI ===\n";
}