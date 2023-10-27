#include "circular_queue.h"
#include <stdio.h>

void CreateQueue(Queue *Q)
{
    IDX_HEAD(*Q) = IDX_UNDEF;
    IDX_TAIL(*Q) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* ********* Prototype ********* */
boolean IsEmpty(Queue Q)
{
    return (IDX_HEAD(Q) == IDX_UNDEF) && (IDX_TAIL(Q) == IDX_UNDEF);
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull(Queue Q)
{
    return Length(Q) == IDX_MAX + 1;
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam Tab melingkar*/

int Length(Queue Q)
{
    if (IsEmpty(Q))
    {
        return 0;
    }
    else if (IDX_HEAD(Q) <= IDX_TAIL(Q))
    {
        return IDX_TAIL(Q) - IDX_HEAD(Q) + 1;
    }
    else
    {
        return (IDX_TAIL(Q) + 1 + (IDX_MAX - IDX_HEAD(Q) + 1));
    }
}
/* Mengirimkan banyaknya elemen Queue. Mengirimkan 0 jika Q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *Q, ElType X)
{
    if (IsEmpty(*Q))
    {
        IDX_HEAD(*Q) = 0;
        IDX_TAIL(*Q) = 0;
        TAIL(*Q) = X;
    }
    else
    {
        IDX_TAIL(*Q) = (IDX_HEAD(*Q) + Length(*Q)) % (IDX_MAX + 1);
        TAIL(*Q) = X;
    }
}
/* Proses: Menambahkan val pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam Tab melingkar. */

ElType dequeue(Queue *Q)
{
    ElType val = HEAD(*Q);
    if (IDX_HEAD(*Q) == IDX_TAIL(*Q))
    {
        IDX_HEAD(*Q) = IDX_UNDEF;
        IDX_TAIL(*Q) = IDX_UNDEF;
    }
    else
    {
        IDX_HEAD(*Q) = ((IDX_HEAD(*Q) + 1) % (IDX_MAX + 1));
    }
    return val;
}
/* Proses: Menghapus val pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        Q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue Q)
{
    printf("[");
    if (!IsEmpty(Q))
    {
        for (int i = IDX_HEAD(Q); i < IDX_HEAD(Q) + Length(Q); i++)
        {
            printf("%d", Q.Tab[i % (IDX_MAX + 1)]);
            if (i % (IDX_MAX + 1) != IDX_TAIL(Q))
            {
                printf(",");
            }
        }
    }
    printf("]\n");
}