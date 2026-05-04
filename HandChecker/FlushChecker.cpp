#include "FlushChecker.h"
#include <iostream>
HandRank FlushChecker::check(const ChosenHand& hand) {
    std::cout << "  [Log] Mengecek: Flush...\n";
    if (allSameSuit(hand)) {
        std::cout << "  [!] Kombinasi FLUSH ditemukan!\n";
        return HandRank::FLUSH;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::NONE;
}