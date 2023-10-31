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

void DeallocateArrayDin(ArrayDin *array)
{
    free((*array).A);
    (*array).Capacity = 0;
    (*array).Neff = 0;
}

boolean IsEmptyArrayDin(ArrayDin array)
{
    return array.Neff == 0;
}

int LengthArrayDin(ArrayDin array)
{
    return array.Neff;
}

playlist Get(ArrayDin array, IdxType i)
{
    return array.A[i];
}

int GetCapacity(ArrayDin array)
{
    return array.Capacity;
}

void InsertAt(ArrayDin *array, IdxType penyanyi, IdxType album, IdxType lagu, IdxType i)
{

    if ((array->Neff) == (array->Capacity))
    {
        int Capacity2 = 2 * ((*array).Capacity);
        playlist *temp = (playlist *)realloc(array->A, Capacity2 * sizeof(playlist));
        if (temp != NULL)
        {
            array->A->penyanyi = penyanyi;
            array->A->penyanyi = album;
            array->A->penyanyi = lagu;
            array->Capacity = Capacity2;
        }
    }
    for (int j = (*array).Neff; j > i; j--)
    {
        (*array).A[j] = (*array).A[j - 1];
    }
    (*array).A[i].penyanyi = penyanyi;
    (*array).A[i].album = album;
    (*array).A[i].lagu = lagu;
    
    (*array).Neff++;
}

void InsertLastArrayDin(ArrayDin *array, IdxType penyanyi, IdxType album, IdxType lagu)
{
    return InsertAt(array, penyanyi, album, lagu, array->Neff);
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirstArrayDin(ArrayDin *array, IdxType penyanyi, IdxType album, IdxType lagu)
{
    return InsertAt(array, penyanyi, album, lagu, 0);
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

void DeleteLast(ArrayDin *array)
{
    // KAMUS
    // ALGORITMA
    DeleteAt(array, (*array).Neff - 1);
}

/*
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ArrayDin *array)
{
    // KAMUS
    // ALGORITMA
    DeleteAt(array, 0);
}

void PrintArrayDin(ArrayDin array)
{
    // KAMUS
    IdxType j;
    // ALGORITMA
    printf("[");
    for (j = 0; j < (array).Neff; j++)
    {
        printf("%d|", (array).A[j].penyanyi);
        printf("%d|", (array).A[j].album);
        printf("%d", (array).A[j].lagu);

        if (j != (array).Neff - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

/*
 * Fungsi untuk melakukan reverse suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayDin(ArrayDin *array)
{
    IdxType j;
    playlist *temp = (playlist *)malloc((*array).Capacity * sizeof(playlist));

    for (j = 0; j < (*array).Neff; j++)
    {
        temp[j] = (*array).A[(*array).Neff - (1 + j)];
    }
    for (j = 0; j < (*array).Neff; j++)
    {
        (*array).A[j] = temp[j];
    }
    free(temp);
}

/*
 * Fungsi untuk melakukan copy suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
ArrayDin CopyArrayDin(ArrayDin array)
{
    return array;
}

/*
 * Fungsi untuk melakukan search suatu ArrayDin.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxType SearchArrayDin(ArrayDin array, IdxType penyanyi, IdxType album, IdxType lagu)
{
    // KAMUS
    IdxType j = 0;
    // ALGORITMA
    while ((j <= (array).Neff))
    {
        if (((array).A[j].penyanyi == penyanyi) && (array.A[j].album == album) && ((array).A[j].lagu == lagu)){
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