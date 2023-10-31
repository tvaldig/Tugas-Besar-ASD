#include "circular_queue.h"
#include <stdio.h>

void delayoutput(){
    int input;
    printf("Masukkan angka sembarang untuk melanjutkan: ");
    scanf("%d",&input);
    printf("\n");
}

int main(){
    /* Tes CreateQueue dan isEmpty */
    Queue temp;
    CreateQueue(&temp);

    printf("Sebuah queue sudah berhasil dibuat\n");

    if(IsEmptyQueue(temp)){
        displayQueue(temp);
        printf("Queue tersebut kosong\n");
    }

    /* Tes Length */
    printf("Panjang Queue: %d\n\n", Length(temp));

    /* Tes enqueue */
    int input;
    printf("Elemen yang mau dimasukkan ke dalam Queue: ");
    scanf("%d", &input);
    enqueue(&temp, input);
    displayQueue(temp);
    printf("\n");

    delayoutput();

    for(int i = 0; i<20; i++){ /* tes enqueue dengan 20 elemen */
        enqueue(&temp, i);
    }

    printf("Enqueue 20 elemen baru berhasil dilakukan\n");
    displayQueue(temp);
    printf("\n");

    /* Tes dequeue */
    delayoutput();
    dequeue(&temp, &input);
    printf("Berhasil didequeue, nilai dari HEAD: %d\n", input);
    displayQueue(temp);
    printf("\n");

    delayoutput();
    printf("Proses dequeue semua elemen elemen\n");

    while(!IsEmptyQueue(temp)){
        dequeue(&temp, &input);
        printf("Berhasil didequeue, nilai dari HEAD: %d\n", input);
        displayQueue(temp);
    }

    printf("\n");

    /* Tes IsFull */
    delayoutput();
    int i = 1;
    while(!IsFullQueue(temp)){
        enqueue(&temp, i);
        i++;
    }
    printf("Queue penuh\n");
    displayQueue(temp);
    printf("\n");

    printf("Pengetesan queue_linked berhasil dilakukan\n");

    
}