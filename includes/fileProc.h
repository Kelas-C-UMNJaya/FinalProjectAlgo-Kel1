typedef struct barang {
  int id;
  char namaBarang[50];
  int hargaBarang;
} Barang;
void procDB(char *namaFile, Barang arr[]);