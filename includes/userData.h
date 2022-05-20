#ifndef _USERDATA_H
#define _USERDATA_H
#include "fileProc.h"

typedef struct User {
  char nama[100];
  unsigned long saldo;
  Barang cart[100];
  int cartSize;
} UserData;

extern UserData _USERDATA;

void readUserFile();
void printUser();
void writeUserFile(UserData data);
void readUserCart(UserData *user);
void writeUserCart(UserData user);
#endif