#ifndef DATATYPES_H_
#define DATATYPES_H_

#define MAX_TRENDING 5
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

typedef struct Node {
  Barang data;
  struct Node *left, *right;
} Node;
typedef struct {
  Barang db[100];
  Barang trending[MAX_TRENDING];
  Node *binaryTree;
  int qty;
} DB;

#endif