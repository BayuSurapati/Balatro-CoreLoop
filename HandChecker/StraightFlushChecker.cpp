#include "StraightFlushChecker.h"
#include <iostream>
HandRank StraightFlushChecker::check(const Hand& hand) {
    std::cout << "  [Log] Mengecek: Straight Flush...\n";
    if (hand.dummyValue == 9) {
        std::cout << "  [!] Kombinasi STRAIGHT FLUSH ditemukan!\n"; return HandRank::STRAIGHT_FLUSH;
    }
    if (nextChecker) return nextChecker->check(hand); return HandRank::NONE;
}