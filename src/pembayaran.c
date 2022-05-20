#include "userData.h"
#include <stdio.h>
#include <stdlib.h>

// Create a function that would search barang from database
// using id as a key, and return the barang if found
// with binary search
Barang searchBarang(int id, Barang barang[], int jumlah) {
  int low = 0;
  int high = jumlah - 1;
  int mid = (low + high) / 2;
  while (low <= high) {
    if (barang[mid].id == id) {
      return barang[mid];
    } else if (barang[mid].id > id) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
    mid = (low + high) / 2;
  }
  return barang[mid];
}

int bayar() {}