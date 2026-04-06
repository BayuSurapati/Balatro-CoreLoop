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
    else if (rank == HandRank::PAIR) return 200;
    else if (rank == HandRank::TWO_PAIR) return 300;
    else if (rank == HandRank::THREE_OF_A_KIND) return 400;
    else if (rank == HandRank::STRAIGHT) return 500;
    else if (rank == HandRank::FLUSH) return 600;
    else if (rank == HandRank::FULL_HOUSE) return 700;
    else if (rank == HandRank::FOUR_OF_A_KIND) return 800;
    else if (rank == HandRank::STRAIGHT_FLUSH) return 900;
    else if (rank == HandRank::ROYAL_FLUSH) return 1000;    
    else if (rank == HandRank::FIVE_OF_A_KIND) return 1100;
    else if (rank == HandRank::FLUSH_FIVE) return 1200;
    else if (rank == HandRank::FLUSH_HOUSE) return 1300; 
    return 0;
}