#include "mesinkarakter.h"
#include <stdio.h>

int main(){
    char x;

    printf("TEST UNTUK MENULISKAN KARAKTER\n");
    printf("TULISKAN KARAKTER :");
    START();
    while(!IsEOP()){ //diakhiri dengan ENTER
        x = GetCC();
        printf("%c\n", x);
        ADV();
    }

    printf("\nTEST UNTUK MELAKUKAN AKUISISI FILE\n");
    STARTFILE("driver.txt");
    while(!IsEOP()){
        x = GetCC();
        printf("%c", x);
        ADVFILE();
    }
    printf("\n");

    printf("\nTEST UNTUK MELAKUKAN OPERASI PADA FILE\n");
    NEWFILE("new.txt");
    WRITESTRING("file");
    WRITEBLANK();
    WRITESTRING("tertulis");
    WRITEBLANK();
    WRITEINT(1);
    WRITEBLANK();
    WRITESEMICOLON();
    WRITEENTER();
    WRITESTRING("line2");
    WRITEFINISH();

    printf("\n");
    
    printf("SILAHKAN BUKA HASILNYA PADA NEW.TXT");
   
}