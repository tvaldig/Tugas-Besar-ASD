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
    printf("Sebuah array dinamik berhasil diinialisasi\n");

    if(IsEmptyArrayDin(temp)){
        printf("Array tersebut kosong\n");
    }

    PrintArrayDin(temp);

    printf("\n");

    /* Tes Insert */
    delayoutput();

    printf("Masukkan nama playlist: ");
    STARTCOMMAND(false);
    handleSemicolon(currentCommand);
    Word playlist = currentCommand;

    InsertFirstArrayDin(&temp, playlist);
    InsertLastArrayDin(&temp, playlist);
    printf("Berhasil di masukkan ke dalam Array Dinamis sebagai elemen pertama dan terakhir\n");
    PrintArrayDin(temp);
    printf("\n");

    delayoutput();

    printf("Masukkan nama playlist: ");
    STARTCOMMAND(false);
    handleSemicolon(currentCommand);
    Word playlist = currentCommand;

    InsertAt(&temp, 1, playlist);
    printf("Berhasil di masukkan ke dalam Array Dinamis sebagai elemen kedua\n");

    PrintArrayDin(temp);
    printf("\n");

    /* Tes Search */
    delayoutput();

    printf("Masukkan elemen yang ingin dicari\n");
    printf("Masukkan IDX penyanyi: ");
    scanf("%d", &penyanyi);
    printf("Masukkan IDX album: ");
    scanf("%d", &album);
    printf("Masukkan IDX lagu: ");
    scanf("%d", &lagu);

    printf("\nElemen ada di IDX: %d\n", SearchArrayDin(temp, penyanyi, album, lagu));
    PrintArrayDin(temp);
    printf("\n");

    /* Tes Delete */
    delayoutput();
    printf("Menghapus semua elemen\n");

    while(!IsEmptyArrayDin(temp)){
        DeleteAt(&temp, 0);
    }

    PrintArrayDin(temp);
    DeallocateArrayDin(&temp);
    printf("Proses dealokasi berhasil dilakukan\n");
    return 0;
}