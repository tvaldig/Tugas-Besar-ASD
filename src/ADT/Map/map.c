#include <stdio.h>
#include "Map.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(MapAlbum *M)
{
    M->Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(MapAlbum M)
{
    return (M.Count == Nil);
}
/* Mengirim true jika MapAlbum M kosong*/
/* Ciri MapAlbum kosong : count bernilai Nil */

boolean IsFullMap(MapAlbum M)
{
    return M.Count == MaxEl;
}
/* Mengirim true jika MapAlbum M penuh */
/* Ciri MapAlbum penuh : count bernilai MaxEl */

/* ********** Operator Dasar MapAlbum ********* */
valuetype Value(MapAlbum M, keytype k)
{
    Set s;
    CreateEmptySet(&s);
    boolean found = false;
    int i = 0;
    while (i < M.Count && !found)
    {
        if (M.Elements[i].Key == k)
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    if (found)
    {
        return M.Elements[i].Value;
    }
    else
    {
        return s;
    }
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */


void InsertMap(MapAlbum *M, keytype k, valuetype v, Word albumname)
{
    if (!(IsMemberMap((*M), k)))
    {
        M->Elements[M->Count].Key = k;
        M->Elements[M->Count].Value = v;
        M->Elements[M->Count].AlbumName = albumname;
        M->Count++;
    }
}


/* Menambahkan Elmt sebagai elemen MapAlbum M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMap(MapAlbum *M, keytype k)
{
    int i = 0;
    boolean found = false;
    while (i < (*M).Count && !found)
    {
        if (M->Elements[i].Key == k)
        {
            found = true;
            while (i < (*M).Count - 1)
            {
                (*M).Elements[i] = (*M).Elements[i + 1];
                i++;
            }
            (*M).Count--;
        }
        else
        {
            i++;
        }
    }
}
/* Menghapus Elmt dari MapAlbum M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMap(MapAlbum M, keytype k)
{
    int i = 0;
    boolean found = false;
    while (i < M.Count && !found)
    {
        if (M.Elements[i].Key == k)
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    return found;
}

/* Mengembalikan true jika k adalah member dari M */