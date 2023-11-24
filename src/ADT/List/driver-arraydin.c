#include "arraydin.h"
#include "../MesinKata/mesinkata.h"
#include <stdio.h>

void delayoutput(){
    int input;
    printf("Masukkan angka sembarang untuk melanjutkan: ");
    scanf("%d",&input);
    printf("\n");
}

int main(){
    ArrayDin temp;

    /* Tes MakeArrayDin dan IsEmptyArrayDin */
    temp = MakeArrayDin();
    printf("\nSebuah array dinamik berhasil diinialisasi\n");

    if(IsEmptyArrayDin(temp)){
        printf("\nFungsi IsEmptyArrayDin() berhasil di tes!\n\n");
    }

    PrintArrayDin(temp);

    printf("\n");

    /* Tes Insert */
    delayoutput();

    char removeenter;
    scanf("%c", &removeenter);

    printf("Masukkan nama playlist: ");
    STARTCOMMAND(false);
    Word playlist = currentCommand;

    InsertLastArrayDin(&temp, playlist);
    printf("Berhasil di masukkan ke dalam Array Dinamis sebagai elemen pertama\n");
    PrintArrayDin(temp);
    printf("\n");

    delayoutput();

    scanf("%c", &removeenter);

    printf("Masukkan nama playlist: ");
    STARTCOMMAND(false);
    playlist = currentCommand;

    InsertAt(&temp, 1, playlist);
    printf("Berhasil di masukkan ke dalam Array Dinamis sebagai elemen kedua\n");

    PrintArrayDin(temp);
    printf("\n");

    /* Tes Search */
    delayoutput();

    IdxType idplaylist;
    printf("Masukkan IDX playlist yang ingin dicari\n");
    printf("Masukkan IDX playlist: ");
    scanf("%d", &idplaylist);

    if(SearchArrayDin(temp, idplaylist) == -1){
        printf("\nIDX playlist %d tidak ditemukan.\n\n", idplaylist);
    }else{
        printf("\nIDX playlist %d ditemukan.\n\n", idplaylist);
    }

    /* Tes Delete */
    delayoutput();
    printf("Menghapus semua elemen\n");

    while(!IsEmptyArrayDin(temp)){
        DeleteAt(&temp, 0);
    }
    PrintArrayDin(temp);

    printf("\nPengetesan arraydin.c berhasil !\n\n");

    return 0;
}