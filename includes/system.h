#if defined(_WIN32) || defined(_WIN64)
#  include <conio.h>
#  define CLEAR "cls"
#  define PLATFORM_NAME "win"
#elif defined(__linux__)
#  define CLEAR "clear"
#  define PLATFORM_NAME "linux"
#endif

void prompt();
void cls();