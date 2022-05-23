#include "pembayaran.h"
#include "userData.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>

Barang searchBarang(Node *root, int id, int *isFound) {
  if (root == NULL) {
    *isFound = 0;
    return (Barang){0, "", 0, ""};
  }
  if (root->data.id == id) {
    *isFound = 1;
    return root->data;
  } else if (root->data.id > id) {
    return searchBarang(root->left, id, isFound);
  } else {
    return searchBarang(root->right, id, isFound);
  }
}
void promptSearch(DB database) {
  int id, isFound;
  printf("Masukkan ID barang: ");
  scanf("%d%*c", &id);
  Barang barangFind = searchBarang(database.binaryTree, id, &isFound);
  if (!isFound) {
    printf("\n");
    printf("+============================================+\n");
    printf("|           Barang tidak ditemukan           |\n");
    printf("+============================================+\n");
    printf("\n");
    prompt();
    return;
  }
  printf("\n");
  printf("+============================================+\n");
  printf("| Nama barang  : %-28s|\n", barangFind.namaBarang);
  printf("| Harga barang : Rp%-26d|\n", barangFind.hargaBarang);
  printf("+============================================+\n");
  printf("Tambahkan ke keranjang? (y/n) ");

  char c;
  scanf("%c%*c", &c);
  if (c == 'y') {
    addToCart(&_USERDATA, barangFind);
    writeUserCart(_USERDATA);
    printf("\n");
    printf("+============================================+\n");
    printf("|   Barang telah ditambahkan ke keranjang!   |\n");
    printf("+============================================+\n");
    printf("\n");
    prompt();
  }
}

// Barang searchBarang(int id, Barang barang[], int jumlah, int *isFound) {
//   int low = 0;
//   int high = jumlah - 1;
//   int mid = (low + high) / 2;
//   while (low <= high) {
//     if (barang[mid].id == id) {
//       *isFound = 1;
//       return barang[mid];
//     } else if (barang[mid].id > id) {
//       high = mid - 1;
//     } else {
//       low = mid + 1;
//     }
//     mid = (low + high) / 2;
//   }
//   *isFound = 0;
// }

void bayar(UserData *user, unsigned long *total) {
  printf("Total pembayaran: Rp%lu\n", *total);
  while ((long)user->saldo - (long)(*total) < 0) {
    printf("Saldo anda tidak mencukupi\n");
    printf("Saldo anda saat ini: Rp%lu\n", user->saldo);
    printf("Ingin Top Up? (y/n): ");
    char c;
    scanf("%c%*c", &c);
    if (c == 'y') {
      topup();
    } else {
      return;
    }
  }
  dedup(*total);
  nota(&_USERDATA);
  clearCart(user);
  printf("\n");
  printf("Pembayaran Berhasil!\n");
  printf("Saldo anda saat ini: %lu\n", user->saldo);
  // printf("Terima Kasih Telah Berbelanja!\n");
  // prompt();
  
  printf("\n");
}