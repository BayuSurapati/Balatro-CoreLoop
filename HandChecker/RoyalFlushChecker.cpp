#include "RoyalFlushChecker.h"
#include <iostream>
HandRank RoyalFlushChecker::check(const Hand& hand) {
    std::cout << "  [Log] Mengecek: Royal Flush...\n";
    if (hand.dummyValue == 10) {
        std::cout << "  [!] Kombinasi ROYAL FLUSH ditemukan!\n"; return HandRank::ROYAL_FLUSH;
    }
    if (nextChecker) return nextChecker->check(hand); return HandRank::NONE;
}