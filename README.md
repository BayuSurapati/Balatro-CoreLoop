# Balatro-CoreLoop
DesignPattern menggunakan studi kasus game balatro dan membuat cloningan gamenya

Overview
Balatro-CoreLoop adalah sistem evaluasi dan penilaian pokerhand berbasis C++ yang terinspirasi dari mekanik game roguelike poker. Proyek ini dirancang untuk:
- Mengevaluasi jenis kartu tangan poker 
- Menghitung skor
- Menerapkan efek Joker 
- Mengelola aksi pemain seperti bermain (PLAY) atau melewati tantangan (SKIP).
Arsitekturnya bersifat modular dan memanfaatkan Design Patterns, sehingga setiap sistem memiliki tanggung jawabnya masing-masing dan dapat diperluas tanpa harus menulis ulang keseluruhan proyek.

High-Level Architecture
Proyek ini dibagi menjadi beberapa sistem utama:
| System            | Responsibility                                                            |
| :---------------- | :------------------------------------------------------------------------ |
| **GameManager** | Mengontrol keseluruhan alur game, iterasi Blind, dan fase Toko.           |
| **HandGenerator** | Menginisialisasi dek, mengacak, dan membagikan kartu ke pemain.           |
| **HandPlayer** | Menangani input pengguna untuk memilih kartu yang akan dimainkan.         |
| **ScoringRule** | Mengevaluasi kombinasi *pokerhand* dan menghitung skor dasar.             |
| **JokerManager** | Menyimpan inventaris Joker pemain dan menerapkan efek pengalinya.         |
| **ShopManager** | Mengelola transaksi pembelian Joker dan *refresh* stok toko.              |
| **BlindState** | Mengontrol progresi *Small/Big/Boss Blind* beserta target skornya.        |
| **SkipCommand** | Menjalankan *reward* acak (Uang atau Joker) saat pemain melewati *Blind*. |


Runtime Flow 
Sesi permainan berjalan mengikuti urutan berikut:
main() → GameManager::runSession() → processBlind() → Draw Hand → Player Selects Cards (ChosenHand) → Evaluate Base Score → Apply Joker Effects → Compare Target Score → Give Money Reward  → shopPhase() → Next Blind. 

System Flow
Sistem runtime dibagi menjadi tiga tahapan utama:
  1. Session Setup
     Tahapan ini mempersiapkan status awal sebelum pemain mulai bermain.
     - GameManager mengatur uang pemain (playerMoney) dan nilai target dasar (baseScore).
     - Pointer currentBlind diinisialisasi menggunakan SmallBlindState.
  2. Main Gameplay Loop
     Terjadi di dalam GameManager::processBlind(), di mana pemain mencoba mencapai target skor yang diminta oleh          - BlindState saat ini.
     - Pemain mulai memainkan blind
     - Pemain memilih maksimal 5 kartu.
     - ScoringRule menilai tipe kombinasi dan mengambil Base Chips dan Base Mult.
     - JokerManager menambahkan atau mengalikan skor berdasarkan efek Joker yang dimiliki pemain.
     - Jika berhasil memenangkan ronde, pemain menerima uangi dan masuk ke shopPhase() untuk membeli atau menyusun          posisi Joker baru.
     - Transisi currentBlind bergeser ke state berikutnya.
  3. Action Branches
     Saat berada di awal Blind, pemain ditawarkan dua cabang aksi:
     - PLAY (1): Memasuki tahapan Main Gameplay Loop untuk mengevaluasi skor.
     - SKIP (2): Jika State mengizinkan (canSkip()), sistem memanggil executeSkipReward() dan menjalankan SkipCommand secara acak. Pemain bisa mendapat uang instan atau Joker acak, dan permainan langsung melompat ke Blind berikutnya.
