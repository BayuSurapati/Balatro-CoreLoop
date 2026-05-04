#include "FourOfAKindChecker.h"
#include <iostream>
HandRank FourOfAKindChecker::check(const ChosenHand& hand) {
    std::cout << "  [Log] Mengecek: Four of a Kind...\n";
    auto freq = rankCount(hand);
    if (countFreq(freq, 4) == 1) {
        std::cout << "  [!] Kombinasi FOUR OF A KIND ditemukan!\n";
        return HandRank::FOUR_OF_A_KIND;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::NONE;
}