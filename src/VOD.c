#include "fileProc.h"
#include "util.h"
#include <stdio.h>

Barang barang[100];
int barang_jumlah = 0;

int VOD_menu() {
  int VODChoose;
  printf("==============================\n");
  printf("|             VOD            |\n");
  printf("==============================\n");
  printf("1. Top VOD Bulan Ini\n"
         "2. Daftar VOD\n"
         "3. Pesan VOD\n"
         "0. Kembali Ke Menu Utama\n"
         "Pilihan: ");
  scanf("%d%*c", &VODChoose);
  printf("\n");
  cls();
  return VODChoose;
}

int VOD() {
  int keepGoing = 1;
  procDB("daftar_vod.txt", barang, &barang_jumlah);

  while (keepGoing) {
    switch (VOD_menu()) {
    case 1:
      //   VOD_trending();
      break;
    case 2:
      listBarang(barang, barang_jumlah);
      break;
    case 3:
      //   pembelian_VOD();
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