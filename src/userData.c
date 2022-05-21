#include "userData.h"
#include "pembayaran.h"
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
  initCart(&newUser);
  return newUser;
}

void initCart(UserData *user) {
  user->cartFront = NULL;
  user->cartBack = NULL;
  user->cartSize = 0;
}

void printUser() {
  printf("+================================+\n");
  printf("|Nama      :%-20s |\n", _USERDATA.nama);
  printf("|Saldo     :%-20lu |\n", _USERDATA.saldo);
  printf("|Cart Size :%-20d |\n", _USERDATA.cartSize);
  printf("+================================+\n");
}

void addToCart(UserData *user, Barang data) {
  Cart *newItem = (Cart *)malloc(sizeof(Cart));
  newItem->data = data;
  newItem->next = NULL;
  // while ((long)user->saldo - data.hargaBarang < 0) {
  //   printf("Saldo anda tidak mencukupi\n");
  //   printf("Ingin Top Up? (y/n): ");
  //   char c;
  //   scanf("%c%*c", &c);
  //   if (c == 'y') {
  //     topup();
  //   } else {
  //     return;
  //   }
  // }
  // dedup(data.hargaBarang);
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

unsigned long totalCart(UserData *user) {
  unsigned long total = 0;
  Cart *temp = user->cartFront;
  while (temp != NULL) {
    total += temp->data.hargaBarang;
    temp = temp->next;
  }
  // printf("Total: Rp%lu\n", total);
  return total;
}

void printCart(UserData *user) {
  int pilihan;
  int keepgoing = 1;
  unsigned long total = totalCart(user);

  Cart *temp = user->cartFront;
  // TODO cantikin printnya
  while (keepgoing) {
    printf("+================================+\n");
    printf("|          Shopping Cart         |\n");
    printf("+================================+\n");
    while (temp != NULL) {
      printf("|ID     : %-22d |\n", temp->data.id);
      printf("|Nama   : %-22s |\n", temp->data.namaBarang);
      printf("|Harga  : Rp%-20d |\n", temp->data.hargaBarang);
      printf("+================================+\n");
      temp = temp->next;
    }
    printf("|Total  : Rp%-20lu |\n", total);
    printf("+================================+\n");
    printf("|1. Bayar                        |\n");
    printf("|0. Kembali                      |\n");
    printf("+================================+\n");
    printf("Pilihan: ");
    scanf("%d%*c", &pilihan);

    switch (pilihan) {
    case 1:
      bayar(&_USERDATA, total);
      break;
    case 0:
      keepgoing = 0;
      break;
    default:
      printf("Pilihan Tidak Valid\n");
      break;
    }
  }
}

void topup() {
  printf("Masukkan jumlah top up: ");
  unsigned long topUp;
  scanf("%lu%*c", &topUp);
  _USERDATA.saldo += topUp;
}
unsigned long dedup(unsigned long saldo) {
  _USERDATA.saldo -= saldo;
  return _USERDATA.saldo;
}

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
  initCart(&user);
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
    char buffer[100];
    fgets(buffer, 100, fp);
    if (strcmp(buffer, "") == 0) {
      printf("%s", buffer);
      printf("data is empty\n");
      break;
    }
    // fscanf(fp, "%[^,],%d\n", newBarang.namaBarang, &newBarang.hargaBarang);
    sscanf(buffer, "%[^\n],%d\n", newBarang.namaBarang, &newBarang.hargaBarang);
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