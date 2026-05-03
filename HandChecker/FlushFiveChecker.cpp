#include "FlushFiveChecker.h"
#include<iostream>

HandRank FlushFiveCheker::check(const Hand& hand){
    std::cout << "[Log] mengecek flush five...\n";
    if(hand.dummyValue == 13){
        std::cout << "[!] Kombinasi FLUSH FIVE ditemukan"; return HandRank::FLUSH_FIVE;
    }
    if(nextChecker) return nextChecker->check(hand); return HandRank::NONE;
}