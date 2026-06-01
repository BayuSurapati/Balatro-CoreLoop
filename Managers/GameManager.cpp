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
        if (ownedJokers.empty()) std::cout << "Tidak ada";
        for (auto& j : ownedJokers) std::cout << "[" << j->getName() << "] ";
        std::cout << "\n";

        Hand hand = handGenerator.generateHand();
        ChosenHand chosen = handPlayer.playHand(hand);

        // 1. Evaluasi Hand Rank & Base Stats
        HandRank rank = scoringRule.evaluateHand(chosen);
        Score score = scoringRule.getBaseStats(rank);
        
        // 2. Apply Joker Effects (Urutan Kiri ke Kanan)
        std::cout << "[System] Menerapkan efek Joker:\n";
        long long currentChips = score.chips;
        double currentMult = score.mult;

        for (auto& joker : ownedJokers) {
            joker->applyEffect(currentChips, currentMult, chosen, rank);
            std::cout << "  [!] " << joker->getName() << " aktif! (Chips: " << currentChips << ", Mult: " << currentMult << ")\n";
        }

        long long finalScore = static_cast<long long>(currentChips * currentMult);
        std::cout << "[System] Skor Akhir: " << currentChips << " x " << currentMult << " = " << finalScore << "\n";

        bool win = blindRule.checkBlind((int)finalScore); // Cast sementara ke int
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
        std::cout << "Pilih Joker untuk dibeli (atau 0 untuk selesai): ";
        int choice;
        std::cin >> choice;

        if (choice == 0) {
            shopping = false;
        } else {
            if (ownedJokers.size() >= MAX_JOKERS) {
                std::cout << "[System] Slot Joker penuh! (Maks 5)\n";
                continue;
            }
            auto bought = shopManager.buyJoker(choice, playerMoney);
            if (bought) {
                ownedJokers.push_back(std::move(bought));
            }
        }
    }
}