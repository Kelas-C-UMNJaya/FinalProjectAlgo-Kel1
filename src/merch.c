#include "DB.h"
#include "fileProc.h"
#include "pembayaran.h"
#include "userData.h"
#include "util.h"
#include <stdio.h>

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
      int id;
      printf("Masukkan ID barang: ");
      scanf("%d%*c", &id);
      Barang *barangFind = searchBarang(id, _MERCHDB, _MERCHQTY);
      if (barangFind == NULL) {
        printf("Barang tidak ditemukan\n");
        break;
      }
      printf("Nama barang: %s\n", (*barangFind).namaBarang);
      printf("Harga barang: Rp%d\n", (*barangFind).hargaBarang);
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