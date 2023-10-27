

#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

ArrayDin MakeArrayDin()
{
    ArrayDin arr;
    arr.A = (ElType *)malloc(InitialSize * sizeof(ElType));
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

boolean IsEmpty(ArrayDin array)
{
    return array.Neff == 0;
}

int Length(ArrayDin array)
{
    return array.Neff;
}

ElType Get(ArrayDin array, IdxType i)
{
    return array.A[i];
}

int GetCapacity(ArrayDin array)
{
    return array.Capacity;
}

void InsertAt(ArrayDin *array, ElType el, IdxType i)
{

    if ((array->Neff) == (array->Capacity))
    {
        int Capacity2 = 2 * ((*array).Capacity);
        ElType *temp = (ElType *)realloc(array->A, Capacity2 * sizeof(ElType));
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
    (*array).A[i] = el;
    (*array).Neff++;
}
void InsertLast(ArrayDin *array, ElType el)
{
    return InsertAt(array, el, array->Neff);
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(ArrayDin *array, ElType el)
{
    return InsertAt(array, el, 0);
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
        printf("%d", (array).A[j]);
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
    ElType *temp = (ElType *)malloc((*array).Capacity * sizeof(ElType));

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
IdxType SearchArrayDin(ArrayDin array, ElType el)
{
    // KAMUS
    IdxType j = 0;
    // ALGORITMA
    while (((array).A[j] != el) && (j <= (array).Neff))
    {
        j++;
    }
    if (j > (array).Neff)
    {
        j = -1;
    }
    return j;
}