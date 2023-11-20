#include "linked_list.h"
#include <stdio.h>

/* Definisi list : */
void delayoutput(){
    int input;
    printf("Masukkan angka sembarang untuk melanjutkan: ");
    scanf("%d",&input);
    printf("\n");
}

int main(){
    addressnode p, new;
    int input1, input2, input3;
    printf("Masukkan idpenyanyi untuk node baru: ");
    scanf("%d", &input1);
    printf("Masukkan idalbum untuk node baru: ");
    scanf("%d", &input2);
    printf("Masukkan idlagu untuk node baru: ");
    scanf("%d", &input3);

    p = alokasi(input1,input2,input3);
    printf("INFO dari node baru: %d %d %d\n", PENYANYI(p), ALBUM(p), LAGU(p));
    printf("NEXT dari node baru: %d\n\n", Next(p));

    playlist L;

    delayoutput();

    CreateEmpty(&L);

    if(IsEmptyLinkedList(L)){
        printf("Fungsi IsEmptyLinkedList() sudah berhasil di tes!\n\n");
    }

    delayoutput();

    InsVLast(&L, 1, 2, 3);

    addressnode q = alokasi (4, 5, 6);
    InsertFirst(&L, q);

    addressnode r = alokasi(7, 8, 9);
    InsertAfter(&L, r, First(L));

    addressnode s = alokasi (10, 11, 12);
    InsertLast(&L, s);

    InsertUnique(&L, 1, 2, 3);
    InsertUnique(&L, 13,14,15);

    printf("Hasil yang diharapkan: [4|5|6 ; 7|8|9 ; 1|2|3 ; 10|11|12 ; 13|14|15]\nHasil yang didapatkan: ");
    PrintInfo(L);
    printf("\nHasil sama, pengetesan operasi Insert berhasil\n\n");

    delayoutput();

    DelAfter(&L, &s, First(L));

    printf("Hasil yang diharapkan: [4|5|6 ; 1|2|3 ; 10|11|12 ; 13|14|15]\nHasil yang didapatkan: ");
    PrintInfo(L);
    printf("\nHasil sama, pengetesan operasi Delete berhasil\n\n");

    delayoutput();

    PrintInfo(L);
    printf("Jumlah elemen dalam playlist: %d\n\n", countPlaylist(L));

    delayoutput();

    printf("Masukkan idpenyanyi untuk dicari di dalam list: ");
    scanf("%d", &input1);
    printf("Masukkan idalbum untuk dicari di dalam list: ");
    scanf("%d", &input2);
    printf("Masukkan idlagu untuk dicari di dalam list: ");
    scanf("%d", &input3);

    if(IsMember(L, input1, input2, input3)){
        printf("\n%d %d %d ada di dalam Playlist L!\n\n", input1, input2, input3);
    }else{
        printf("\n%d %d %d tidak ditemukan!\n\n", input1, input2, input3);
    }

    printf("Pengetesan berhasil !\n\n");
}