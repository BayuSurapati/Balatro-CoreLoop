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
    if (rank == HandRank::HIGH_CARD) return 100; 
    return 0;
}