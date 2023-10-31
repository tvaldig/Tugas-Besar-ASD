#include "circular_queue.h"
#include <stdio.h>

void delayoutput(){
    int input;
    printf("Masukkan angka sembarang untuk melanjutkan: ");
    scanf("%d",&input);
    printf("\n");
}

int main(){
    /* Tes CreateQueue dan isEmptyStack */
    Queue temp;
    CreateQueue(&temp);

    printf("Sebuah queue sudah berhasil dibuat\n");

    if(IsEmptyQueue(temp)){
        displayQueue(temp);
        printf("Queue tersebut kosong\n");
    }

    /* Tes Length */
    printf("Panjang Queue: %d\n\n", LengthQueue(temp));

    /* Tes enqueue */
    IdxType inputpenyanyi;
    IdxType inputalbum;
    IdxType inputlagu;

    int n;
    printf("Masukkan berapa elemen yang mau diinput ke dalam queue: ");
    scanf("%d", &n);
    for(int i = 0; i<n; i++){ /* tes enqueue dengan 20 elemen */
        printf("Nama penyanyi yang mau dimasukkan ke dalam Queue: ");
        scanf("%d", &inputpenyanyi);
        printf("Nama album yang mau dimasukkan ke dalam Queue: ");
        scanf("%d", &inputalbum);
        printf("Nama lagu yang mau dimasukkan ke dalam Queue: ");
        scanf("%d", &inputlagu);
        enqueue(&temp, inputpenyanyi, inputalbum, inputlagu);
    }

    printf("Enqueue %d elemen baru berhasil dilakukan\n",n);
    displayQueue(temp);
    printf("\n");

    /* Tes dequeue */
    delayoutput();
    dequeue(&temp, &inputpenyanyi, &inputalbum, &inputlagu);
    printf("Berhasil didequeue, penyanyi: %d\n", inputpenyanyi);
    printf("Berhasil didequeue, album: %d\n", inputalbum);
    printf("Berhasil didequeue, lagu: %d\n", inputlagu);

    displayQueue(temp);
    printf("\n");

    delayoutput();
    printf("Proses dequeue semua elemen elemen\n");

    while(!IsEmptyQueue(temp)){
        dequeue(&temp, &inputpenyanyi, &inputalbum, &inputlagu);
        printf("Berhasil didequeue, penyanyi: %d\n", inputpenyanyi);
        printf("Berhasil didequeue, album: %d\n", inputalbum);
        printf("Berhasil didequeue, lagu: %d\n", inputlagu);
        printf("\n");
    }

    displayQueue(temp);
    printf("\n");



}