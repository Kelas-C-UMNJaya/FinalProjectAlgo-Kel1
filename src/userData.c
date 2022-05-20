#include "userData.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
UserData _USERDATA;

UserData createUser() {
  UserData newUser;
  char nama[100];
  unsigned long saldo = 0;
  printf("Masukkan nama anda: ");
  scanf("%[^\n]%*c", nama);
  strcpy(newUser.nama, nama);
  newUser.saldo = saldo;
  return newUser;
}

void initCart(UserData *user) {
  user->cartFront = NULL;
  user->cartBack = NULL;
  user->cartSize = 0;
}

void printUser() {
  printf("Nama: %s\n", _USERDATA.nama);
  printf("Saldo: %lu\n", _USERDATA.saldo);
  printf("Cart Size: %d\n", _USERDATA.cartSize);
}

void addToCart(UserData *user, Barang data) {
  Cart *newItem = (Cart *)malloc(sizeof(Cart));
  newItem->next = NULL;
  if (user->cartFront == NULL) {
    user->cartFront = user->cartBack = newItem;
  } else {
    user->cartBack->next = newItem;
    user->cartBack = newItem;
  }
  user->cartSize++;
}

void removeFrontCart(UserData *user) {
  Cart *temp = user->cartFront;
  user->cartFront = user->cartFront->next;
  free(temp);
  user->cartSize--;
}

void topup(unsigned long saldo) { _USERDATA.saldo += saldo; }
void dedup(unsigned long saldo) { _USERDATA.saldo -= saldo; }

void readUserFile() {
  FILE *fp = fopen("../data/user_data.txt", "r");
  if (fp == NULL) {
    printf("File tidak ditemukan, membuat file...\n");
    UserData newUser = createUser();
    writeUserFile(newUser);
    _USERDATA = newUser;
    return;
  }
  UserData user;
  fscanf(fp, "%[^,],%lu\n", user.nama, &user.saldo);
  readUserCart(&user);
  fclose(fp);
  _USERDATA = user;
}

void writeUserFile(UserData data) {
  FILE *fp = fopen("../data/user_data.txt", "w");
  fprintf(fp, "%s,%lu\n", data.nama, data.saldo);
  writeUserCart(data);
  fclose(fp);
}

void readUserCart(UserData *user) {
  FILE *fp = fopen("../data/user_cart.txt", "r");
  if (fp == NULL) {
    printf("File tidak ditemukan, membuat file...\n");
    writeUserCart(*user);
    exit(1);
  }
  int i = 0;
  while (!feof(fp)) {
    struct barang newBarang;
    fscanf(fp, "%[^,],%d\n", newBarang.namaBarang, &newBarang.hargaBarang);
    addToCart(user, newBarang);
    i++;
  }
  user->cartSize = i;
  fclose(fp);
}

void writeUserCart(UserData user) {
  FILE *fp = fopen("../data/user_cart.txt", "w");
  int i;
  Cart *temp = user.cartFront;
  while (temp != NULL) {
    fprintf(fp, "%s,%d\n", temp->data.namaBarang, temp->data.hargaBarang);
    temp = temp->next;
  }
  fclose(fp);
}