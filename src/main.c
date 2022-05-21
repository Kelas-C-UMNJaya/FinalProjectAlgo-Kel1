#include "DB.h"
#include "VOD.h"
#include "merch.h"
#include "tiket.h"
#include "userData.h"
#include "util.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

DB _MERCH;
DB _VOD;
DB _TIKET;

void init() {
  procDB("daftar_merch.txt", &_MERCH);
  procDB("daftar_vod.txt", &_VOD);
  procDB("daftar_tiket.txt", &_TIKET);
}

int mainMenu() {
  int pilih;
  printf("+================================+\n");
  printf("|            Main Menu           |\n");
  printf("+================================+\n");
  printf("|1. Beli Tiket                   |\n"
         "|2. Beli Digital Download        |\n"
         "|3. Beli Merch                   |\n"
         "|4. Tampilkan Shopping Cart      |\n"
         "|0. Keluar                       |\n"
         "+================================+\n"
         "Pilihan: ");
  scanf("%d", &pilih);
  printf("\n");
  return pilih;
}

int main() {
  cls();
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
    case 4:
      printUser();
      printCart(&_USERDATA);
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
