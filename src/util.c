#include "util.h"
// #include "../includes/fileProc.h"
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
  puts("======+================+========");
  puts("| ID  |  Nama Barang   | Harga |");
  puts("======+================+========");

  for (int i = 0; i < jumlah; i++) {
    printf("| %d  | %-15s | Rp%d |\n", barang[i].id, barang[i].namaBarang,
           barang[i].hargaBarang);
  }
}