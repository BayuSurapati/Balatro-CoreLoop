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

HandRank ScoringRule::evaluateHand(const ChosenHand& chosen) {
    std::cout << "[System] Memulai evaluasi kartu pemain...\n";
    return flushFive.check(chosen);
}

Score ScoringRule::getBaseStats(HandRank rank) {
    switch (rank) {
        case HandRank::FLUSH_FIVE:      return {160, 16};
        case HandRank::FLUSH_HOUSE:     return {140, 14};
        case HandRank::FIVE_OF_A_KIND:  return {120, 12};
        case HandRank::ROYAL_FLUSH:     return {100, 8};
        case HandRank::STRAIGHT_FLUSH:  return {100, 8};
        case HandRank::FOUR_OF_A_KIND:  return {60, 7};
        case HandRank::FULL_HOUSE:      return {40, 4};
        case HandRank::FLUSH:           return {35, 4};
        case HandRank::STRAIGHT:        return {30, 4};
        case HandRank::THREE_OF_A_KIND: return {30, 3};
        case HandRank::TWO_PAIR:        return {20, 2};
        case HandRank::PAIR:            return {10, 2};
        case HandRank::HIGH_CARD:       return {5, 1};
        default:                        return {0, 0};
    }
}