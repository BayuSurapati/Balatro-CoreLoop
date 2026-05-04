#include "StraightFlushChecker.h"
#include <iostream>
HandRank StraightFlushChecker::check(const ChosenHand& hand) {
    std::cout << "  [Log] Mengecek: Straight Flush...\n";
    if (allSameSuit(hand) && isSequential(hand)) {
        std::cout << "  [!] Kombinasi STRAIGHT FLUSH ditemukan!\n";
        return HandRank::STRAIGHT_FLUSH;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::NONE;
}