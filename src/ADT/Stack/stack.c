#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void CreateEmptyStack(Stack *S)
{
    S->TOP = NIL;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0..MaxEl-1 (inklusif) */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S)
{
    return S.TOP == NIL;
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull(Stack S)
{
    return S.TOP == MaxEl - 1;
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, infotype X)
{
    S->TOP++;
    InfoTop(*S) = X;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. TOP bertambah 1, X menjadi TOP yang baru, */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, infotype *X)
{
    *X = InfoTop(*S);
    S->TOP--;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

Stack validParantheses(char *input, int length)
{
    Stack temp;
    int i = 0;
    CreateEmptyStack(&temp);
    while (i < length)
    {
        if (input[i] == '{')
        {
            if (input[i + 1] == '}')
            {
                Push(&temp, input[i]);
                Push(&temp, input[i + 1]);
            }
        }
        if (input[i] == '[')
        {
            if (input[i + 1] == ']')
            {
                Push(&temp, input[i]);
                Push(&temp, input[i + 1]);
            }
        }
        if (input[i] == '(')
        {
            if (input[i + 1] == ')')
            {
                Push(&temp, input[i]);
                Push(&temp, input[i + 1]);
            }
        }
        i++;
    }
    return temp;
}
