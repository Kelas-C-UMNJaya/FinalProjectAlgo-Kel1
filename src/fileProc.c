#include "fileProc.h"
#include <stdio.h>
#include <string.h>

void procDB(char *namaFile, Barang arr[]) {
  int i = 0;
  char fileIn[100] = "../data/";
  strcat(fileIn, namaFile);
  FILE *fp = fopen(fileIn, "r");

  while (!feof(fp)) {

    struct barang newBarang;
    fscanf(fp, "%[^,],%d\n", newBarang.namaBarang, &newBarang.hargaBarang);
    arr[i] = newBarang;

    i++;
  }
  fclose(fp);
}

void writeDB(char *namaFile, Barang arr[]) {
  char fileOut[100] = "../data/";
  strcat(fileOut, namaFile);
  FILE *fp = fopen(fileOut, "w");

  for (int i = 0; i < 10; i++) {
    fprintf(fp, "%s,%d\n", arr[i].namaBarang, arr[i].hargaBarang);
  }
  fclose(fp);
}