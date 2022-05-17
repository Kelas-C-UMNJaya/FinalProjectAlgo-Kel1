#include "fileProc.h"
#include <stdio.h>
#include <string.h>

void proc(char *namaFile, Barang arr[]) {

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