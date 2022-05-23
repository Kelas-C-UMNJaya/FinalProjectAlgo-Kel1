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

DB _MERCH = {
    .db =
        {
            {111, "Sepatu", 100000, ""},     {104, "Topi", 25000, ""},
            {102, "Jaket", 250000, ""},      {167, "Payung", 15000, ""},
            {107, "Baju", 50000, ""},        {108, "Gelas", 25000, ""},
            {169, "Dakimakura", 200000, ""}, {106, "Gelang", 10000, ""},
            {112, "Kacamata", 30000, ""},    {123, "Masker", 5000, ""},
            {120, "Tas", 150000, ""},        {100, "Jam", 25000, ""},
            {150, "Pin", 5000, ""},          {149, "Tumbler", 20000, ""},
            {190, "Kipas", 10000, ""},       {173, "USB", 15000, ""},
            {143, "Casing HP", 10000, ""},   {109, "Stiker", 5000, ""},
            {199, "Pena", 5000, ""},         {162, "Power Bank", 55000, ""},
        },
    .qty = 20};

DB _VOD = {.db =
               {
                   {222, "Triple Trouble", 499000, "17-09-2018"},
                   {253, "Github", 135000, "03-05-2020"},
                   {298, "Re-Write", 150000, "09-08-2019"},
                   {212, "Konser Tulus 2020", 140000, "12-25-2020"},
                   {256, "Patungan", 90000, "10-05-2020"},
                   {202, "Close The Door", 145000, "22-05-2012"},
                   {271, "Summer Sonic", 75000, "31-05-2019"},
                   {281, "Fuji Rock Festival", 85000, "04-04-2020"},
                   {221, "Free Code Camp", 90000, "30-05-2019"},
                   {234, "Justin Bieber Justice Rour", 125000, "30-03-2010"},
                   {251, "Djakarta Warehouse Project", 135000, "11-08-2018"},
                   {274, "Hammersonic Festival", 145000, "16-07-2017"},
                   {282, "Jazz Gunung Bromo 2015", 115000, "20-01-2015"},
                   {254, "Gue Buta Bukan Bego", 110000, "01-01-2022"},
                   {233, "Dar Der Dor!", 100000, "17-02-2013"},
                   {278, "Pandemi VS Komedi", 100000, "21-03-2011"},
                   {292, "Wedding Proposal", 150000, "05-05-2020"},
                   {200, "Live Konser Fariz RM", 100000, "11-11-2011"},
                   {299, "Live Konser Ari Lasso", 100000, "21-12-2017"},
                   {282, "Stand Up Comedy Pandji", 100000, "01-10-2016"},
               },
           .qty = 20};

DB _TIKET = {
    .db = {{345, "Valorant Coaching", 250000, "20-05-2023"},
           {358, "Ilucinati", 350000, "23-08-2022"},
           {336, "Hip!", 150000, "04-07-2022"},
           {380, "Ternyata Ini Sebabnya", 350000, "04-11-2022"},
           {386, "Cerita Cintaku", 350000, "26-07-2022"},
           {343, "Juru Bicara", 250000, "15-12-2022"},
           {387, "Ayah Ikhlas Volume 2", 150000, "25-06-2022"},
           {376, "Personal Branding", 125000, "10-10-2022"},
           {311, "Bhinneka Tunggal Tawa", 200000, "17-08-2022"},
           {334, "Java Jazz 2022", 200000, "17-08-2022"},
           {308, "Konser Tulus 2022", 200000, "17-08-2022"},
           {333, "Java Jazz Festival", 575000, "29-05-2022"},
           {367, "Rossa 25 Shining Years Concert", 350000, "27-05-2022"},
           {346, "Prambanan Jazz Festival (PJF)", 650000, "02-07-2022"},
           {385, "Louis Tomlinson", 550000, "10-07-2022"},
           {324, "Jazz Gunung Bromo 2022", 400000, "23-08-2022"},
           {301, "Soundrenaline", 250000, "10-10-2022"},
           {302, "Synchronize Fest", 150000, "09-08-2022"},
           {399, "Patraiarki", 150000, "30-10-2022"},
           {323, "Theater: JKT48 2023", 450000, "04-01-2023"}},
    .qty = 20};

void init() {
  initDir();
  procDB("daftar_merch.txt", &_MERCH);
  procDB("daftar_vod.txt", &_VOD);
  procDB("daftar_tiket.txt", &_TIKET);
}

int mainMenu() {
  int pilih;
  printf("+================================+\n");
  printf("|            Main Menu           |\n");
  printf("+================================+\n");
  printf("|1. Beli Tiket                   |\n"
         "|2. Beli Digital Download        |\n"
         "|3. Beli Merch                   |\n"
         "|4. Tampilkan Shopping Cart      |\n"
         "|5. Ubah Data User               |\n"
         "|0. Keluar                       |\n"
         "+================================+\n"
         "Pilihan: ");
  scanf("%d%*c", &pilih);
  printf("\n");
  return pilih;
}

void splashScreen() {
  puts("+===============================================================+");
  puts("|        @@@@@ j@@    ,gg,    ]@@   g@@` @@@@@@P $@@@@P         |");
  puts("|        --]@@ ]@@ g$'    *$g ]@@ g@@'   @@[---  ]@@--          |");
  puts("|          ]@@ ]@@ $  g$$g@$$ ]@@@@P     @@@@@@  ]@@            |");
  puts("|          ]@@ ]@@ lg '**''$$ ]@@'@@@    @@['''  ]@@            |");
  puts("|          ]@@ ]@@  '%ggggP'  ]@@  *@@@  @@@BBBP ]@@            |");
  puts("+===============================================================+");
  printf("\n");
}

int main() {
  cls();
  init();
  bool keepGoing = true;
  readUserFile();
  cls();

  while (keepGoing) {
    splashScreen();
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
      // cls();
      // printUser();
      printCart(&_USERDATA);
      break;
    case 5:
      menuGantiData();
      break;
    case 0:
      keepGoing = false;
      break;
    case 69:
      aboutUs();
      break;
    default:
      printf("Pilihan Tidak Valid\n");
      prompt();
      printf("\n");
      break;
    }
  }
}
