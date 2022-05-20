#include "util.h"
#include <stdio.h>
#include <stdlib.h>

void prompt() {
  if (PLATFORM_NAME == "win") {
    system("pause");
  } else {
    printf("Press enter to continue...");
    getchar();
  }
}

void cls() {
  if (PLATFORM_NAME == "win") {
    system("cls");
  } else {
    system("clear");
  }
}

void listBarang(Barang barang[], int jumlah) {
  int iterator;
  int start = 0;
  int user;

  while (1) {
    puts("+======+=================================+=============+");
    puts("|  ID  |           Nama Barang           |    Harga    |");
    puts("|======+=================================+=============|");

    for (iterator = 0; iterator < 5; iterator++) {
      if ((iterator + start) >= jumlah) {
        break;
      }
      printf("| %-3d  | %-31s | Rp%-9d |\n", barang[iterator + start].id,
             barang[iterator + start].namaBarang,
             barang[iterator + start].hargaBarang);
    }
    printf("+======+=================================+=============+\n");
    puts("|1. Next Page                                          |");
    puts("|2. Previous Page                                      |");
    puts("|0. Kembali                                            |");
    printf("+======================================================+\n");
    printf("Pilihan: ");
    scanf("%d%*c", &user);

    switch (user) {
    case 1:
      start += 5;
      if (start = jumlah + 5) {
        start = jumlah - 5;
      }
      break;
    case 2:
      start -= 5;
      if (start < 0) {
        start = 0;
      }
      break;
    case 0:
      return;
      break;
    }
    cls();
  }
}