#include "DB.h"
#include "VOD.h"
#include "dbController.h"
#include "merch.h"
#include "tiket.h"
#include "userData.h"
#include "util.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

DB _MERCH = {.db = {{111, "Sepatu", 100000, ""},
                    {104, "Topi", 25000, ""},
                    {102, "Jaket", 250000, ""},
                    {167, "Payung", 15000, ""},
                    {107, "Baju", 50000, ""},
                    {108, "Gelas", 25000, ""},
                    {109, "Dakimakura", 200000, ""},
                    {106, "Gelang", 10000, ""},
                    {112, "Kacamata", 30000, ""},
                    {123, "Masker", 5000}},
             .qty = 10};

DB _VOD = {.db =
               {
                   {222, "Radit", 100000, "17-09-2018"},
                   {253, "Github", 100000, "03-05-2020"},
                   {298, "Avengers", 100000, "09-08-2019"},
                   {212, "Ben & Rivo", 100000, "12-25-2020"},
                   {256, "Patungan", 100000, "10-05-2020"},
                   {202, "Spiderman", 100000, "22-05-2012"},
                   {271, "Captain America", 100000, "31-05-2019"},
                   {281, "Hulk", 100000, "04-04-2020"},
                   {221, "Ben & Jefer", 100000, "30-05-2019"},
                   {234, "Ironman", 100000, "30-03-2010"},
               },
           .qty = 10};

DB _TIKET = {.db = {{345, "Valorant Coaching", 250000, "20-05-2023"},
                    {358, "Ilucinati", 350000, "23-08-2022"},
                    {336, "Hip!", 150000, "04-07-2022"},
                    {380, "Ternyata Ini Sebabnya", 350000, "04-11-2022"},
                    {386, "Cerita Cintaku", 350000, "26-07-2022"},
                    {343, "Juru Bicara", 250000, "15-12-2022"},
                    {387, "Ayah Ikhlas Volume 2", 150000, "25-06-2022"},
                    {376, "Personal Branding", 125000, "10-10-2022"},
                    {334, "Bhinneka Tungal Tawa", 200000, "17-08-2022"},
                    {399, "Patraiarki", 150000, "30-10-2022"}},
             .qty = 10};

void init() {
  initDir();
  procDB("daftar_merch.txt", &_MERCH);
  procDB("daftar_vod.txt", &_VOD);
  procDB("daftar_tiket.txt", &_TIKET);
}

int mainMenu() {
  int pilih;
  cls();
  printf("+================================+\n");
  printf("|            Main Menu           |\n");
  printf("+================================+\n");
  printf("|1. Beli Tiket                   |\n"
         "|2. Beli Digital Download        |\n"
         "|3. Beli Merch                   |\n"
         "|4. Tampilkan Shopping Cart      |\n"
         "|0. Keluar                       |\n"
         "+================================+\n"
         "Pilihan: ");
  scanf("%d", &pilih);
  printf("\n");
  return pilih;
}

int main() {
  init();
  bool keepGoing = true;
  readUserFile();
  cls();

  while (keepGoing) {
    printUser();
    switch (mainMenu()) {
    case 1:
      tiket();
      break;
    case 2:
      VOD();
      break;
    case 3:
      merch();
      break;
    case 4:
      printUser();
      printCart(&_USERDATA);
      break;
    case 0:
      keepGoing = false;
      break;
    case 69:
      aboutUs();
    default:
      printf("Pilihan Tidak Valid\n");
      prompt();
      printf("\n");
      break;
    }
  }
}
