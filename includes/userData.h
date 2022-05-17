#include "fileProc.h"

typedef struct User {
  char nama[100];
  unsigned long saldo;
  Barang cart[100];
  int cartSize;
} UserData;

UserData readUserFile();
void printUser(UserData user);
void writeUserFile(UserData data);
void readUserCart(UserData *user);
void writeUserCart(UserData user);