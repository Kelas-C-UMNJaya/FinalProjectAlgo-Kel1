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
    fprintf(fp, "%d,%s,%d\n", arr[i].id, arr[i].namaBarang, arr[i].hargaBarang);
  }
  fclose(fp);
}

void procDB(char *namaFile, Barang arr[], int *jumlah) {
  int i = 0;
  char fileIn[100] = "../data/";
  strcat(fileIn, namaFile);
  FILE *fp = fopen(fileIn, "r");

  while (!feof(fp)) {

    Barang newBarang;
    fscanf(fp, "%d,%[^,],%d\n", &newBarang.id, newBarang.namaBarang,
           &newBarang.hargaBarang);
    arr[i] = newBarang;

    i++;
  }
  *jumlah = i;
  if (!isSorted(arr, *jumlah)) {
    sortDB(arr, *jumlah);
    writeDB(namaFile, arr, *jumlah);
  }
  fclose(fp);
}
