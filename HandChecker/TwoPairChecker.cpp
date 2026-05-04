#include "TwoPairChecker.h"
#include <iostream>
HandRank TwoPairChecker::check(const ChosenHand& hand) {
    std::cout << "  [Log] Mengecek: Two Pair...\n";
    auto freq = rankCount(hand);
    if (countFreq(freq, 2) == 2) {
        std::cout << "  [!] Kombinasi TWO PAIR ditemukan!\n";
        return HandRank::TWO_PAIR;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::NONE;
}   