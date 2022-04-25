#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// CATATAN
// Setiap menu (kecuali menu utama) memiliki menu-menu yang sama:
// - List 10 event/barang yang lagi trending
// - List semua barang/tiket
// - Pesan barang/tiket
// - Kembali ke menu utama

void prompt() {
  printf("\nTekan apa saja untuk melanjutkan...");
  getchar();
}

// TODO menu tiketnya
int menuTiket() {
  int tiketChoose;
  printf("==============================\n");
  printf("|            Tiket           |\n");
  printf("==============================\n");
  printf("1. Event Trending Bulan Ini\n"
         "2. Event Yang Akan Datang\n"
         "3. Pembelian Tiket\n"
         "0. Kembali Ke Menu Utama\n"
         "Pilihan: ");
  scanf("%d", &tiketChoose);
  printf("\n");
  return tiketChoose;
}

// TODO menu VOD
int menuVOD() {
  int vodChoose;
  printf("==============================\n");
  printf("|            VOD             |\n");
  printf("==============================\n");
  printf("1. VOD Trending Bulan Ini\n"
         "2. Daftar Semua VOD \n"
         "3. Pembelian VOD\n"
         "0. Kembali Ke Menu Utama\n"
         "Pilihan: ");
  scanf("%d", &vodChoose);
  printf("\n");
  return vodChoose;
}

// TODO menu merch
int menuMerch() {
  int merchChoose;
  printf("==============================\n");
  printf("|           Merch            |\n");
  printf("==============================\n");
  printf("1. Top Sale Bulan Ini\n"
         "2. Daftar Barang\n"
         "3. Pesan Barang\n"
         "0. Kembali Ke Menu Utama\n"
         "Pilihan: ");
  scanf("%d", &merchChoose);
  printf("\n");
  return merchChoose;
}

// TODO menu utama
int mainMenu() {
  int pilih;
  printf("==============================\n");
  printf("|          Main Menu         |\n");
  printf("==============================\n");
  printf("1. Beli Tiket\n"
         "2. Beli Digital Download\n"
         "3. Beli Merch\n"
         "0. Keluar\n");
  printf("Pilihan: ");
  scanf("%d", &pilih);
  printf("\n");
  return pilih;
}

// Nanti ada 3 menu, ikutin dari flowchartnya

int main() {
  bool keepGoing = true;
  while (keepGoing) {
    switch (mainMenu()) {
    case 1:
      menuTiket();
      break;
    case 2:
      menuVOD();
      break;
    case 3:
      menuMerch();
      break;
    case 0:
      keepGoing = false;
      break;
    default:
      printf("Pilihan Tidak Valid\n");
      prompt();
      break;
    }
  }
}
