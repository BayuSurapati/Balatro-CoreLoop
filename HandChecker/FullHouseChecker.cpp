#include "FullHouseChecker.h"
#include <iostream>
HandRank FullHouseChecker::check(const ChosenHand& hand) {
    std::cout << "  [Log] Mengecek: Full House...\n";
    auto freq = rankCount(hand);
    if (countFreq(freq, 3) == 1 && countFreq(freq, 2) == 1) {
        std::cout << "  [!] Kombinasi FULL HOUSE ditemukan!\n";
        return HandRank::FULL_HOUSE;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::NONE;
}