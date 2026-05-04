// Core/HandGenerator.cpp
#include "HandGenerator.h"
#include <iostream>
#include <algorithm>  // untuk shuffle
#include <random>     // untuk mt19937
#include <ctime>      // untuk time()

Hand HandGenerator::generateHand() {
    std::cout << "[System] Membagikan kartu kepada pemain...\n";

    // 1. Buat deck 52 kartu
    std::vector<Card> deck;
    char suits[] = {'H', 'D', 'C', 'S'};
    for (char suit : suits) {
        for (int rank = 2; rank <= 14; rank++) {
            deck.push_back({rank, suit});
        }
    }

    // 2. Shuffle deck secara random
    std::mt19937 rng(static_cast<unsigned int>(time(0)));
    std::shuffle(deck.begin(), deck.end(), rng);

    // 3. Ambil 5 kartu pertama
    Hand hand;
    for (int i = 0; i < 8; i++) {
        hand.cards.push_back(deck[i]);
    }

    // Tampilkan kartu yang dibagikan
    /*std::cout << "  [System] Kartu yang dibagikan: ";
    for (auto& card : hand.cards) {
        std::cout << card.rank << card.suit << " ";
    }
    std::cout << "\n\n";
*/
    return hand;
}