
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
/* *** Daya tampung container *** */
int MaxNbEl(TabInt T)
{
    return IdxMax;
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T)
{
    return IdxMin;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
IdxType GetLastIdx(TabInt T)
{
    return NbElmt(T);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt(TabInt T, IdxType i)
{
    return T.penyanyi[i].IdAlbumPertama;
}
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab(TabInt Tin, TabInt *Tout)
{
    (*Tout) = Tin;
}
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
void SetEl(TabInt *T, IdxType i, ElType v)
{
    T->penyanyi->IdAlbumPertama = v;
    if (i > GetLastIdx(*T))
    {
        T->Neff += 1;
    }
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
void SetNeff(TabInt *T, IdxType N)
{
    T->Neff = N;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i)
{
    return (MaxNbEl(T) >= i && GetFirstIdx(T) <= i);
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff(TabInt T, IdxType i)
{
    return (GetLastIdx(T) >= i && GetFirstIdx(T) <= i);
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArray(TabInt T)
{
    return NbElmt(T) == 0;
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFullArray(TabInt T)
{
    return NbElmt(T) == MaxNbEl(T);
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi(TabInt T)
{
    if (IsEmptyArray(T))
    {
        printf("Tabel kosong\n");
    }
    else
    {
        for (IdxType i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
        {
            printf("%d:%d\n", i, T.penyanyi->IdAlbumPertama);
        }
    }
}
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [1,2,3] maka akan diprint
0:1
1:2
2:3
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab(TabInt T1, TabInt T2)
{
    TabInt TPlus;
    MakeEmpty(&TPlus);
    for (IdxType i = GetFirstIdx(TPlus); i <= GetLastIdx(TPlus); i++)
    {
        TPlus.penyanyi->IdAlbumPertama = GetElmt(T1, i) + GetElmt(T2, i);
    }
    TPlus.Neff = T1.Neff;
    return TPlus;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 + T2 */
TabInt MinusTab(TabInt T1, TabInt T2)
{
    TabInt TMin;
    MakeEmpty(&TMin);
    for (IdxType i = GetFirstIdx(TMin); i <= GetLastIdx(TMin); i++)
    {
        TMin.penyanyi[i].IdAlbumPertama = GetElmt(T1, i) - GetElmt(T2, i);
    }
    TMin.Neff = T1.Neff;
    return TMin;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 - T2 */

/* ********** NILAI EKSTREM ********** */
ElType ValMax(TabInt T)
{
    ElType max = GetElmt(T, 1);
    for (int i = GetFirstIdx(T) + 1; i < GetLastIdx(T); i++)
    {

        if (T.penyanyi[i].IdAlbumPertama > max)
        {
            max = T.penyanyi[i].IdAlbumPertama;
        }
    }
    return max;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */

ElType ValMin(TabInt T)
{
    ElType min = GetElmt(T, 1);
    for (int i = GetFirstIdx(T) + 1; i < GetLastIdx(T); i++)
    {

        if (T.penyanyi[i].IdAlbumPertama < min)
        {
            min = T.penyanyi[i].IdAlbumPertama;
        }
    }
    return min;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */

/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab(TabInt T)
{
    IdxType maxin;
    maxin = GetFirstIdx(T);
    for (int i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++)
    {
        if (GetElmt(T, maxin) < GetElmt(T, i))
        {
            maxin = i;
        }
    }
    return (maxin);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */

IdxType IdxMinTab(TabInt T)
{
    IdxType minin;
    minin = GetFirstIdx(T);
    for (int i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++)
    {
        if (GetElmt(T, minin) > GetElmt(T, i))
        {
            minin = i;
        }
    }
    return (minin);
}
/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i */
/* dengan elemen ke-i nilai minimum pada tabel */
