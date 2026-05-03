#include "TwoPairChecker.h"
#include <iostream>
HandRank TwoPairChecker::check(const Hand& hand) {
    std::cout << "  [Log] Mengecek: Two Pair...\n";
    if (hand.dummyValue == 3) {
        std::cout << "  [!] Kombinasi TWO PAIR ditemukan!\n"; return HandRank::TWO_PAIR;
    }
    if (nextChecker) return nextChecker->check(hand); return HandRank::NONE;
}