#pragma once

enum class HandRank{
    FLUSH_FIVE, FLUSH_HOUSE, FIVE_OF_A_KIND, ROYAL_FLUSH,
    STRAIGHT_FLUSH, FOUR_OF_A_KIND, FULL_HOUSE, FLUSH,
    STRAIGHT, THREE_OF_A_KIND, TWO_PAIR, PAIR, HIGH_CARD, NONE
};

struct Hand {
    int dummyValue = 0;
};