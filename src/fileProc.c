#include "fileProc.h"
#include <stdio.h>
#include <string.h>

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
  fclose(fp);
}

void writeDB(char *namaFile, Barang arr[]) {
  char fileOut[100] = "../data/";
  strcat(fileOut, namaFile);
  FILE *fp = fopen(fileOut, "w");

  for (int i = 0; i < 10; i++) {
    fprintf(fp, "%d,%s,%d\n", arr[i].id, arr[i].namaBarang, arr[i].hargaBarang);
  }
  fclose(fp);
}