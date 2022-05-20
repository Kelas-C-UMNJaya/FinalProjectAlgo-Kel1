#include "DB.h"
#include "VOD.h"
#include "merch.h"
#include "tiket.h"
#include "userData.h"
#include "util.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// CATATAN
// Setiap menu (kecuali menu utama) memiliki menu-menu yang sama:
// - List 10 event/barang yang lagi trending
// - List semua barang/tiket
// - Pesan barang/tiket
// - Kembali ke menu utama

Barang _MERCHDB[100];
int _MERCHQTY = 0;
Barang _VODDB[100];
int _VODQTY = 0;
Barang _TIKETDB[100];
int _TIKETQTY = 0;

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

void init() {
  procDB("daftar_merch.txt", _MERCHDB, &_MERCHQTY);
  procDB("daftar_vod.txt", _VODDB, &_VODQTY);
  procDB("daftar_tiket.txt", _TIKETDB, &_TIKETQTY);
}

int main() {
  bool keepGoing = true;
  readUserFile();
  printUser();
  init();

  while (keepGoing) {
    switch (mainMenu()) {
    case 1:
      tiket();
      break;
    case 2:
      VOD();
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
