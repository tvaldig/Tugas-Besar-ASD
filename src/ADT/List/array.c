
#include "array.h"
#include "../../boolean.h"
#include <stdio.h>
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
void MakeEmpty(TabInt *T)
{
    (*T).Neff = 0;
}
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T)
{
    return T.Neff;
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */

/* *** Selektor INDEKS *** */
IdxType GetLastIdx(TabInt T)
{
    return NbElmt(T);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* *** Menghasilkan sebuah elemen *** */
Word GetNamaPenyanyi(TabInt T, IdxType i)
{
    return T.penyanyi[i].namapenyanyi;
}
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel nama penyanyi yang ke-i */

ElType GetJumlahAlbum(TabInt T, IdxType i){
    return T.penyanyi[i].jumlahalbum;
}
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel jumlah album yang ke-i */

ElType GetIdAlbumPertama(TabInt T, IdxType i)
{
    return T.penyanyi[i].IdAlbumPertama;
}
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel id album pertama yang ke-i */


/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Assignment THsl -> Tin */
void SetPenyanyi(TabInt *T, IdxType i, Penyanyi penyanyi)
{
    T->penyanyi[i] = penyanyi;
    T->Neff++;
}

void SetIdAlbumPertamaPenyanyi(TabInt *T, IdxType i, ElType idAlbum){
    T->penyanyi[i].IdAlbumPertama = idAlbum;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArray(TabInt T)
{
    return NbElmt(T) == 0;
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi(TabInt T)
{
    char penyanyi[100];
    if (IsEmptyArray(T))
    {
        printf("Tabel kosong\n");
    }
    else
    {
        for (IdxType i = 0; i < GetLastIdx(T); i++)
        {
            Word wordpenyanyi = GetNamaPenyanyi(T,i);
            ConvertWordToString(&wordpenyanyi,penyanyi);
            printf("ID: %d, NAMA PENYANYI: %s, JUMLAH ALBUM: %d, IDALBUMPERTAMA: %d\n", i, penyanyi, GetJumlahAlbum(T,i), GetIdAlbumPertama(T,i));
        }
    }
}
/* Proses : Menuliskan isi tabel dengan traversal */
