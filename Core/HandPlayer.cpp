// Core/HandPlayer.cpp
#include "HandPlayer.h"
#include <iostream>
#include <string>
#include <set>

// Helper: tampilkan nama kartu
std::string rankName(int rank) {
    if (rank == 11) return "J";
    if (rank == 12) return "Q";
    if (rank == 13) return "K";
    if (rank == 14) return "A";
    return std::to_string(rank);
}

ChosenHand HandPlayer::playHand(const Hand& hand) {
    // Tampilkan 8 kartu
    std::cout << "\n[System] Kartu yang kamu miliki:\n";
    for (int i = 0; i < (int)hand.cards.size(); i++) {
        std::cout << "  [" << i + 1 << "] "
                  << rankName(hand.cards[i].rank)
                  << hand.cards[i].suit << "\n";
    }

    // Input pilihan pemain
    ChosenHand chosen;
    std::set<int> sudahPilih;

    std::cout << "\n[System] Pilih maksimal 5 kartu (masukkan nomor 1-8, ketik 0 untuk selesai):\n";

    while (chosen.cards.size() < 5) {
        std::cout << "  Pilihan ke-" << chosen.cards.size() + 1 << " (0 = selesai): ";
        int input;
        std::cin >> input;

        if (input == 0) break;

        if (input < 1 || input > (int)hand.cards.size()) {
            std::cout << "  [!] Nomor tidak valid, coba lagi.\n";
            continue;
        }

        if (sudahPilih.count(input)) {
            std::cout << "  [!] Kartu sudah dipilih, pilih yang lain.\n";
            continue;
        }

        sudahPilih.insert(input);
        chosen.cards.push_back(hand.cards[input - 1]);
        std::cout << "  [+] " << rankName(hand.cards[input - 1].rank)
                  << hand.cards[input - 1].suit << " ditambahkan.\n";
    }

    // Tampilkan kartu yang dipilih
    std::cout << "\n[System] Kartu yang kamu mainkan: ";
    for (auto& c : chosen.cards)
        std::cout << rankName(c.rank) << c.suit << " ";
    std::cout << "\n";

    return chosen;
}