/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#ifndef listlinier_H
#define listlinier_H

#include "../../boolean.h"
#include "../MesinKata/mesinkata.h"

#define null NULL

typedef struct tElmtlist *addressnode;
typedef struct tElmtlist
{
    int idpenyanyi;
    int idalbum;
    int idlagu;
    addressnode next;
} Elmtlist;

typedef struct
{
    addressnode First;
    Word namaplaylist;
    int idplaylist;
}playlist;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

#define PENYANYI(P) (P)->idpenyanyi
#define ALBUM(P) (P)->idalbum
#define LAGU(P) (P)->idlagu

#define Next(P) (P)->next
#define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyLinkedList(playlist L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty(playlist *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
addressnode alokasi(int idpenyanyi, int idalbum, int idlagu);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi(addressnode *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVLast(playlist *L, int idpenyanyi, int idalbum, int idlagu);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst(playlist *L, addressnode P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter(playlist *L, addressnode P, addressnode Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast(playlist *L, addressnode P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertUnique(playlist *L, int idpenyanyi, int idalbum, int idlagu);
/* I.S. Sembarang */
/* F.S. idpenyanyi, idalbum, idlagu ditambahkan ke dalam Playlist L apabila sebelumnya tidak ada elemen dengan */
/*      idpenyanyi, idalbum, idlagu yang sama */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelAfter(playlist *L, addressnode *Pdel, addressnode Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo(playlist L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int countPlaylist(playlist L);
/* Menghitung jumlah elemen di dalam suatu Playlist L */

/****************** PROSES TERHADAP LIST ******************/
boolean IsMember(playlist L, int idpenyanyi, int idalbum, int idlagu);
/* Mengembalikan true apabila idpenyanyi, idalbum, idlagu sudah merupakan anggota dari Playlist L */


#endif