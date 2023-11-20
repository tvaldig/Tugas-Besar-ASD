#include <stdio.h>
#include "array.h"

void delayoutput(){
    int input;
    printf("Masukkan angka sembarang untuk melanjutkan: ");
    scanf("%d",&input);
    printf("\n");
}

int main(){
    TabInt test;

    MakeEmpty(&test);

    if(IsEmptyArray(test)){
        printf("Fungsi IsEmptyArray() berhasil di tes!\n\n");
    }

    delayoutput();

    Penyanyi sample;

    int input;

    printf("Masukkan nama penyanyi: ");
    STARTCOMMAND(false);
    sample.namapenyanyi = currentCommand;
    printf("Masukkan jumlah album: ");
    scanf("%d", &(sample.jumlahalbum));
    printf("Masukkan ID album pertama: ");
    scanf("%d", &input);

    SetIdAlbumPertamaPenyanyi(&test, NbElmt(test), input);

    SetPenyanyi(&test, NbElmt(test), sample);

    printf("\nBerhasil dimasukkan ke dalam TabInt test\n\n");

    printf("Nama penyanyi yang dimasukkan %s\n", GetNamaPenyanyi(test, 0).TabWord);
    printf("Jumlah album yang dimasukkan %d\n", GetJumlahAlbum(test, 0));
    printf("ID album pertama yang dimasukkan: %d\n\n", GetIdAlbumPertama(test, 0));
    
    printf("Jumlah elemen dalam TabInt: %d\n", NbElmt(test));
    printf("Isi TabInt: ");
    TulisIsi(test);

    printf("\n\nPengetesan array.c berhasil! \n\n");


}   