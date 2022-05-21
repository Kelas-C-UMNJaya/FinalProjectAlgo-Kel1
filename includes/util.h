
#include "DataTypes.h"
#if defined(_WIN32) || defined(_WIN64)
#  include <conio.h>
#  include <windows.h>
#  define mkdire(dir, mode) !(CreateDirectory(dir, NULL))
#  define PLATFORM_NAME "win"
#  define CLEAR "cls"
#elif defined(__linux__)
#  define CLEAR "clear"
#  define mkdire(dir, mode) mkdir(dir, mode)
#  define PLATFORM_NAME "linux"
#endif

void prompt();
void cls();
void listBarang(Barang barang[], int jumlah, int category);
