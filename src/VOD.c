#include "DB.h"
#include "fileProc.h"
#include "userData.h"
#include "util.h"
#include <stdio.h>

int VOD_menu() {
  int VODChoose;
  printf("+================================+\n");
  printf("|               VOD              |\n");
  printf("+================================+\n");
  printf("|1. Top VOD Bulan Ini            |\n"
         "|2. Daftar VOD                   |\n"
         "|3. Pesan VOD                    |\n"
         "|0. Kembali                      |\n"
         "+================================+\n"
         "Pilihan: ");
  scanf("%d%*c", &VODChoose);
  printf("\n");
  cls();
  return VODChoose;
}

int VOD() {
  int keepGoing = 1;
  int category = 2;

  while (keepGoing) {
    switch (VOD_menu()) {
    case 1:
      //   VOD_trending();
      break;
    case 2:
      listBarang(_VOD.db, _VOD.qty, category);
      break;
    case 3:
      //   pembelian_VOD();
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