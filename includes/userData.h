#ifndef _USERDATA_H
#define _USERDATA_H
#include "DataTypes.h"
#include "fileProc.h"

extern UserData _USERDATA;

void readUserFile();
void initCart(UserData *user);
void printUser();
void writeUserFile(UserData data);
void readUserCart(UserData *user);
void writeUserCart(UserData user);
#endif