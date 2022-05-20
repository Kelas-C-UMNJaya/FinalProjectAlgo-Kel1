#include "fileProc.h"
#include "userData.h"
#include "util.h"
#include <stdio.h>

Barang _MERCHDB[100];
int _MERCHQTY = 0;

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
  scanf("%d%*c", &merchChoose);
  printf("\n");
  cls();
  return merchChoose;
}

int merch() {
  procDB("Daftar_Barang.txt", _MERCHDB, &_MERCHQTY);
  while (1) {

    switch (menuMerch()) {
    // case 1:
    //   topSales();
    //   break;
    case 2:
      listBarang(_MERCHDB, _MERCHQTY);
      break;
    case 3:
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