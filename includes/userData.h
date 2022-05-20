#ifndef _USERDATA_H
#define _USERDATA_H
#include "DataTypes.h"
#include "fileProc.h"

extern UserData _USERDATA;

void readUserFile();
void initCart(UserData *user);
void printUser();
void addToCart(UserData *user, Barang data);
void printCart(UserData *user);
void topup();
unsigned long dedup(unsigned long saldo);
void writeUserFile(UserData data);
void readUserCart(UserData *user);
void writeUserCart(UserData user);
#endif