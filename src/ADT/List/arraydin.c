#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

ArrayDin MakeArrayDin()
{
    ArrayDin arr;
    arr.A = (playlist *)malloc(InitialSize * sizeof(playlist));
    arr.Capacity = InitialSize;
    arr.Neff = 0;
    return arr;
}

boolean IsEmptyArrayDin(ArrayDin array)
{
    return array.Neff == 0;
}

void InsertAt(ArrayDin *array, IdxType i, Word nama)
{

    if ((array->Neff) == (array->Capacity))
    {
        int Capacity2 = 2 * ((*array).Capacity);
        playlist *temp = (playlist *)realloc(array->A, Capacity2 * sizeof(playlist));
        if (temp != NULL)
        {
            array->A = temp;
            array->Capacity = Capacity2;
        }
    }
    for (int j = (*array).Neff; j > i; j--)
    {
        (*array).A[j] = (*array).A[j - 1];
    }
    array->A[i].namaplaylist = nama;
    array->A[i].idplaylist = i;
    (*array).Neff++;
}

void InsertLastArrayDin(ArrayDin *array, Word nama)
{
    return InsertAt(array, array->Neff, nama);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */

void DeleteAt(ArrayDin *array, IdxType i)
{
    for (int j = i; j < array->Neff; j++)
    {
        array->A[j] = array->A[j + 1];
    }
    array->Neff--;
}

void PrintArrayDin(ArrayDin array)
{
    // KAMUS
    IdxType j;
    // ALGORITMA;
    printf("ID | Nama Playlist\n");
    printf("------------------\n");
    for (j = 0; j < (array).Neff; j++)
    {
        printf("%d  | ", (array).A[j].idplaylist);
        printf("%s\n", (array).A[j].namaplaylist.TabWord);
    }
}

/*
 * Fungsi untuk melakukan search suatu ArrayDin.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxType SearchArrayDin(ArrayDin array, IdxType idplaylist)
{
    // KAMUS
    IdxType j = 0;
    // ALGORITMA
    while ((j <= (array).Neff))
    {
        if (array.A[j].idplaylist == idplaylist){
            break;
        }
        j++;
    }

    if (j > (array).Neff)
    {
        j = -1;
    }
    return j;
}