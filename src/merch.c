#include "fileProc.h"
#include "system.h"
#include <stdio.h>

typedef struct
{
  // int id;
  char namaBarang[50];
  int hargaBarang;
} Barang;

// void prompt() {
//   printf("\nTekan apa saja untuk melanjutkan...");
//   getchar();
// }

int menuMerch()
{
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

void daftar()
{
  int i = 0;
  Barang barang[12];

  puts("===============================");
  puts("=======| Daftar Barang |=======");
  puts("===============================");

  proc(barang);

  printf("\n");
  for (i = 0; i < 12; i++)
  {
    printf("Barang ke-%d\n", i + 1);
    // printf("ID : %d\n", barang[i].id);
    printf("Nama Barang: %s\n", barang[i].namaBarang);
    printf("Harga Barang: Rp%d\n", barang[i].hargaBarang);
    printf("\n");
  }

  prompt();
  cls();
}

int merch()
{
  while (1)
  {

    switch (menuMerch())
    {
    // case 1:
    //   topSales();
    //   break;
    case 2:
      daftar();
      break;
    // case 3:
    //   pesan();
    //   break;
    case 0:
      return 0;
      break;
    default:
      break;
    }
  }

  return 0;
}