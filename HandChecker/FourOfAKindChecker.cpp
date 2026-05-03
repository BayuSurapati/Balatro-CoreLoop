#include "FourOfAKindChecker.h"
#include <iostream>
HandRank FourOfAKindChecker::check(const Hand& hand) {
    std::cout << "  [Log] Mengecek: Four of a Kind...\n";
    if (hand.dummyValue == 8) {
        std::cout << "  [!] Kombinasi FOUR OF A KIND ditemukan!\n"; return HandRank::FOUR_OF_A_KIND;
    }
    if (nextChecker) return nextChecker->check(hand); return HandRank::NONE;
}