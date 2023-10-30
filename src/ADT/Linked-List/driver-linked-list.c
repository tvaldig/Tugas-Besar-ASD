#include "linked_list.h"
#include <stdio.h>

void delayoutput(){
    int input;
    printf("Masukkan angka sembarang untuk melanjutkan: ");
    scanf("%d",&input);
    printf("\n");
}


int main(){
    /* Test Alokasi */
    address p, new;
    int input;
    printf("Masukkan INFO untuk node baru: ");
    scanf("%d", &input);
    p = Alokasi(input);
    printf("INFO dari node baru: %d\n", Info(p));
    printf("NEXT dari node baru: %d\n\n", Next(p));

    /* Test CreateEmpty dan IsEmptyLinkedList */
    delayoutput();
    List temp, temp2, hasil;
    CreateEmpty(&temp);
    if(IsEmptyLinkedList(temp)){
        printf("List kosong berhasil dibuat\n\n");
    }

    /* Test Modifikasi Elemen */
    delayoutput();
    printf("Memasukkan 1 sebagai Elemen Terakhir\n");
    p = Alokasi(1);
    InsVLast(&temp,1);
    DelVLast(&temp, &input);
    InsertLast(&temp, p);

    printf("Memasukkan 2 sebagai Elemen Pertama\n");
    p = Alokasi(2);
    InsVFirst(&temp,2);
    DelVFirst(&temp, &input);
    InsertFirst(&temp, p);
    PrintInfo(temp);

    printf("\n\n");

    delayoutput();

    printf("Memasukkan 4 setelah Elemen yang bernilai 1\n");
    p = Search(temp, 1);
    new = Alokasi(4);
    InsertAfter(&temp, new, p);
    PrintInfo(temp);
    printf("\n");
    printf("Jumlah elemen dalam list: %d\n", NbElmtLinkedList(temp));
    printf("Nilai maksiumum dalam list: %d\n\n", Max(temp));

    /* Tes Konkat */
    delayoutput();
    CreateEmpty(&temp2);

    InsVFirst(&temp2, 9);
    InsVFirst(&temp2, 8);
    printf("Isi dari list ke 2: ");
    PrintInfo(temp2);
    printf("\n");
    printf("Konkatenasi list 1 dan list 2\n");
    Konkat1(&temp, &temp2, &hasil);
    PrintInfo(hasil);
    printf("\n\n");


    


}