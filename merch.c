#include <stdio.h>

typedef struct
{
    char namaBarang[50];
    int hargaBarang;
} Barang;

void prompt()
{
    printf("\nTekan apa saja untuk melanjutkan...");
    getchar();
}

void cls(void)
{
    system("cls||clear");
    return;
}

int menuMerch()
{
    int merchChoose;
    printf("==============================\n");
    printf("|           Merch            |\n");
    printf("==============================\n");
    printf("1. Top Sale Bulan Ini\n"
           "2. Daftar Barang\n"
           "3. Pesan Barang\n"
           "0. Kembali Ke Menu Utama\n"
           "Pilihan: ");
    scanf("%d", &merchChoose);
    printf("\n");
    cls();
    return merchChoose;
}

void daftar()
{
    int i = 0;
    Barang barang[6];

    FILE *fp = fopen("Daftar_Barang.txt", "r");

    puts("===============================");
    puts("=======| Daftar Barang |=======");
    puts("===============================");

    while (!feof(fp))
    {
        Barang newBarang;
        fscanf(fp, "%[^,],%d\n", &newBarang.namaBarang, &newBarang.hargaBarang);
        barang[i] = newBarang;
        i++;
    }

    printf("\n");
    for (i = 0; i < 6; i++)
    {
        printf("Barang ke-%d\n", i + 1);
        printf("Nama Barang: %s\n", barang[i].namaBarang);
        printf("Harga Barang: Rp%d\n", barang[i].hargaBarang);
        printf("\n");
    }
    fclose(fp);
    system("pause");
    cls();
}

int main()
{
    while (1)
    {

        switch (menuMerch())
        {
        // case 1:
        //   topSales();
        //   break;
        case 2:
            daftar();
            break;
        // case 3:
        //   pesan();
        //   break;
        case 0:
            break;
        default:
            break;
        }
    }

    return 0;
}