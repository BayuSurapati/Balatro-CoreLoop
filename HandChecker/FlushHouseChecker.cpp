#include "FlushHouseChecker.h"
#include <iostream>
HandRank FlushHouseChecker::check(const ChosenHand& hand) {
    std::cout << "  [Log] Mengecek: Flush House...\n";
    auto freq = rankCount(hand);
    bool isFullHouse = countFreq(freq, 3) == 1 && countFreq(freq, 2) == 1;
    if (allSameSuit(hand) && isFullHouse) {
        std::cout << "  [!] Kombinasi FLUSH HOUSE ditemukan!\n";
        return HandRank::FLUSH_HOUSE;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::NONE;
}