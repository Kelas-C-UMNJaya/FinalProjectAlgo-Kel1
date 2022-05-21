#include "fileProc.h"
#include "util.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

void sortDB(Barang barang[], int jumlah) {
  Barang temp;
  for (int i = 0; i < jumlah; i++) {
    for (int j = i + 1; j < jumlah; j++) {
      if (barang[i].id > barang[j].id) {
        temp = barang[i];
        barang[i] = barang[j];
        barang[j] = temp;
      }
    }
  }
}

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
  char fileIn[100] = "./data/barang/";
  strcat(fileIn, namaFile);
  FILE *fp = fopen(fileIn, "r");
  if (fp == NULL) {
    printf("File %s tidak ditemukan, membuat file...\n", namaFile);
    writeDB(namaFile, database->db, database->qty);
    fp = fopen(fileIn, "r");
  }
  clearDB(database);
  Barang newBarang;
  while (fscanf(fp, "%d,%[^,],%d,%[^\n]\n", &newBarang.id, newBarang.namaBarang,
                &newBarang.hargaBarang, newBarang.tanggal) != EOF) {
    database->db[i] = newBarang;
    i++;
  }
  database->qty = i;
  if (!isSorted(database->db, database->qty)) {
    sortDB(database->db, database->qty);
    writeDB(namaFile, database->db, database->qty);
  }
  fclose(fp);
}
