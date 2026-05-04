#include "StraightChecker.h"
#include <iostream>
HandRank StraightChecker::check(const ChosenHand& hand) {
    std::cout << "  [Log] Mengecek: Straight...\n";
    if (isSequential(hand)) {
        std::cout << "  [!] Kombinasi STRAIGHT ditemukan!\n";
        return HandRank::STRAIGHT;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::NONE;
}