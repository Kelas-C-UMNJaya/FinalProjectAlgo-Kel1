#include "pembayaran.h"
#include "userData.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>

void promptSearch(Barang DB[], int qty) {
  int id, isFound;
  printf("Masukkan ID barang: ");
  scanf("%d%*c", &id);
  Barang barangFind = searchBarang(id, DB, qty, &isFound);
  if (!isFound) {
    printf("Barang tidak ditemukan\n");
    prompt();
    return;
  }
  printf("Nama barang: %s\n", barangFind.namaBarang);
  printf("Harga barang: Rp%d\n", barangFind.hargaBarang);
  printf("Tambahkan ke keranjang? (y/n) ");
  char c;
  scanf("%c%*c", &c);
  if (c == 'y') {
    addToCart(&_USERDATA, barangFind);
    printf("Barang telah berhasil ditambahkan ke keranjang!\n");
    prompt();
  }
}

Barang searchBarang(int id, Barang barang[], int jumlah, int *isFound) {
  int low = 0;
  int high = jumlah - 1;
  int mid = (low + high) / 2;
  while (low <= high) {
    if (barang[mid].id == id) {
      *isFound = 1;
      return barang[mid];
    } else if (barang[mid].id > id) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
    mid = (low + high) / 2;
  }
  *isFound = 0;
}

void bayar(UserData *user, unsigned long total) {
  printf("Total pembayaran: Rp%lu\n", total);
  while ((long)user->saldo - (long)total < 0) {
    printf("Saldo anda tidak mencukupi\n");
    printf("Ingin Top Up? (y/n): ");
    char c;
    scanf("%c%*c", &c);
    if (c == 'y') {
      topup();
    } else {
      return;
    }
  }
  dedup(total);
  printf("Pembayaran Berhasil!\n");
  printf("Saldo anda saat ini: %lu\n", user->saldo);
  printf("Terima Kasih Telah Berbelanja!\n");
  prompt();
  printf("\n");
}