#include "queue_linked.h"
#include <stdlib.h>

Address newNode (ElType x){
    Node *temp;

    temp = (Node *) malloc (sizeof(Node));

    if(temp != NIL){
        NEXT(temp) = NIL;
        INFO(temp) = x;
    }else{
        temp = NIL;
    }

    return temp;
}
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info x, 
atau NIL jika alokasi gagal */

boolean isEmpty(Queue q){
    return (ADDR_HEAD(q) == NIL) && (ADDR_TAIL(q) == NIL);
}
/* Mengirim true jika q kosong: ADDR_HEAD(q) = NIL and ADDR_TAIL(q) = NIL */

int length (Queue q){
    if(isEmpty(q)){
        return 0;
    }else{
        int count = 0;
        Address p;
        p = q.addrHead;
        while(p != NIL){
            count = count + 1;
            p = NEXT(p);
        }
        return count;
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */

void CreateQueue (Queue *q){
    ADDR_HEAD(*q) = NIL;
    ADDR_TAIL(*q) = NIL;
    
}
/* I.S. sembaran */
/* F.S. sebuah q kosong terbentuk */

void enqueue (Queue *q, ElType x){
    Address p;

    p = newNode(x);

    if(p != NIL){
        if(isEmpty(*q)){
            ADDR_HEAD(*q) = p;
        }else{
            NEXT(ADDR_TAIL(*q)) = p;
        }
        
        ADDR_TAIL(*q) = p;
    }
}
/* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dassarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi Tail, Tail"maju" */

void dequeue (Queue *q, ElType *x){
    Address p;

    *x = HEAD(*q);

    p = ADDR_HEAD(*q);

    ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));

    if(ADDR_HEAD(*q) == NIL){
        ADDR_TAIL(*q) = NIL;
    }

    NEXT(p) = NIL;
    free(p);
}
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pada I.S., HEAD "mundur"*/
