#include "fileProc.h"
#include "userData.h"
#include "util.h"
#include <stdio.h>

Barang _TIKETDB[100];
int _TIKETQTY = 0;

int tiket_menu() {
  int tiketChoose;
  printf("==============================\n");
  printf("|            Tiket           |\n");
  printf("==============================\n");
  printf("1. Event Trending Bulan Ini\n"
         "2. Event Yang Akan Datang\n"
         "3. Pembelian Tiket\n"
         "0. Kembali Ke Menu Utama\n"
         "Pilihan: ");
  scanf("%d%*c", &tiketChoose);
  printf("\n");
  cls();
  return tiketChoose;
}

int tiket() {
  int keepGoing = 1;
  procDB("daftar_tiket.txt", _TIKETDB, &_TIKETQTY);

  while (keepGoing) {
    switch (tiket_menu()) {
    case 1:
      //   event_trending();
      break;
    case 2:
      listBarang(_TIKETDB, _TIKETQTY);
      break;
    case 3:
      //   pembelian_tiket();
      break;
    case 0:
      keepGoing = 0;
      break;
    default:
      printf("Pilihan tidak ada\n");
      break;
    }
  }
  return 0;
}