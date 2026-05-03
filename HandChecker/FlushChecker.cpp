#include "FlushChecker.h"
#include <iostream>
HandRank FlushChecker::check(const Hand& hand) {
    std::cout << "  [Log] Mengecek: Flush...\n";
    if (hand.dummyValue == 6) {
        std::cout << "  [!] Kombinasi FLUSH ditemukan!\n"; return HandRank::FLUSH;
    }
    if (nextChecker) return nextChecker->check(hand); return HandRank::NONE;
}