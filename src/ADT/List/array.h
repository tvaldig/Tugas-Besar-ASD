#include "../../boolean.h"
#include "../MesinKata/mesinkata.h"
#ifndef ARRAY_H
#define ARRAY_H
/* Kamus Umum */

#define IdxMax 99
#define IdxMin 0
#define IdxUndef -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef int ElType;

typedef struct
{
    Word namapenyanyi;
    ElType jumlahalbum;
    ElType IdAlbumPertama;
} Penyanyi;

/* ********** KONSTRUKTOR ********** */
typedef struct
{
    Penyanyi penyanyi[IdxMax - IdxMin + 1]; /* memori tempat penyimpan elemen (container) */
    int Neff;                       /* banyaknya elemen efektif */
} TabInt;


/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen tabel
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty(TabInt *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
IdxType GetLastIdx(TabInt T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
Word GetNamaPenyanyi(TabInt T, IdxType i);
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel nama penyanyi yang ke-i */

ElType GetJumlahAlbum(TabInt T, IdxType i);
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel jumlah album yang ke-i */

ElType GetIdAlbumPertama(TabInt T, IdxType i);

/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
 /* Mengirimkan elemen tabel id album pertama yang ke-i */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */

void SetPenyanyi(TabInt *T, IdxType i, Penyanyi penyanyi);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai datapenyanyi*/

void SetIdAlbumPertamaPenyanyi(TabInt *T, IdxType i, ElType idAlbum);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai idalbum*/

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArray(TabInt T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi(TabInt T);
/* Proses : Menuliskan isi tabel dengan traversal */

#endif

// Path: src/ADT/List/array.c