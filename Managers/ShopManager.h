#pragma once
#include "../Core/Joker.h"
#include "../Core/ConcreteJokers.h"
#include <vector>
#include <memory>
#include <iostream>
#include <random>
#include <ctime>

class ShopManager {
private:
    std::vector<std::unique_ptr<Joker>> availableJokers;

public:
    ShopManager() {
        // Inisialisasi pool joker yang bisa muncul di toko
    }

    void refreshShop() {
        availableJokers.clear();
        
        // Contoh: Ambil 3 joker acak (untuk demo kita masukkan manual dulu)
        availableJokers.push_back(std::make_unique<JollyJoker>());
        availableJokers.push_back(std::make_unique<SlyJoker>());
        availableJokers.push_back(std::make_unique<TheDuo>());
        availableJokers.push_back(std::make_unique<GrosMichel>());
        availableJokers.push_back(std::make_unique<LustyBat>());
    }

    void showShop(int playerMoney) {
        std::cout << "\n=== TOKO JOKER (Uang: $" << playerMoney << ") ===\n";
        for (int i = 0; i < (int)availableJokers.size(); i++) {
            std::cout << "  [" << i + 1 << "] " << availableJokers[i]->getName() 
                      << " ($" << availableJokers[i]->getPrice() << ") - " 
                      << availableJokers[i]->getDescription() << "\n";
        }
        std::cout << "  [0] Lewati Toko\n";
    }

    std::unique_ptr<Joker> buyJoker(int index, int& playerMoney) {
        if (index < 1 || index > (int)availableJokers.size()) return nullptr;
        
        int cost = availableJokers[index - 1]->getPrice();
        if (playerMoney >= cost) {
            playerMoney -= cost;
            std::cout << "[Shop] Berhasil membeli " << availableJokers[index - 1]->getName() << "!\n";
            auto joker = std::move(availableJokers[index - 1]);
            availableJokers.erase(availableJokers.begin() + (index - 1));
            return joker;
        } else {
            std::cout << "[Shop] Uang tidak cukup!\n";
            return nullptr;
        }
    }
};