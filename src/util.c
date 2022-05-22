#include "util.h"
#include "pembayaran.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prompt() {
  if (PLATFORM_NAME == "win") {
    system("pause");
  } else {
    printf("Tekan Enter Untuk Melanjutkan...");
    getchar();
  }
}

void cls() {
  if (PLATFORM_NAME == "win") {
    system("cls");
  } else {
    system("clear");
  }
}

Node *createNode(Barang item) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = item;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// TODO bikin fungsi ini nerima kategori apa yang mau dibandingkan
void insertToTree(Node **root, Barang item, int sortCategory) {
  char prevName[100], currName[100];
  strcpy(prevName, item.namaBarang);
  strcpy(currName, item.namaBarang);

  int compare;
  if (*root == NULL) {
    *root = createNode(item);
  } else {
    switch (sortCategory) {
    case 0:
      compare = item.id < (*root)->data.id ? 1 : 0;
      break;
    case 1:
      compare = strcmp(item.namaBarang, (*root)->data.namaBarang) < 0 ? 1 : 0;
      break;
    case 2:
      compare = item.hargaBarang < (*root)->data.hargaBarang ? 1 : 0;
      break;
    default:
      compare = item.id < (*root)->data.id ? 1 : 0;
      break;
    }
    if (compare) {
      insertToTree(&(*root)->left, item, sortCategory);
    } else {
      insertToTree(&(*root)->right, item, sortCategory);
    }
  }
}

void clearTree(Node **root) {
  if (*root != NULL) {
    clearTree(&(*root)->left);
    clearTree(&(*root)->right);
    free(*root);
    *root = NULL;
  }
}

// TODO bikin fungsi ini nerima kategori apa yang mau dibandingkan
void createTreeFromDB(Node **root, DB *database, int sortCategory) {
  for (int i = 0; i < database->qty; i++) {
    insertToTree(root, database->db[i], sortCategory);
  }
}

void tree_Inorder(Node *root, Barang arr[], int *qty) {
  if (root != NULL) {
    tree_Inorder(root->left, arr, qty);
    arr[*qty] = root->data;
    (*qty)++;
    tree_Inorder(root->right, arr, qty);
  }
}

void listBarang(DB *database, int category) {
  int iterator;
  int start = 0;
  int user;
  Barang barang[100];
  int jumlah = 0;
  int sortChoice = 0;
  Node *treeRoot;
  createTreeFromDB(&treeRoot, database, sortChoice);
  tree_Inorder(treeRoot, barang, &jumlah);

  while (1) {
    if (category == 1) {
      puts("+======+=================================+=============+");
      puts("|  ID  |           Nama Barang           |    Harga    |");
      puts("|======+=================================+=============|");

      for (iterator = 0; iterator < 5; iterator++) {
        if ((iterator + start) >= jumlah) {
          break;
        }
        printf("| %-3d  | %-31s | Rp%-9d |\n", barang[iterator + start].id,
               barang[iterator + start].namaBarang,
               barang[iterator + start].hargaBarang);
      }

      puts("+======+=================================+=============+");
      puts("|1. Halaman Sebelumnya                                 |");
      puts("|2. Halaman Selanjutnya                                |");
      puts("|3. Pesan Barang                                       |");
      puts("|4. Urutkan Data                                       |");
      puts("|0. Kembali                                            |");
      puts("+======================================================+");

    } else if (category == 2 || category == 3) {
      puts("+======+=================================+=============+==========="
           "=="
           "=+");
      puts("|  ID  |           Nama Barang           |    Harga    |    "
           "Tanggal  "
           " |");
      puts("+======+=================================+=============+==========="
           "=="
           "=+");
      for (iterator = 0; iterator < 5; iterator++) {
        if ((iterator + start) >= jumlah) {
          break;
        }
        printf("| %-3d  | %-31s | Rp%-9d |  %-12s|\n",
               barang[iterator + start].id, barang[iterator + start].namaBarang,
               barang[iterator + start].hargaBarang,
               barang[iterator + start].tanggal);
      }
      printf(
          "+======+=================================+=============+==========="
          "===+\n");
      puts("|1. Halaman Sebelumnya                                             "
           "   |");
      puts("|2. Halaman Selanjutnya                                            "
           "   |");
      puts("|3. Pesan Barang                                                   "
           "   |");
      puts("|4. Urutkan data                                                   "
           "   |");
      puts("|0. Kembali                                                        "
           "   |");
      printf("+================================================================"
             "=====+\n");
    }
    printf("Pilihan: ");
    scanf("%d%*c", &user);

    switch (user) {
    case 1:
      start -= 5;
      if (start < 0) {
        start = 0;
      }
      break;
    case 2:
      start += 5;
      if (start >= jumlah) {
        start = jumlah - 5;
      }
      break;
    case 3:
      promptSearch(*database);
      break;
    case 4:
      printf("Sorting berdasarkan: ");
      printf("0) ID barang\n");
      printf("1) Nama barang\n");
      printf("2) Harga barang\n");
      printf("Pilihan:");
      scanf("%d%*c", &sortChoice);
      clearTree(&treeRoot);
      jumlah = 0;
      createTreeFromDB(&treeRoot, database, sortChoice);
      tree_Inorder(treeRoot, barang, &jumlah);
      break;
    case 0:
      return;
      break;
    }
    clearTree(&treeRoot);
    cls();
  }
}