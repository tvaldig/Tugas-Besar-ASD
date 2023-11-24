#include <stdio.h>
#include "help.h"


void help(boolean login) {
    if (login) {
        printf("\n"
        "====================================================[ Menu Help WayangWave ]===================================================\n"
        "1.  LOGIN    -> Untuk masuk ke user tertentu\n"
        "2.  LOGOUT   -> Untuk keluar dari user saat ini\n"
        "3.  LIST     -> Untuk menampilkan daftar lagu, playlist\n"
        "4.  PLAY     -> Untuk memulai suatu lagu\n"
        "5.  QUEUE    -> Untuk memanipulasi queue lagu\n"
        "6.  SONG     -> Untuk menavigasi lagu yang ada pada queue lagu saat ini\n"
        "7.  PLAYLIST -> Untuk membuat playlist baru dan ditambahkan pada daftar playlist pengguna\n"
        "8.  STATUS   -> Untuk menampilkan lagu yang sedang dimainkan beserta Queue song yang ada dan dari playlist mana lagu itu diputar\n"
        "9.  SAVE     -> Untuk menyimpan state aplikasi terbaru ke dalam suatu file\n"
        "10. ENHANCE  -> Untuk memberikan rekomendasi lagu untuk ditambahkan ke dalam playlist pengguna\n"
        "11. RADIO    -> Untuk memberikan rekomendasi lagu untuk dimainkan berdasarkan suatu lagu\n"
        "12. QUIT     -> Untuk keluar dari sesi\n\n"
        );
    } else {
        printf("\n"
        "==================[ Menu Help WayangWave ]==================\n"
        "1. START -> Untuk masuk sesi baru\n"
        "2. LOAD  -> Untuk memulai sesi berdasarkan file konfigurasi\n\n"
        );
    }
}