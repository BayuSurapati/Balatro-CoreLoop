#pragma once
#include <iostream>
#include "../Managers/JokerManager.h"
#include "../Core/ConcreteJokers.h"
#include <memory>
#include <vector>
#include <random>

// Command Interface
class SkipCommand {
public:
    virtual ~SkipCommand() = default;
    virtual void execute(int& playerMoney, JokerManager& jokerManager) = 0;
};

// Concrete Command: Reward $25
class MoneyRewardCommand : public SkipCommand {
public:
    void execute(int& playerMoney, JokerManager& jokerManager) override {
        playerMoney += 25;
        std::cout << "[Skip Reward] Kamu mendapatkan $25!\n";
    }
};

// Concrete Command: Free Random Joker
class JokerRewardCommand : public SkipCommand {
public:
    void execute(int& playerMoney, JokerManager& jokerManager) override {
        if (jokerManager.isFull()) {
            std::cout << "[Skip Reward] Slot Joker penuh! Sebagai gantinya kamu dapat $10.\n";
            playerMoney += 10;
            return;
        }

        // List joker yang tersedia untuk reward
        std::vector<std::unique_ptr<Joker>> pool;
        pool.push_back(std::make_unique<JollyJoker>());
        pool.push_back(std::make_unique<SlyJoker>());
        pool.push_back(std::make_unique<TheDuo>());
        pool.push_back(std::make_unique<GrosMichel>());
        pool.push_back(std::make_unique<LustyBat>());

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, pool.size() - 1);
        
        auto selectedJoker = std::move(pool[dis(gen)]);
        std::cout << "[Skip Reward] Kamu mendapatkan Joker Gratis: " << selectedJoker->getName() << "!\n";
        jokerManager.addJoker(std::move(selectedJoker));
    }
};
