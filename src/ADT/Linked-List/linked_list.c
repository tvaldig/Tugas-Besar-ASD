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
boolean IsEmptyLinkedList(playlist L)
{
    /* Mengirim true jika list kosong */
    return (First(L) == null);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty(playlist *L)
{
    /* I.S. sembarang             */
    /* F.S. Terbentuk list kosong */
    First(*L) = null;
}

/****************** Manajemen Memori ******************/
addressnode alokasi(int idpenyanyi, int idalbum, int idlagu)
{
    /* Mengirimkan address hasil alokasi sebuah elemen */
    /* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
    /* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
    /* Jika alokasi gagal, mengirimkan Nil */
    
    addressnode E = (addressnode) malloc (sizeof(Elmtlist));
    if (E != NULL)
    {
        PENYANYI(E) = idpenyanyi;
        ALBUM(E) = idalbum;
        LAGU(E) = idlagu;
        Next(E) = null;
        return E;
    }
}

void Dealokasi(addressnode *P)
{
    /* I.S. P terdefinisi */
    /* F.S. P dikembalikan ke sistem */
    /* Melakukan dealokasi/pengembalian address P */
    free(*P);
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
void InsVLast(playlist *L, int idpenyanyi, int idalbum, int idlagu)
{
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen list di akhir: elemen terakhir yang baru */
    /* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    addressnode P = alokasi(idpenyanyi, idalbum, idlagu);
    if (P != null)
    {
        InsertLast(L, P);
    }
}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst(playlist *L, addressnode P)
{
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter(playlist *L, addressnode P, addressnode Prec)
{
    /* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
    /*      P sudah dialokasi  */
    /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
void InsertLast(playlist *L, addressnode P)
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

void InsertUnique(playlist *L, int idpenyanyi, int idalbum, int idlagu)
{
    /* I.S. Sembarang */
    /* F.S. idpenyanyi, idalbum, idlagu ditambahkan ke dalam Playlist L apabila sebelumnya tidak ada elemen dengan */
    /*      idpenyanyi, idalbum, idlagu yang sama */
    if(!IsMember(*L, idpenyanyi, idalbum, idlagu)){
        InsVLast(L, idpenyanyi, idalbum, idlagu);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelAfter(playlist *L, addressnode *Pdel, addressnode Prec)
{
    /* I.S. List tidak kosong. Prec adalah anggota list  */
    /* F.S. Menghapus Next(Prec): */
    /*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Next(Prec);
    if (Next(Prec) != null)
    {
        Next(Prec) = Next(Next(Prec));
        Next(*Pdel) = null;
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo(playlist L)
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
            printf("%d|%d|%d", PENYANYI(P), ALBUM(P), LAGU(P));
            P = Next(P);
            if (P != null)
                printf(" ; ");
        } while (P != null);
    }
    printf("]\n");
}

int countPlaylist(playlist L){
    /* Menghitung jumlah elemen di dalam suatu Playlist L */
    int count = 0;

    addressnode P = First(L);

    while(P != null){
        count++;
        P = Next(P);
    }

    return count;
}

/****************** PROSES TERHADAP LIST ******************/
boolean IsMember(playlist L, int idpenyanyi, int idalbum, int idlagu)
{
    /* Mengembalikan true apabila idpenyanyi, idalbum, idlagu sudah merupakan anggota dari Playlist L */
    boolean found = false;
    addressnode elmt = First(L);

    if (!IsEmptyLinkedList(L))
    {
        while ((!found) && (elmt != null))
        {
            if (PENYANYI(elmt) == idpenyanyi && ALBUM(elmt) == idalbum && LAGU(elmt) == idlagu)
            {
                return true;
            }
            else
            {
                elmt = Next(elmt);
            }
        }
    }

    return false;
}


