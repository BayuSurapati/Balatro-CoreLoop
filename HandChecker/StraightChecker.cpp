#include "StraightChecker.h"
#include <iostream>
HandRank StraightChecker::check(const Hand& hand) {
    std::cout << "  [Log] Mengecek: Straight...\n";
    if (hand.dummyValue == 5) {
        std::cout << "  [!] Kombinasi STRAIGHT ditemukan!\n"; return HandRank::STRAIGHT;
    }
    if (nextChecker) return nextChecker->check(hand); return HandRank::NONE;
}