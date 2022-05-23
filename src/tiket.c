#include "DB.h"
#include "dbController.h"
#include "userData.h"
#include "util.h"
#include <stdio.h>
#include "pembayaran.h"

int tiket_menu() {
  int tiketChoose;
  cls();
  printf("+================================+\n");
  printf("|              Tiket             |\n");
  printf("+================================+\n");
  printf("|1. Event Trending Bulan Ini     |\n"
         "|2. Event Yang Akan Datang       |\n"
         "|3. Pembelian Tiket              |\n"
         "|0. Kembali                      |\n"
         "+================================+\n"
         "Pilihan: ");
  scanf("%d%*c", &tiketChoose);
  printf("\n");
  cls();
  return tiketChoose;
}

int tiket() {
  int category = 3;
  int keepGoing = 1;

  while (keepGoing) {
    switch (tiket_menu()) {
    case 1:
      listTrending(&_TIKET, category);
      break;
    case 2:
      listBarang(&_TIKET, category);
      break;
    case 3:
      promptSearch(_MERCH);
      break;
    case 0:
      keepGoing = 0;
      break;
    default:
      printf("Pilihan Tidak Valid\n");
      break;
    }
  }
  return 0;
}