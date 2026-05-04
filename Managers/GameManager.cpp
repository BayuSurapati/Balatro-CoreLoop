#include "GameManager.h"
#include "../Models/ChosenHand.h"
#include <iostream>

void GameManager::runSession() {
    std::cout << "=== MEMULAI CORE LOOP ===\n";

    Hand hand = handGenerator.generateHand();       // 8 kartu
    ChosenHand chosen = handPlayer.playHand(hand);  // pemain pilih

    int score = scoringRule.scoreHand(chosen);      // cek kombinasi
    std::cout << "[System] Skor: " << score << "\n";

    bool win = blindRule.checkBlind(score);
    std::cout << "[System] Menang? " << (win ? "Ya" : "Tidak") << "\n";

    int reward = rewardRule.earnMoney(win, score);
    std::cout << "[System] Reward: $" << reward << "\n";
    std::cout << "=== CORE LOOP SELESAI ===\n";
}