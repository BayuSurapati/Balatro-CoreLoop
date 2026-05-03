#include "FlushHouseChecker.h"
#include <iostream>
HandRank FlushHouseChecker::check(const Hand& hand) {
    std::cout << "  [Log] Mengecek: Flush House...\n";
    if (hand.dummyValue == 12) {
        std::cout << "  [!] Kombinasi FLUSH HOUSE ditemukan!\n"; return HandRank::FLUSH_HOUSE;
    }
    if (nextChecker) return nextChecker->check(hand); return HandRank::NONE;
}