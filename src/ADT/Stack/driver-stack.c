#include "stack.h"
#include <stdio.h>

/* Definisi list : */
void delayoutput(){
    int input;
    printf("Masukkan angka sembarang untuk melanjutkan: ");
    scanf("%d",&input);
    printf("\n");
}

int main(){
    Stack temp;
    /* Tes CreateEmptyStack dan isEmptyStack */
    CreateEmptyStack (&temp);

    printf("Sebuah stack sudah berhasil dibuat\n");

    if(IsEmptyStack(temp)){
        displayStack(temp);
        printf("Stack tersebut kosong\n\n");
    }

    /* Tes Push */
    void delayoutput();
    idx inputpenyanyi;
    idx inputalbum;
    idx inputlagu;
    int n;
    printf("Masukkan berapa elemen yang mau dipush ke dalam stack: ");
    scanf("%d", &n);

    for(int i = 0; i<n; i++){ /* tes enqueue dengan 20 elemen */
        printf("Nama penyanyi yang mau dimasukkan ke dalam Stack: ");
        scanf("%d", &inputpenyanyi);
        printf("Nama album yang mau dimasukkan ke dalam Stack: ");
        scanf("%d", &inputalbum);
        printf("Nama lagu yang mau dimasukkan ke dalam Stack: ");
        scanf("%d", &inputlagu);
        Push(&temp, inputpenyanyi, inputalbum, inputlagu);
    }

    /* Tes displayStack */
    printf("Enqueue %d elemen baru berhasil dilakukan\n",n);
    displayStack(temp);
    printf("\n");

    /* Tes Pop */
    delayoutput();
    Pop(&temp, &inputpenyanyi, &inputalbum, &inputlagu);
    printf("Berhasil dipop, penyanyi: %d\n", inputpenyanyi);
    printf("Berhasil dipop, album: %d\n", inputalbum);
    printf("Berhasil dipop, lagu: %d\n", inputlagu);

    displayStack(temp);
    printf("\n");

    delayoutput();
    printf("Proses dequeue semua elemen elemen\n");

    while(!IsEmptyStack(temp)){
        Pop(&temp, &inputpenyanyi, &inputalbum, &inputlagu);
        printf("Berhasil dipop, penyanyi: %d\n", inputpenyanyi);
        printf("Berhasil dipop, album: %d\n", inputalbum);
        printf("Berhasil dipop, lagu: %d\n", inputlagu);
        printf("\n");
    }

    displayStack(temp);

    printf("\n");



}