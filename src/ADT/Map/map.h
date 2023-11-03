#ifndef map_H
#define map_H
#include <stdio.h>
#include "../../boolean.h"
#include "../Set/set.h"
/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define Nil 0
#define MaxEl 100
#define Undefined -999

// typedef int bool;
typedef int keytype;
typedef Set valuetype;
typedef int address;

typedef struct
{
        keytype Key; // Id Album
        valuetype Value;
        Word AlbumName;
} Album;

typedef struct
{
    Album Elements[MaxEl];
    address Count;
} MapAlbum;


/* Definisi MapAlbum M kosong : M.Count = Nil */
/* M.Count = jumlah element MapAlbum */
/* M.Elements = tempat penyimpanan element MapAlbum */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(MapAlbum *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah MapAlbum M kosong berkapasitas MaxEl */
/* Ciri MapAlbum kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(MapAlbum M);
/* Mengirim true jika MapAlbum M kosong*/
/* Ciri MapAlbum kosong : count bernilai Nil */

boolean IsFullMap(MapAlbum M);
/* Mengirim true jika MapAlbum M penuh */
/* Ciri MapAlbum penuh : count bernilai MaxEl */

/* ********** Operator Dasar MapAlbum ********* */
valuetype Value(MapAlbum M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertMap(MapAlbum *M, keytype k, valuetype v);
/* Menambahkan Elmt sebagai elemen MapAlbum M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMap(MapAlbum *M, keytype k);
/* Menghapus Elmt dari MapAlbum M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMap(MapAlbum M, keytype k);
/* Mengembalikan true jika k adalah member dari M */

#endif