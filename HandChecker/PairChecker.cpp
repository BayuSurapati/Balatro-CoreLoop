#include "PairChecker.h"
#include <iostream>
HandRank PairChecker::check(const ChosenHand& hand) {
    std::cout << "  [Log] Mengecek: Pair...\n";
    auto freq = rankCount(hand);
    if (countFreq(freq, 2) == 1) {
        std::cout << "  [!] Kombinasi PAIR ditemukan!\n";
        return HandRank::PAIR;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::NONE;
}