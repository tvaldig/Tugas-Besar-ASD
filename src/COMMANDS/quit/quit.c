#include <stdlib.h>
#include "quit.h"

void Quit(boolean isLogin) {
    if (!isLogin) {
        char namacommand[100];
        // Save
        printf("Apakah kamu ingin menyimpan data sesi sekarang? ");
        STARTCOMMAND(false);
        ConvertWordToString(&currentCommand, namacommand);
        while(!(IsStringEqual(namacommand, "N;") || IsStringEqual(namacommand, "Y;"))){
            unknownCommand();
            printf("Apakah kamu ingin menyimpan data sesi sekarang? ");
            STARTCOMMAND(false);
            ConvertWordToString(&currentCommand, namacommand);
        }
        if (IsStringEqual(namacommand, "N;")) {
            printf("Kamu keluar dari WayangWave.\nDadah ^_^/\n");
        } else if (IsStringEqual(namacommand, "Y;")) {
            printf("Masukkan nama file!\n");
            printf("* Perhatikan kesalahan penulisan dapat mengakibatkan file tidak tersimpan, program akan otomatis tidak menyimpan file apabila salah menulis nama file!\n");
            printf("** Contoh penulisan yang benar : \"test.txt;\"\n\n");
            SAVE();
        }
        exit(0);
    } else {
        printf("Silahkan logout terlebih dahulu!\n");
    }
}