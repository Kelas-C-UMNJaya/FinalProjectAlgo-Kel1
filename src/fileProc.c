#include "fileProc.h"
#include <stdio.h>
#include <string.h>

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

int isSorted(Barang barang[], int jumlah) {
  for (int i = 0; i < jumlah - 1; i++) {
    if (barang[i].id > barang[i + 1].id) {
      return 0;
    }
  }
  return 1;
}

void writeDB(char *namaFile, Barang arr[], int jumlah) {
  char fileOut[100] = "../data/";
  strcat(fileOut, namaFile);
  FILE *fp = fopen(fileOut, "w");

  for (int i = 0; i < jumlah; i++) {
    fprintf(fp, "%d,%s,%d,%s\n", arr[i].id, arr[i].namaBarang,
            arr[i].hargaBarang, arr[i].tanggal);
  }
  fclose(fp);
}

void procDB(char *namaFile, DB *database) {
  int i = 0;
  char fileIn[100] = "../data/";
  strcat(fileIn, namaFile);
  FILE *fp = fopen(fileIn, "r");

  while (!feof(fp)) {

    Barang newBarang;
    fscanf(fp, "%d,%[^,],%d,%s\n", &newBarang.id, newBarang.namaBarang,
           &newBarang.hargaBarang, newBarang.tanggal);
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
