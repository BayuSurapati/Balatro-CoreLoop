#include "GameManager.h"
#include "../Models/ChosenHand.h"
#include <iostream>

void GameManager::runSession() {
    std::cout << "=== MEMULAI SESI BALATRO (MOD) ===\n";

    bool keepPlaying = true;
    while (keepPlaying) {
        std::cout << "\n--- RONDE BARU ---\n";
        std::cout << "[System] Uang saat ini: $" << playerMoney << "\n";
        std::cout << "[System] Joker yang dimiliki: ";
        jokerManager.displayJokers();

        Hand hand = handGenerator.generateHand();
        ChosenHand chosen = handPlayer.playHand(hand);

        // 1. Evaluasi Hand Rank & Base Stats
        HandRank rank = scoringRule.evaluateHand(chosen);
        Score score = scoringRule.getBaseStats(rank);
        
        // 2. Apply Joker Effects via JokerManager
        long long currentChips = score.chips;
        double currentMult = score.mult;
        jokerManager.applyAllEffects(currentChips, currentMult, chosen, rank);

        long long finalScore = static_cast<long long>(currentChips * currentMult);
        std::cout << "[System] Skor Akhir: " << currentChips << " x " << currentMult << " = " << finalScore << "\n";

        bool win = blindRule.checkBlind((int)finalScore); 
        std::cout << "[System] Menang Ronde? " << (win ? "Ya" : "Tidak") << "\n";

        int reward = rewardRule.earnMoney(win, (int)finalScore);
        playerMoney += reward;
        std::cout << "[System] Total Uang: $" << playerMoney << "\n";

        // 3. Shop Phase
        shopPhase();

        std::cout << "\n[System] Lanjut ke ronde berikutnya? (1: Ya, 0: Keluar): ";
        int choice;
        std::cin >> choice;
        if (choice == 0) keepPlaying = false;
    }

    std::cout << "=== SESI BERAKHIR ===\n";
}

void GameManager::shopPhase() {
    shopManager.refreshShop();
    bool shopping = true;
    while (shopping) {
        shopManager.showShop(playerMoney);
        std::cout << "Pilih Joker untuk dibeli (0 untuk selesai, 9 untuk reorder): ";
        int choice;
        std::cin >> choice;

        if (choice == 0) {
            shopping = false;
        } else if (choice == 9) {
            std::cout << "Masukkan dua nomor Joker untuk ditukar posisinya (misal: 1 2): ";
            int a, b;
            std::cin >> a >> b;
            jokerManager.swapJokers(a - 1, b - 1);
        } else {
            if (jokerManager.isFull()) {
                std::cout << "[System] Slot Joker penuh! Jual salah satu atau lewati.\n";
                continue;
            }
            auto bought = shopManager.buyJoker(choice, playerMoney);
            if (bought) {
                jokerManager.addJoker(std::move(bought));
            }
        }
    }
}