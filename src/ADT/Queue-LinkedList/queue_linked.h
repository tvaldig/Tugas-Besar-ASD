#ifndef QUEUE_LINKED_H
#define QUEUE_LINKED_H

#include "../Tugas-Besar-ASD/src/boolean.h"
#include <stdlib.h>

#define NIL NULL

typedef int ElType;
typedef struct node *Address;
typedef struct node {
    ElType info;
    address next;
}Node;

typedef struct {
    address addrHead;
    address addrTail;
} Queue;

#define NEXT(p) (p)->next
#define INFO(p) (p)->info

#define ADDR_HEAD(q) (q).addrHead
#define ADDR_TAIL(q) (q).addrTail
#define      HEAD(q) (q).addrHead->info

Address newNode (ElType x);
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info x, 
atau NIL jika alokasi gagal */

boolean isEmpty(Queue q);
/* Mengirim true jika q kosong: ADDR_HEAD(q) = NIL and ADDR_TAIL(q) = NIL */

int length (Queue q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */

void CreateQueue (Queue *q);
/* I.S. sembaran */
/* F.S. sebuah q kosong terbentuk */

void enqueue (Queue *q, ElType x);
/* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dassarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi Tail, Tail"maju" */

void dequeue (Queue *q, ElType x);
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* */
