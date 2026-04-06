#include "HandGenerator.h"
#include "iostream"

Hand HandGenerator::generateHand(){
    std::cout << "[System] Membagikan kartu kepada pemain...\n";
    
    // Mengatur 'seed' waktu agar angka acak
    srand(static_cast<unsigned int>(time(0))); 
    
    Hand hand;
    hand.dummyValue = (rand() % 13) + 1; 
    
    std::cout << "  [Rahasia] Sistem memberikan kartu dengan kode: " << hand.dummyValue << "\n\n";
    return hand;
}