#include "GameManager.h"
#include "../Models/ChosenHand.h"
#include <iostream>
#include <random>

GameManager::GameManager() {
    currentBlind = std::make_unique<SmallBlindState>();
}

void GameManager::runSession() {
    std::cout << "=== MEMULAI BALATRO CORE LOOP (Ante " << currentAnte << ") ===\n";

    bool keepPlaying = true;
    while (keepPlaying) {
        processBlind();

        if (playerMoney < 0) { 
            std::cout << "Game Over! Anda kehabisan uang.\n";
            keepPlaying = false;
            break;
        }

        std::cout << "\n[System] Lanjut ke fase berikutnya? (1: Ya, 0: Keluar): ";
        int choice;
        std::cin >> choice;
        if (choice == 0) keepPlaying = false;
    }

    std::cout << "=== SESI BERAKHIR ===\n";
}

void GameManager::processBlind() {
    int target = currentBlind->getTargetScore(baseScore);
    std::cout << "\n------------------------------------------\n";
    std::cout << "ANTE " << currentAnte << " | " << currentBlind->getName() << "\n";
    std::cout << "Target Skor: " << target << "\n";
    std::cout << "Uang Anda: $" << playerMoney << "\n";
    std::cout << "Joker: "; jokerManager.displayJokers();
    std::cout << "------------------------------------------\n";

    std::cout << "1. Play Blind\n";
    if (currentBlind->canSkip()) {
        std::cout << "2. Skip Blind (Dapatkan Reward Random)\n";
    } else {
        std::cout << "[Boss Blind tidak bisa di-skip]\n";
    }
    
    std::cout << "Pilihan Anda: ";
    int choice;
    std::cin >> choice;

    if (choice == 2 && currentBlind->canSkip()) {
        executeSkipReward();
        currentBlind = currentBlind->nextState();
        return; 
    }

    bool roundWon = false;
    int handsLeft = 4; 
    long long totalRoundScore = 0;
    
    while (handsLeft > 0 && !roundWon) {
        std::cout << "\n[Round] Sisa Hand: " << handsLeft << " | Total Skor: " << totalRoundScore << "\n";
        Hand hand = handGenerator.generateHand();
        ChosenHand chosen = handPlayer.playHand(hand);

        HandRank rank = scoringRule.evaluateHand(chosen);
        Score score = scoringRule.getBaseStats(rank);
        
        long long currentChips = score.chips;
        double currentMult = score.mult;
        jokerManager.applyAllEffects(currentChips, currentMult, chosen, rank);

        long long finalScore = static_cast<long long>(currentChips * currentMult);
        totalRoundScore += finalScore;
        std::cout << "[System] Skor Hand: " << finalScore << " (Total: " << totalRoundScore << ")\n";

        if (totalRoundScore >= target) {
            roundWon = true;
            std::cout << "[System] Blind Berhasil Dikalahkan!\n";
        }
        handsLeft--;
    }

    if (roundWon) {
        int reward = rewardRule.earnMoney(true, target);
        playerMoney += reward;
        std::cout << "[System] Reward Menang: $" << reward << "\n";
        
        shopPhase(); 

        bool isBoss = (currentBlind->getName() == "Boss Blind");
        currentBlind = currentBlind->nextState();

        if (isBoss) {
            currentAnte++;
            baseScore *= 2; 
            std::cout << "\n*** ANTE " << currentAnte << " DIMULAI! Target dasar naik menjadi " << baseScore << " ***\n";
        }
    } else {
        std::cout << "[System] Gagal mengalahkan Blind! Permainan Berakhir.\n";
        playerMoney = -1; 
    }
}

void GameManager::executeSkipReward() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 2);
    
    std::unique_ptr<SkipCommand> command;
    int rewardType = dis(gen);

    if (rewardType == 1) {
        command = std::make_unique<MoneyRewardCommand>();
    } else {
        command = std::make_unique<JokerRewardCommand>();
    }

    command->execute(playerMoney, jokerManager);
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
