#include "ThreeOfAKindChecker.h"
#include <iostream>
HandRank ThreeOfAKindChecker::check(const Hand& hand) {
    std::cout << "  [Log] Mengecek: Three of a Kind...\n";
    if (hand.dummyValue == 4) {
        std::cout << "  [!] Kombinasi THREE OF A KIND ditemukan!\n"; return HandRank::THREE_OF_A_KIND;
    }
    if (nextChecker) return nextChecker->check(hand); return HandRank::NONE;
}