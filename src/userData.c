#include "userData.h"
#include "pembayaran.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
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
  printf("|Halo, %-25s |\n", _USERDATA.nama);
  printf("|Saldo     : %-19lu |\n", _USERDATA.saldo);
  printf("|Cart Size : %-19d |\n", _USERDATA.cartSize);
  printf("+================================+\n");
  printf("\n");
}

void addToCart(UserData *user, Barang data) {
  Cart *newItem = (Cart *)malloc(sizeof(Cart));
  newItem->data = data;
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
  if (user->cartFront == NULL) {
    user->cartBack = NULL;
  }
  user->cartSize--;
}

void removeItemFromCart(UserData *user, int id) {
  Cart *prev = NULL;
  Cart *curr = user->cartFront;
  while (curr != NULL) {
    if (curr->data.id == id) {
      if (prev == NULL) {
        removeFrontCart(user);
      } else {
        prev->next = curr->next;
        free(curr);
        user->cartSize--;
      }
      return;
    }
    prev = curr;
    curr = curr->next;
  }
}

void clearCart(UserData *user) {
  while (user->cartFront != NULL) {
    removeFrontCart(user);
  }
  user->cartBack = NULL;
  user->cartSize = 0;
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
      bayar(&_USERDATA, &total);
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
  FILE *fp = fopen("./data/user/user_data.txt", "r");
  if (fp == NULL) {
    printf("File user data tidak ditemukan, membuat file...\n");
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
  FILE *fp = fopen("data/user/user_data.txt", "w");
  fprintf(fp, "%s,%lu\n", data.nama, data.saldo);
  writeUserCart(data);
  fclose(fp);
}

void readUserCart(UserData *user) {
  FILE *fpOut = fopen("data/user/user_cart.txt", "r");
  char buffer[100];
  if (fpOut == NULL) {
    printf("File user cart tidak ditemukan, membuat file...\n");
    writeUserCart(*user);
    exit(1);
  }
  int i = 0;
  int size;
  if (fseek(fpOut, 0, SEEK_END) != 0) {
    printf("Error!\n");
    exit(1);
  } else if ((size = ftell(fpOut)) == 0) {
    printf("Cart kosong\n");

    return;
  }
  fseek(fpOut, 0, SEEK_SET);
  Barang newBarang;
  int scanResult;
  // fgets(buffer, 100, fpOut);
  // printf("%s\n", buffer);
  do {
    scanResult =
        fscanf(fpOut, "%d,%[^,],%d,%[^\n]\n", &newBarang.id,
               newBarang.namaBarang, &newBarang.hargaBarang, newBarang.tanggal);
    if (scanResult == 3 || scanResult == 4) {
      if (scanResult == 3) {
        strcpy(newBarang.tanggal, "");
      }
      addToCart(user, newBarang);
      i++;
    }
  } while (scanResult != EOF || scanResult > 3);
  user->cartSize = i;
  fclose(fpOut);
}

void writeUserCart(UserData user) {
  FILE *fp = fopen("./data/user/user_cart.txt", "w");
  int i;
  Cart *temp = user.cartFront;
  while (temp != NULL) {
    fprintf(fp, "%d,%s,%d,%s\n", temp->data.id, temp->data.namaBarang,
            temp->data.hargaBarang, temp->data.tanggal);
    temp = temp->next;
  }
  fclose(fp);
}