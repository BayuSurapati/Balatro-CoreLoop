#include "JokerManager.h"

bool JokerManager::addJoker(std::unique_ptr<Joker> joker) {
    if (ownedJokers.size() >= MAX_JOKERS) {
        std::cout << "[JokerManager] Slot Joker penuh!\n";
        return false;
    }
    std::cout << "[JokerManager] " << joker->getName() << " ditambahkan ke slot.\n";
    ownedJokers.push_back(std::move(joker));
    return true;
}

void JokerManager::removeJoker(int index) {
    if (index >= 0 && index < (int)ownedJokers.size()) {
        std::cout << "[JokerManager] " << ownedJokers[index]->getName() << " dihapus.\n";
        ownedJokers.erase(ownedJokers.begin() + index);
    }
}

void JokerManager::applyAllEffects(long long& chips, double& mult, const ChosenHand& hand, HandRank rank) {
    std::cout << "[JokerManager] Menerapkan efek Joker (Kiri -> Kanan):\n";
    for (auto& joker : ownedJokers) {
        long long oldChips = chips;
        double oldMult = mult;
        joker->applyEffect(chips, mult, hand, rank);
        
        if (chips != oldChips || mult != oldMult) {
            std::cout << "  [!] " << joker->getName() << " aktif! -> Chips: " << chips << ", Mult: " << mult << "\n";
        }
    }
}

void JokerManager::displayJokers() const {
    if (ownedJokers.empty()) {
        std::cout << "Tidak ada";
    } else {
        for (int i = 0; i < (int)ownedJokers.size(); i++) {
            std::cout << "[" << i + 1 << ". " << ownedJokers[i]->getName() << "] ";
        }
    }
    std::cout << "\n";
}

bool JokerManager::isFull() const {
    return ownedJokers.size() >= MAX_JOKERS;
}

int JokerManager::getCount() const {
    return (int)ownedJokers.size();
}

void JokerManager::swapJokers(int i, int j) {
    if (i >= 0 && i < (int)ownedJokers.size() && j >= 0 && j < (int)ownedJokers.size()) {
        std::swap(ownedJokers[i], ownedJokers[j]);
        std::cout << "[JokerManager] Joker dipindah posisinya.\n";
    }
}