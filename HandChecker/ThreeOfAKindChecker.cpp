#include "ThreeOfAKindChecker.h"
#include <iostream>
HandRank ThreeOfAKindChecker::check(const ChosenHand& hand) {
    std::cout << "  [Log] Mengecek: Three of a Kind...\n";
    auto freq = rankCount(hand);
    if (countFreq(freq, 3) == 1 && countFreq(freq, 2) == 0) {
        std::cout << "  [!] Kombinasi THREE OF A KIND ditemukan!\n";
        return HandRank::THREE_OF_A_KIND;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::NONE;
}