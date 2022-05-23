#ifndef _USERDATA_H
#define _USERDATA_H
#include "DataTypes.h"
#include "dbController.h"

extern UserData _USERDATA;

void readUserFile();
void initCart(UserData *user);
void printUser();
unsigned long totalCart(UserData *user);
void addToCart(UserData *user, Barang data);
void printCart(UserData *user);
void topup();
unsigned long dedup(unsigned long saldo);
void writeUserFile(UserData data);
void readUserCart(UserData *user);
void writeUserCart(UserData user);
void clearCart(UserData *user);
void printNota(UserData *user);
void writeNota(UserData *user);
#endif