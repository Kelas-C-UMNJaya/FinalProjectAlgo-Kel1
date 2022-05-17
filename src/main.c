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
  UserData user = readUserFile();
  printUser(user);

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
