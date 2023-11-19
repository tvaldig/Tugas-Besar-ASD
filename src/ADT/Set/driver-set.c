#include "set.h"
#include <stdio.h>
#include "../MesinKata/mesinkata.h"


int main(){
    Set driver;

    CreateEmptySet(&driver); // Menginisialisasi Set Kosong

    printf("\nUntuk menghentikan test driver, masukkan input \"-999\" pada input ID Lagu!\n\n");
    printf("Masukkan nama lagu: ");
    STARTCOMMAND(false);

    while(!(IsStringEqual(currentCommand.TabWord, "-999"))){
        InsertSetLagu(&driver, 1, 1, currentCommand);
        printf("\nISI SET SAAT INI\n");
        PrintSet(driver);

        printf("\nUntuk menghentikan test driver, masukkan angka -999 pada input ID Lagu!\n");
        printf("Bila ada masukkan dengan nama lagu yang sama maka akan otomatis tidak dimasukkan ke dalam Set! \n\n");
        printf("Masukkan nama lagu: ");
        STARTCOMMAND(false);  
    }
}