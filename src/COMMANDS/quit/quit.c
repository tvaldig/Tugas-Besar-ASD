#include <stdlib.h>
#include "quit.h"

void Quit(boolean isLogin) {
    if (isLogin) {
        char namacommand[100];
        // Save
        printf("Apakah kamu ingin menyimpan data sesi sekarang?\n");
        STARTCOMMAND(false);
        ConvertWordToString(&currentCommand, namacommand);
        if (IsStringEqual(namacommand, "N;")) {
            printf("Kamu keluar dari WayangWave.\nDadah ^_^/\n");
        } else {
            SAVE();
        }
        exit(0);
    }
}