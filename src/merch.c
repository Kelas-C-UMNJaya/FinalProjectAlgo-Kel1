#include "fileProc.h"
#include "userData.h"
#include "util.h"
#include <stdio.h>

Barang barang[100];
int barang_jumlah = 0;

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

// TODO ganti dengan yang di util.c
void daftar() {
  int i = 0;

  puts("===============================");
  puts("=======| Daftar Barang |=======");
  puts("===============================");

  printf("\n");
  for (i = 0; i < 12; i++) {
    printf("Barang ke-%d\n", i + 1);
    // printf("ID : %d\n", barang[i].id);
    printf("Nama Barang: %s\n", barang[i].namaBarang);
    printf("Harga Barang: Rp%d\n", barang[i].hargaBarang);
    printf("\n");
  }

  prompt();
  cls();
}

void pesan() {
  int i = 0;

  puts("================================");
  puts("========| Pesan Barang |========");
  puts("================================");

  printf("\n");
  printf("Nama Barang : ");
  printf("Banyak Barang : ");
  prompt();
  cls();
}

int merch() {
  procDB("Daftar_Barang.txt", barang, &barang_jumlah);
  while (1) {

    switch (menuMerch()) {
    // case 1:
    //   topSales();
    //   break;
    case 2:
      listBarang(barang, barang_jumlah);
      break;
    case 3:
      pesan();
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