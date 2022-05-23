# Proyek Akhir IF232 - Algoritma dan Struktur Data

## Kelompok 1

- Rivo Juicer Wowor (00000059635)
- Christian Ivan Wibowo (00000058450)
- Basilius Jethro (00000057833)
- Jefer Setiawan (00000059297)
- Areta Escalonia Candra(00000057872)

# Cara Install dan Pemakaiannya

Tinggal jalankan `tiket.exe` (untuk Windows) atau `tiket` (untuk Linux) di dalam folder `bin/`.

# Cara compile

## Linux

Pastikan anda mempunyai beberapa hal berikut:

- CMake
- GCC
- GNU Make
- Ninja

Dalam Ubuntu, anda bisa menjalankan command berikut

```
sudo apt update && sudo apt upgrade
sudo apt install cmake ninja build-essential
```

Setelah semua terinstall, clone repository ini dan buatlah suatu direktori
dengan nama `build`. Masuk kedalamnya dan jalankan command berikut:

```
cmake -G Ninja ..
cmake --build .
./tiket
```

## Windows

Pastikan anda mempunyai beberapa hal berikut:

- CMake
- Code:Blocks (dengan MinGW)

> **Catatan**
> Anda perlu menambahkan folder `<Folder Instalasi CodeBlocks>\MinGW\bin` ke
> dalam environment variablesnya untuk bisa dijalankan.
> [Tutorial berkaitan](https://stackoverflow.com/questions/15024419/cmake-for-codeblocks-under-windows#:~:text=for%20me%20following,open%20project.cbp)

Setelah semua terinstall, clone repository ini dan buatlah suatu direktori
dengan nama `build`. Masuk kedalamnya dan jalankan command berikut:

```
cmake -G "CodeBlocks - MinGW Makefiles" ..
```

Kemudian bukalah file `ProjectAkhirAlgo-Group1.cbp` menggunakan CodeBlocks.
Lalu [ubah Build Target](https://i.imgur.com/UN0wdYd.png) yang semula dari `all`
menjadi `main` kemudian klik Build & Run.
