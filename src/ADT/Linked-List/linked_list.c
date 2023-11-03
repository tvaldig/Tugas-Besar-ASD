/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#include "../../boolean.h"
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyLinkedList(List L)
{
    /* Mengirim true jika list kosong */
    return (First(L) == null);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty(List *L)
{
    /* I.S. sembarang             */
    /* F.S. Terbentuk list kosong */
    First(*L) = null;
}

/****************** Manajemen Memori ******************/
addressnode alokasi(int X)
{
    /* Mengirimkan address hasil alokasi sebuah elemen */
    /* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
    /* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
    /* Jika alokasi gagal, mengirimkan Nil */
    ElmtList *E = (ElmtList *)malloc(sizeof(ElmtList));

    if (E != null)
    {
        Info(E) = X;
        Next(E) = null;
        return E;
    }
    else
    {
        return null;
    }
}

void Dealokasi(addressnode *P)
{
    /* I.S. P terdefinisi */
    /* F.S. P dikembalikan ke sistem */
    /* Melakukan dealokasi/pengembalian address P */
    free(*P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressnode search(List L, int X)
{
    /* Mencari apakah ada elemen list dengan Info(P)= X */
    /* Jika ada, mengirimkan address elemen tersebut. */
    /* Jika tidak ada, mengirimkan Nil */

    boolean found = false;
    addressnode elmt = First(L);

    if (!IsEmptyLinkedList(L))
    {
        while ((!found) && (elmt != null))
        {
            if (Info(elmt) == X)
            {
                found = true;
            }
            else
            {
                elmt = Next(elmt);
            }
        }
    }

    return elmt;
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst(List *L, int X)
{
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    addressnode P = alokasi(X);
    if (P != null)
    {
        InsertFirst(L, P);
    }
}

void InsVLast(List *L, int X)
{
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen list di akhir: elemen terakhir yang baru */
    /* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    addressnode P = alokasi(X);
    if (P != null)
    {
        InsertLast(L, P);
    }
}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(List *L, int *X)
{
    /* I.S. List L tidak kosong  */
    /* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
    /*      dan alamat elemen pertama di-dealokasi */
    addressnode P;
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}
void DelVLast(List *L, int *X)
{
    /* I.S. list tidak kosong */
    /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
    /*      dan alamat elemen terakhir di-dealokasi */
    addressnode P;
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst(List *L, addressnode P)
{
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter(List *L, addressnode P, addressnode Prec)
{
    /* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
    /*      P sudah dialokasi  */
    /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
void InsertLast(List *L, addressnode P)
{
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    if (IsEmptyLinkedList(*L))
    {
        InsertFirst(L, P);
    }
    else
    {
        addressnode Last = First(*L);
        while (Next(Last) != null)
        {
            Last = Next(Last);
        }
        InsertAfter(L, P, Last);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst(List *L, addressnode *P)
{
    /* I.S. List tidak kosong */
    /* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
    /*      Elemen list berkurang satu (mungkin menjadi kosong) */
    /* First element yg baru adalah suksesor elemen pertama yang lama */
    addressnode X = First(*L);
    if (Next(X) == null)
    {
        CreateEmpty(L);
    }
    else
    {
        First(*L) = Next(X);
    }
    *P = X;
}

void DelP(List *L, int X)
{
    /* I.S. Sembarang */
    /* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
    /* Maka P dihapus dari list dan di-dealokasi */
    /* Jika ada lebih dari satu elemen list dengan Info bernilai X */
    /* maka yang dihapus hanya elemen pertama dengan Info = X */
    /* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
    /* List mungkin menjadi kosong karena penghapusan */
    addressnode P = search(*L, X);

    if (P != null)
    {
        addressnode prev = First(*L);

        if (prev == P)
        {
            DelFirst(L, &P);
        }
        else
        {
            while (Next(prev) != P)
            {
                prev = Next(prev);
            }
            DelAfter(L, &P, prev);
        }
    }
    Dealokasi(&P);
}
void DelLast(List *L, addressnode *P)
{
    /* I.S. List tidak kosong */
    /* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
    /*      Elemen list berkurang satu (mungkin menjadi kosong) */
    /* Last element baru adalah predesesor elemen terakhir yg lama, */
    /* jika ada */
    *P = First(*L);
    if (Next(*P) == null)
    {
        CreateEmpty(L);
    }
    else
    {
        addressnode prev = *P;
        while (Next(Next(prev)) != null)
            prev = Next(prev);

        DelAfter(L, P, prev);
    }
}

void DelAfter(List *L, addressnode *Pdel, addressnode Prec)
{
    /* I.S. List tidak kosong. Prec adalah anggota list  */
    /* F.S. Menghapus Next(Prec): */
    /*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Next(Prec);
    if (*Pdel != null)
        Next(Prec) = Next(Next(Prec));
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo(List L)
{
    /* I.S. List mungkin kosong */
    /* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika list kosong : menulis [] */
    /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    printf("[");
    if (!IsEmptyLinkedList(L))
    {
        addressnode P = First(L);
        do
        {
            printf("%d", Info(P));
            P = Next(P);
            if (P != null)
                printf(",");
        } while (P != null);
    }
    printf("]");
}

int NbElmtLinkedList(List L)
{
    /* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    int count = 0;
    if (!IsEmptyLinkedList(L))
    {
        addressnode P = First(L);
        while (Next(P) != null)
        {
            count++;
            P = Next(P);
        }
        count++;
    }

    return count;
}
/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
int Max(List L)
{
    /* Mengirimkan nilai Info(P) yang maksimum */
    addressnode P = First(L);
    int mx = Info(P);

    do
    {
        P = Next(P);
        if (Info(P) > mx)
            mx = Info(P);
    } while (Next(P) != null);

    return mx;
}
/****************** PROSES TERHADAP LIST ******************/
void Konkat1(List *L1, List *L2, List *L3)
{
    /* I.S. L1 dan L2 sembarang */
    /* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
    /* Konkatenasi dua buah list : L1 dan L2    */
    /* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
    /* dan L1 serta L2 menjadi list kosong.*/
    /* Tidak ada alokasi/dealokasi pada prosedur ini */
    addressnode X;

    CreateEmpty(L3);
    if (!IsEmptyLinkedList(*L1))
    {
        addressnode P = First(*L1);
        First(*L3) = P;
        while (Next(P) != null)
        {
            P = Next(P);
        }
        Next(P) = First(*L2);
    }
    else
    {
        First(*L3) = First(*L2);
    }

    CreateEmpty(L1);
    CreateEmpty(L2);
}