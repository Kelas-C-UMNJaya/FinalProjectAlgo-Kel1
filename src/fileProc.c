#include <stdio.h>

typedef struct {
  // int id[3];
  char namaBarang[50];
  int hargaBarang;
} Barang;

void proc(Barang barang[12]) {
  int i = 0;
  FILE *fp = fopen("../data/Daftar_Barang.txt", "r");

  while (!feof(fp)) {
    Barang newBarang;
    fscanf(fp, "%[^,],%d\n", newBarang.namaBarang, &newBarang.hargaBarang);
    barang[i] = newBarang;
    i++;
  }
  fclose(fp);
}