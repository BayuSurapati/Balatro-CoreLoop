#include "FullHouseChecker.h"
#include <iostream>
HandRank FullHouseChecker::check(const Hand& hand) {
    std::cout << "  [Log] Mengecek: Full House...\n";
    if (hand.dummyValue == 7) {
        std::cout << "  [!] Kombinasi FULL HOUSE ditemukan!\n"; return HandRank::FULL_HOUSE;
    }
    if (nextChecker) return nextChecker->check(hand); return HandRank::NONE;
}