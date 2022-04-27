#include "../includes/system.h"
#include <stdio.h>
#include <stdlib.h>

void prompt() {
  if (PLATFORM_NAME == "win") {
    system("pause");
  } else {
    printf("Press any key to continue...");
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