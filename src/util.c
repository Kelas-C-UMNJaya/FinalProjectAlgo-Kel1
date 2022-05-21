#include "util.h"
#include "pembayaran.h"
#include <stdio.h>
#include <stdlib.h>

void prompt() {
  if (PLATFORM_NAME == "win") {
    system("pause");
  } else {
    printf("Tekan Enter Untuk Melanjutkan...");
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

void listBarang(Barang barang[], int jumlah, int category) {
  int iterator;
  int start = 0;
  int user;

  while (1) {
    if (category == 1) {
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

      puts("+======+=================================+=============+");
      puts("|1. Halaman Sebelumnya                                 |");
      puts("|2. Halaman Selanjutnya                                |");
      puts("|3. Pesan Barang                                       |");
      puts("|0. Kembali                                            |");
      puts("+======================================================+");

    } else if (category == 2 || category == 3) {
      puts("+======+=================================+=============+==========="
           "=="
           "=+");
      puts("|  ID  |           Nama Barang           |    Harga    |    "
           "Tanggal  "
           " |");
      puts("+======+=================================+=============+==========="
           "=="
           "=+");
      for (iterator = 0; iterator < 5; iterator++) {
        if ((iterator + start) >= jumlah) {
          break;
        }
        printf("| %-3d  | %-31s | Rp%-9d |  %-12s|\n",
               barang[iterator + start].id, barang[iterator + start].namaBarang,
               barang[iterator + start].hargaBarang,
               barang[iterator + start].tanggal);
      }
      printf(
          "+======+=================================+=============+==========="
          "===+\n");
      puts("|1. Halaman Sebelumnya                                             "
           "   |");
      puts("|2. Halaman Selanjutnya                                            "
           "   |");
      puts("|3. Pesan Barang                                                   "
           "   |");
      puts("|0. Kembali                                                        "
           "   |");
      printf("+================================================================"
             "=====+\n");
    }
    printf("Pilihan: ");
    scanf("%d%*c", &user);

    switch (user) {
    case 1:
      start -= 5;
      if (start < 0) {
        start = 0;
      }
      break;
    case 2:
      start += 5;
      if (start = jumlah + 5) {
        start = jumlah - 5;
      }
      break;
    case 3:
      promptSearch(barang, jumlah);
      break;
    case 0:
      return;
      break;
    }
    cls();
  }
}