#ifndef DATATYPES_H_
#define DATATYPES_H_
typedef struct barang {
  int id;
  char namaBarang[50];
  int hargaBarang;
  char tanggal[11];
} Barang;

typedef struct CartQueue {
  Barang data;
  struct CartQueue *next;
} Cart;

typedef struct User {
  char nama[100];
  unsigned long saldo;
  Cart *cartFront, *cartBack;
  int cartSize;
} UserData;

#endif