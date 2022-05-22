#include "dbController.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

// void sortDB(Barang barang[], int jumlah) {
//   Barang temp;
//   for (int i = 0; i < jumlah; i++) {
//     for (int j = i + 1; j < jumlah; j++) {
//       if (barang[i].id > barang[j].id) {
//         temp = barang[i];
//         barang[i] = barang[j];
//         barang[j] = temp;
//       }
//     }
//   }
// }

void initDir() {
  if (!mkdire("./data", 0777)) {
    printf("Directory data doesn't exist, creating...\n");
    mkdire("./data/barang", 0777);
    mkdire("./data/user", 0777);
    return;
  }
  printf("Directory data exists\n");
}

int isSorted(Barang barang[], int jumlah) {
  for (int i = 0; i < jumlah - 1; i++) {
    if (barang[i].id > barang[i + 1].id) {
      return 0;
    }
  }
  return 1;
}

void writeDB(char *namaFile, Barang arr[], int jumlah) {
  char fileOut[100] = "./data/barang/";
  strcat(fileOut, namaFile);
  FILE *fpOut = fopen(fileOut, "w");

  for (int i = 0; i < jumlah; i++) {
    fprintf(fpOut, "%d,%s,%d,%s\n", arr[i].id, arr[i].namaBarang,
            arr[i].hargaBarang, arr[i].tanggal);
  }
  fclose(fpOut);
}

void clearDB(DB *database) {
  for (int i = 0; i < database->qty; i++) {
    database->db[i] = (Barang){0, "", 0, ""};
  }
  database->qty = 0;
}

void procDB(char *namaFile, DB *database) {
  int i = 0;
  int j = 0;
  char fileIn[100] = "./data/barang/";
  strcat(fileIn, namaFile);
  FILE *fp = fopen(fileIn, "r");
  if (fp == NULL) {
    printf("File %s tidak ditemukan, membuat file...\n", namaFile);
    writeDB(namaFile, database->db, database->qty);
    fp = fopen(fileIn, "r");
    // return;
  }
  clearDB(database);
  Barang newBarang;
  int scanResult;
  srand(time(NULL));
  do {
    scanResult =
        fscanf(fp, "%d,%[^,],%d,%[^\n]\n", &newBarang.id, newBarang.namaBarang,
               &newBarang.hargaBarang, newBarang.tanggal);
    if (scanResult == 3 || scanResult == 4) {
      if (scanResult == 3) {
        strcpy(newBarang.tanggal, "");
      }
      database->db[i] = newBarang;
      if (rand() % 2 == 0 && j < 5) {
        database->trending[j] = newBarang;
      }
      i++;
    }
  } while (scanResult != EOF || scanResult > 3);
  database->qty = i;
  createTreeFromDB(&database->binaryTree, database->db, database->qty, 0);
  // if (!isSorted(database->db, database->qty)) {
  // sortDB(database->db, database->qty);
  // writeDB(namaFile, database->db, database->qty);
  // }
  fclose(fp);
}
