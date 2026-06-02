#pragma once
#include "../Models/ChosenHand.h"
#include "../Models/HandRank.h"
#include <map>
#include <algorithm>
#include <vector>

class PokerHandChecker {
protected:
    PokerHandChecker* nextChecker = nullptr;

    // Helper functions - bisa dipakai semua checker turunan
    std::map<int,int> rankCount(const ChosenHand& hand) const {
        std::map<int,int> freq;
        for (auto& c : hand.cards) freq[c.rank]++;
        return freq;
    }

   bool allSameSuit(const ChosenHand& hand) const {
    // Tolak jika jumlah kartu tidak sama dengan 5
    if (hand.cards.size() != 5) return false;

    // tipe data 'char' sesuai deklarasi di Models/Card.h
    char s = hand.cards[0].suit;
    for (auto& c : hand.cards) {
        if (c.suit != s) return false;
    }
    return true;
}

    bool isSequential(const ChosenHand& hand) const {
        if (hand.cards.size() != 5) return false; //harus cek 5 kartu untuk straight    

        std::vector<int> ranks;
        for (auto& c : hand.cards) ranks.push_back(c.rank);
        std::sort(ranks.begin(), ranks.end());
        for (int i = 1; i < (int)ranks.size(); i++)
            if (ranks[i] != ranks[i-1] + 1) return false;
        return true;
    }

    int countFreq(const std::map<int,int>& freq, int n) const {
        int count = 0;
        for (auto& p : freq)
            if (p.second == n) count++;
        return count;
    }

public:
    virtual ~PokerHandChecker() = default;
    void setNext(PokerHandChecker* next) { nextChecker = next; }
    virtual HandRank check(const ChosenHand& hand) = 0;
};