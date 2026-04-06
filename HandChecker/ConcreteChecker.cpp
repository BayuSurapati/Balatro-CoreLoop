#include "ConcreteChecker.h"
#include <iostream>

HandRank FlushFiveChecker::check(const Hand& hand) {
    std::cout << "  [Log] Mengecek: Flush Five...\n";
    if (hand.dummyValue == 13) {
        std::cout << "  [!] Kombinasi FLUSH FIVE ditemukan!\n";
        return HandRank::FLUSH_FIVE;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::NONE;
}

HandRank FlushHouseChecker::check(const Hand& hand) {
    std::cout << "  [Log] Mengecek: Flush House...\n";
    if (hand.dummyValue == 12) {
        std::cout << "  [!] Kombinasi FLUSH HOUSE ditemukan!\n";
        return HandRank::FLUSH_HOUSE;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::NONE;
}

HandRank FiveOfAKindChecker::check(const Hand& hand) {
    std::cout << "  [Log] Mengecek: Five of a Kind...\n";
    if (hand.dummyValue == 11) {
        std::cout << "  [!] Kombinasi FIVE OF A KIND ditemukan!\n";
        return HandRank::FIVE_OF_A_KIND;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::NONE;
}

HandRank RoyalFlushChecker::check(const Hand& hand) {
    std::cout << "  [Log] Mengecek: Royal Flush...\n";
    if (hand.dummyValue == 10) {
        std::cout << "  [!] Kombinasi ROYAL FLUSH ditemukan!\n";
        return HandRank::ROYAL_FLUSH;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::NONE;
}

HandRank StraightFlushChecker::check(const Hand& hand) {
    std::cout << "  [Log] Mengecek: Straight Flush...\n";
    if (hand.dummyValue == 9) {
        std::cout << "  [!] Kombinasi STRAIGHT FLUSH ditemukan!\n";
        return HandRank::STRAIGHT_FLUSH;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::NONE;
}

HandRank FourOfAKindChecker::check(const Hand& hand) {
    std::cout << "  [Log] Mengecek: Four of a Kind...\n";
    if (hand.dummyValue == 8) {
        std::cout << "  [!] Kombinasi FOUR OF A KIND ditemukan!\n";
        return HandRank::FOUR_OF_A_KIND;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::NONE;
}

HandRank FullHouseChecker::check(const Hand& hand) {
    std::cout << "  [Log] Mengecek: Full House...\n";
    if (hand.dummyValue == 7) {
        std::cout << "  [!] Kombinasi FULL HOUSE ditemukan!\n";
        return HandRank::FULL_HOUSE;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::NONE;
}

HandRank FlushChecker::check(const Hand& hand) {
    std::cout << "  [Log] Mengecek: Flush...\n";
    if (hand.dummyValue == 6) {
        std::cout << "  [!] Kombinasi FLUSH ditemukan!\n";
        return HandRank::FLUSH;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::NONE;
}

HandRank StraightChecker::check(const Hand& hand) {
    std::cout << "  [Log] Mengecek: Straight...\n";
    if (hand.dummyValue == 5) {
        std::cout << "  [!] Kombinasi STRAIGHT ditemukan!\n";
        return HandRank::STRAIGHT;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::NONE;
}

HandRank ThreeOfAKindChecker::check(const Hand& hand) {
    std::cout << "  [Log] Mengecek: Three of a Kind...\n";
    if (hand.dummyValue == 4) {
        std::cout << "  [!] Kombinasi THREE OF A KIND ditemukan!\n";
        return HandRank::THREE_OF_A_KIND;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::NONE;
}

HandRank TwoPairChecker::check(const Hand& hand) {
    std::cout << "  [Log] Mengecek: Two Pair...\n";
    if (hand.dummyValue == 3) {
        std::cout << "  [!] Kombinasi TWO PAIR ditemukan!\n";
        return HandRank::TWO_PAIR;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::NONE;
}

HandRank PairChecker::check(const Hand& hand) {
    std::cout << "  [Log] Mengecek: Pair...\n";
    if (hand.dummyValue == 2) {
        std::cout << "  [!] Kombinasi PAIR ditemukan!\n";
        return HandRank::PAIR;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::NONE;
}

HandRank HighCardChecker::check(const Hand& hand) {
    std::cout << "  [Log] Mengecek: High Card...\n";
    std::cout << "  [!] Kombinasi HIGH CARD ditetapkan!\n";
    return HandRank::HIGH_CARD;
}