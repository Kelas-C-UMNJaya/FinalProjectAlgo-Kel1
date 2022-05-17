#include "userData.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

UserData createUser() {
  UserData newUser;
  char nama[100];
  unsigned long saldo = 0;
  printf("Masukkan nama anda: ");
  scanf("%[^\n]%*c", nama);
  strcpy(newUser.nama, nama);
  newUser.saldo = saldo;
  newUser.cartSize = 0;
  return newUser;
}

void printUser(UserData user) {
  printf("Nama: %s\n", user.nama);
  printf("Saldo: %d\n", user.saldo);
  printf("Cart Size: %d\n", user.cartSize);
}

UserData readUserFile() {
  FILE *fp = fopen("../data/user_data.txt", "r");
  if (fp == NULL) {
    printf("File tidak ditemukan, membuat file...\n");
    UserData newUser = createUser();
    writeUserFile(newUser);
    return newUser;
  }
  UserData user;
  fscanf(fp, "%[^,],%d\n", user.nama, &user.saldo);
  readUserCart(&user);
  fclose(fp);
  return user;
}

void writeUserFile(UserData data) {
  FILE *fp = fopen("../data/user_data.txt", "w");
  fprintf(fp, "%s,%d\n", data.nama, data.saldo);
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
    user->cart[i] = newBarang;
    i++;
  }
  user->cartSize = i;
  fclose(fp);
}

void writeUserCart(UserData user) {
  FILE *fp = fopen("../data/user_cart.txt", "w");
  int i;
  for (i = 0; i < user.cartSize; i++) {
    fprintf(fp, "%s,%d\n", user.cart[i].namaBarang, user.cart[i].hargaBarang);
  }
  fclose(fp);
}