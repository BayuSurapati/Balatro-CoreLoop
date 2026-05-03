#include "ScoringRule.h"
#include <iostream>

ScoringRule::ScoringRule() {
    flushFive.setNext(&flushHouse);
    flushHouse.setNext(&fiveOfAKind);
    fiveOfAKind.setNext(&royalFlush);
    royalFlush.setNext(&straightFlush);
    straightFlush.setNext(&fourOfAKind);
    fourOfAKind.setNext(&fullHouse);
    fullHouse.setNext(&flush);
    flush.setNext(&straight);
    straight.setNext(&threeOfAKind);
    threeOfAKind.setNext(&twoPair);
    twoPair.setNext(&pair);
    pair.setNext(&highCard);
}

int ScoringRule::scoreHand(const Hand& hand) {
    std::cout << "[System] Memulai evaluasi kartu pemain:\n";
    HandRank rank = flushFive.check(hand); 
    return convertRankToScore(rank);
}

int ScoringRule::convertRankToScore(HandRank rank) {
    // Menggunakan switch case membuat pemetaan enum ke integer sangat rapi
    switch (rank) {
        case HandRank::FLUSH_FIVE:      return 1200;
        case HandRank::FLUSH_HOUSE:     return 1300;
        case HandRank::FIVE_OF_A_KIND:  return 1100;
        case HandRank::ROYAL_FLUSH:     return 1000;
        case HandRank::STRAIGHT_FLUSH:  return 900;
        case HandRank::FOUR_OF_A_KIND:  return 800;
        case HandRank::FULL_HOUSE:      return 700;
        case HandRank::FLUSH:           return 600;
        case HandRank::STRAIGHT:        return 500;
        case HandRank::THREE_OF_A_KIND: return 400;
        case HandRank::TWO_PAIR:        return 300;
        case HandRank::PAIR:            return 200;
        case HandRank::HIGH_CARD:       return 100;
        default:                        return 0; // Fallback jika tidak ada yang cocok
    }
}