#include "HighCardChecker.h"
#include <iostream>
HandRank HighCardChecker::check(const ChosenHand& hand) {
    std::cout << "  [Log] Mengecek: High Card...\n";
    std::cout << "  [!] Kombinasi HIGH CARD ditetapkan!\n";
    return HandRank::HIGH_CARD;
}