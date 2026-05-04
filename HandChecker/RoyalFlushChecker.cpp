#include "RoyalFlushChecker.h"
#include <iostream>
#include <set>
HandRank RoyalFlushChecker::check(const ChosenHand& hand) {
    std::cout << "  [Log] Mengecek: Royal Flush...\n";
    if (!allSameSuit(hand)) {
        if (nextChecker) return nextChecker->check(hand);
        return HandRank::NONE;
    }
    std::set<int> royalRanks = {10, 11, 12, 13, 14};
    std::set<int> handRanks;
    for (auto& c : hand.cards) handRanks.insert(c.rank);
    if (handRanks == royalRanks) {
        std::cout << "  [!] Kombinasi ROYAL FLUSH ditemukan!\n";
        return HandRank::ROYAL_FLUSH;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::NONE;
}