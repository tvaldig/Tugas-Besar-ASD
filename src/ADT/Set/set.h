#ifndef set_H
#define set_H
#include <stdio.h>
#include "../../boolean.h"
#include "../MesinKata/mesinkata.h"
/* MODUL Set
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

#define Zero 0
#define MaxEl 100

typedef int address;

typedef struct {
        Word JudulLagu;
        int IdLagu;
        int IdAlbum;
} Lagu;

typedef struct
{
    Lagu AlbumLagu[MaxEl];
    address Count;
    int idSet;
} Set;

/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptySet(Set *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(Set S);
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFullSet(Set S);
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void InsertSetLagu(Set *S, int IdLagu, int IdAlbum, Word Elmt);
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */


boolean IsMemberSet(Set S, Word Elmt);
/* Mengembalikan true jika Elmt adalah member dari S */

void PrintSet(Set S);
#endif