#include "util.h"
#include "pembayaran.h"
#include <ctype.h>
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

void stringToLower(char *str) {
  int i;
  for (i = 0; i < strlen(str); i++) {
    str[i] = tolower(str[i]);
  }
}

void insertToTree(Node **root, Barang item, int sortCategory) {
  char prevName[100], currName[100];

  int compare;
  if (*root == NULL) {
    *root = createNode(item);
  } else {
    switch (sortCategory) {
    case 1:
      compare = item.id < (*root)->data.id ? 1 : 0;
      break;
    case 2:
      strcpy(prevName, item.namaBarang);
      strcpy(currName, (*root)->data.namaBarang);
      stringToLower(prevName);
      stringToLower(currName);
      compare = strcmp(prevName, currName) < 0 ? 1 : 0;
      break;
    case 3:
      compare = item.hargaBarang < (*root)->data.hargaBarang ? 1 : 0;
      break;
    case 4:
      return;
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

void createTreeFromDB(Node **root, Barang db[], int qty, int sortCategory) {
  for (int i = 0; i < qty; i++) {
    if (strcmp(db[i].namaBarang, "") == 0) {
      break;
    }
    insertToTree(root, db[i], sortCategory);
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

void printTabelBarang(Barang barang[], int jumlah, int category, int *start) {
  int iterator = 0;
  if (category == 1) {
    puts("+======+=================================+=============+");
    puts("|  ID  |           Nama Barang           |    Harga    |");
    puts("+======+=================================+=============+");

    for (iterator = 0; iterator < 5; iterator++) {
      if ((iterator + (*start)) >= jumlah) {
        break;
      }
      printf("| %-3d  | %-31s | Rp%-9d |\n", barang[iterator + (*start)].id,
             barang[iterator + (*start)].namaBarang,
             barang[iterator + (*start)].hargaBarang);
    }
    puts("+======+=================================+=============+");
  } else if (category == 2 || category == 3) {
    puts("+======+=================================+=============+============="
         "=+");
    puts("|  ID  |           Nama Barang           |    Harga    |    "
         "Tanggal  "
         " |");
    puts("+======+=================================+=============+============="
         "=+");
    for (iterator = 0; iterator < 5; iterator++) {
      if ((iterator + (*start)) >= jumlah) {
        break;
      }
      printf("| %-3d  | %-31s | Rp%-9d |  %-12s|\n",
             barang[iterator + (*start)].id,
             barang[iterator + (*start)].namaBarang,
             barang[iterator + (*start)].hargaBarang,
             barang[iterator + (*start)].tanggal);
    }
    puts("+======+=================================+=============+============="
         "=+");
  }
}

void aboutUs() {
  cls();
  puts("+============================================+");
  puts("|               The Creator                  |");
  puts("+============================================+");
  puts("| 1. Rivo Juicer Wowor        (00000059635)  |");
  puts("| 2. Christian Ivan Wibowo    (00000058450)  |");
  puts("| 3. Jefer Setiawan           (00000059297)  |");
  puts("| 4. Areta Escalonia Candra   (00000057872)  |");
  puts("+============================================+");
  printf("\n");
  prompt();
  cls();
  return;
}

void listTrending(DB *database, int category) {
  int iterator, user;
  int start = 0;
  int jumlah = 0;
  int sortChoice = 0;
  Barang barang[MAX_TRENDING];
  Node *treeRoot = NULL;
  createTreeFromDB(&treeRoot, database->trending, MAX_TRENDING, sortChoice);
  tree_Inorder(treeRoot, barang, &jumlah);

  while (1) {
    printTabelBarang(barang, jumlah, category, &start);
    printf("\n+==========================+\n");
    puts("|1. Pesan Barang           |");
    puts("|2. Urutkan data           |");
    puts("|0. Kembali                |");
    printf("+==========================+\n");
    printf("Pilihan: ");
    scanf("%d%*c", &user);

    switch (user) {
    case 1:
      promptSearch(*database);
      break;
    case 2:
      printf("+==========================+\n");
      printf("|Sorting berdasarkan:      |\n");
      printf("|1) ID barang              |\n");
      printf("|2) Nama barang            |\n");
      printf("|3) Harga barang           |\n");
      printf("|0) Kembali                |\n");
      printf("+==========================+\n");
      printf("Pilihan: ");
      scanf("%d%*c", &sortChoice);
      if (sortChoice < 0) {
        break;
      } else if (sortChoice > 3 || sortChoice < 0) {
        printf("Pilihan tidak ditemukan\n");
        prompt();
        break;
      }
      clearTree(&treeRoot);
      jumlah = 0;
      createTreeFromDB(&treeRoot, database->trending, MAX_TRENDING, sortChoice);
      tree_Inorder(treeRoot, barang, &jumlah);
      break;
    case 0:
      return;
      break;
    default:
      printf("Pilihan tidak ditemukan\n");
      break;
    }
    clearTree(&treeRoot);
    cls();
  }
}

void listBarang(DB *database, int category) {
  int iterator, user;
  int start = 0;
  int jumlah = 0;
  int sortChoice = 0;
  Barang barang[100];
  Node *treeRoot = NULL;
  createTreeFromDB(&treeRoot, database->db, database->qty, sortChoice);
  tree_Inorder(treeRoot, barang, &jumlah);

  while (1) {
    printTabelBarang(barang, jumlah, category, &start);
    printf("\n+==========================+\n");
    puts("|1. Halaman Sebelumnya     |");
    puts("|2. Halaman Selanjutnya    |");
    puts("|3. Pesan Barang           |");
    puts("|4. Urutkan data           |");
    puts("|0. Kembali                |");
    printf("+==========================+\n");
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
      printf("+==========================+\n");
      printf("|Sorting berdasarkan:      |\n");
      printf("|1) ID barang              |\n");
      printf("|2) Nama barang            |\n");
      printf("|3) Harga barang           |\n");
      printf("|0) Kembali                |\n");
      printf("+==========================+\n");
      printf("Pilihan: ");
      scanf("%d%*c", &sortChoice);
      if (sortChoice < 0) {
        break;
      } else if (sortChoice > 3 || sortChoice < 0) {
        printf("Pilihan tidak ditemukan\n");
        prompt();
        break;
      }
      clearTree(&treeRoot);
      jumlah = 0;
      createTreeFromDB(&treeRoot, database->db, database->qty, sortChoice);
      tree_Inorder(treeRoot, barang, &jumlah);
      break;
    case 0:
      return;
      break;
    default:
      printf("Pilihan tidak ditemukan\n");
      break;
    }
    clearTree(&treeRoot);
    cls();
  }
}