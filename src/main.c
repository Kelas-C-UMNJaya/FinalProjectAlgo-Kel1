#include "merch.h"
#include "system.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// CATATAN
// Setiap menu (kecuali menu utama) memiliki menu-menu yang sama:
// - List 10 event/barang yang lagi trending
// - List semua barang/tiket
// - Pesan barang/tiket
// - Kembali ke menu utama

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
      merch();
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
