#include <stdio.h>
#include "help.h"


void help(boolean login) {
    if (login) {
        printf("\n"
        "====================================================[ Menu Help WayangWave ]===================================================\n"
        "1. LIST     -> Untuk menampilkan daftar lagu, playlist\n"
        "2. PLAY     -> Untuk memulai suatu lagu\n"
        "3. QUEUE    -> Untuk memanipulasi queue lagu\n"
        "4. SONG     -> Untuk menavigasi lagu yang ada pada queue lagu saat ini\n"
        "5. PLAYLIST -> Untuk membuat playlist baru dan ditambahkan pada daftar playlist pengguna\n"
        "6. STATUS   -> Untuk menampilkan lagu yang sedang dimainkan beserta Queue song yang ada dan dari playlist mana lagu itu diputar\n"
        "7. SAVE     -> untuk menyimpan state aplikasi terbaru ke dalam suatu file\n"
        "8. QUIT     -> Untuk keluar dari sesi\n\n"
        );
    } else {
        printf("\n"
        "==================[ Menu Help WayangWave ]==================\n"
        "1. START -> Untuk masuk sesi baru\n"
        "2. LOAD  -> Untuk memulai sesi berdasarkan file konfigurasi\n\n"
        );
    }
}