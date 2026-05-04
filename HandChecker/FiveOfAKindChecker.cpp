#include "FiveOfAKindChecker.h"
#include <iostream>
HandRank FiveOfAKindChecker::check(const ChosenHand& hand) {
    std::cout << "  [Log] Mengecek: Five of a Kind...\n";
    auto freq = rankCount(hand);
    if (countFreq(freq, 5) == 1) {
        std::cout << "  [!] Kombinasi FIVE OF A KIND ditemukan!\n";
        return HandRank::FIVE_OF_A_KIND;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::NONE;
}