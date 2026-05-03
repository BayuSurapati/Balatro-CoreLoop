#include "PairChecker.h"
#include <iostream>
HandRank PairChecker::check(const Hand& hand) {
    std::cout << "  [Log] Mengecek: Pair...\n";
    if (hand.dummyValue == 2) {
        std::cout << "  [!] Kombinasi PAIR ditemukan!\n"; return HandRank::PAIR;
    }
    if (nextChecker) return nextChecker->check(hand); return HandRank::NONE;
}