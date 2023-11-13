#include <stdio.h>
#include <stdlib.h>
#include "quit.h"
#include "./../ADT/MesinKarakter/mesinkarakter.h"
#include "./../ADT/MesinKarakter/mesinkarakter.c"
#include "./../boolean.h"

void Quit(boolean isLogin) {
    if (isLogin) {
        // Save
        printf("Apakah kamu ingin menyimpan data sesi sekarang? ");
        START();
        if (currentChar == 'N;') {
            printf("Kamu keluar dari WayangWave.\nDadah ^_^/\n");
        } else {
            // Memanggil Save
        }
        exit(0);
    }
}