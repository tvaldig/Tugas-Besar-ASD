/* MODUL CIRCULAR QUEUE */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */
/* Implementasi Queue menggunakan circular buffer (Alternatif III) */

#ifndef __circular_queue_h__
#define __circular_queue_h__

#include "../../boolean.h"
#include "../MesinKata/mesinkata.h"

#define IDX_UNDEF -1
#define IDX_MAX 99

/* Definisi tipe elemen dan indeks pada Queue */
typedef int IdxType;

typedef int KEY;

typedef struct{
    IdxType penyanyi;
    KEY album;
    KEY lagu;
} isiqueue;

typedef struct
{
    isiqueue Tab[IDX_MAX + 1]; /* tabel penyimpan elemen */
    IdxType idxHead;         /* indeks elemen paling awal (terdepan) */
    IdxType idxTail;         /* indeks tempat menambah elemen baru */
} Queue;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define HEADPENYANYI(q) (q).Tab[(q).idxHead].penyanyi
#define HEADALBUM(q) (q).Tab[(q).idxHead].album
#define HEADLAGU(q) (q).Tab[(q).idxHead].lagu
#define TAILPENYANYI(q) (q).Tab[(q).idxTail].penyanyi
#define TAILALBUM(q) (q).Tab[(q).idxTail].album
#define TAILLAGU(q) (q).Tab[(q).idxTail].lagu


/* ********* Prototype ********* */
boolean IsEmptyQueue(Queue Q);
/* Mengirim true jika Q kosong */
/* yaitu ketika idxHead=IDX_UNDEF dan idxTail=IDX_UNDEF */
boolean IsFullQueue(Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu ketika idxHead=0 dan idxTail=IDX_MAX atau idxHead=idxTail+1 ketika idxHead > idxTail */
int LengthQueue(Queue Q);
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */

/* *** Kreator *** */
void CreateQueue(Queue *Q);
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/* - idxHead=IDX_UNDEF; */
/* - idxTail=IDX_UNDEF. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *Q, IdxType penyanyi, IdxType album, IdxType lagu);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. Tail "maju" dengan mekanisme circular buffer,
        X menjadi idxTail yang baru
        Jika Q kosong, idxHead dimulai dari 0 */
void dequeue(Queue *Q, IdxType *penyanyi, IdxType *album, IdxType *lagu);
/* Proses: Menghapus idxHead pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada idxHead;
        Head "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue q);
/* Proses : Menuliskan isi Queue dengan traversal dan mekanisme circular buffer; */
/* Queue ditulis di antara kurung siku; antara dua elemen dipisahkan dengan separator "koma" */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
/* Note: Output mengandung newline */

#endif