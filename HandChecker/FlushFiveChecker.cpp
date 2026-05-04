#include "FlushFiveChecker.h"
#include <iostream>
HandRank FlushFiveChecker::check(const ChosenHand& hand) {
    std::cout << "  [Log] Mengecek: Flush Five...\n";
    auto freq = rankCount(hand);
    if (allSameSuit(hand) && countFreq(freq, 5) == 1) {
        std::cout << "  [!] Kombinasi FLUSH FIVE ditemukan!\n";
        return HandRank::FLUSH_FIVE;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::NONE;
}