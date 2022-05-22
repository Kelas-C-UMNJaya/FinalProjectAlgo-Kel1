#include "DB.h"
#include "dbController.h"
#include "pembayaran.h"
#include "userData.h"
#include "util.h"
#include <stdio.h>

int menuMerch() {
  int merchChoose;
  printf("+================================+\n");
  printf("|              Merch             |\n");
  printf("+================================+\n");
  printf("|1. Top Sale Bulan Ini           |\n"
         "|2. Daftar Barang                |\n"
         "|3. Pesan Barang                 |\n"
         "|0. Kembali                      |\n"
         "+================================+\n"
         "Pilihan: ");
  scanf("%d%*c", &merchChoose);
  printf("\n");
  cls();
  return merchChoose;
}

int merch() {
  int id;
  int category = 1;
  while (1) {
    switch (menuMerch()) {
    // case 1:
    //   topSales();
    //   break;
    case 2:
      listBarang(&_MERCH, category);
      break;
    case 3:
      promptSearch(_MERCH);
      break;
    case 0:
      return 0;
      break;
    default:
      break;
    }
  }

  return 0;
}