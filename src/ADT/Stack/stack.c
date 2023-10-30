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
    CreateEmpty(&temp);
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

// JAWABAN PALINDROME TAHUN 2021
int main()
{
    Stack s1, s2;
    int x;
    infotype y;
    boolean palindrome = false;
    CreateEmpty(&s1);
    CreateEmpty(&s2);
    scanf("%d", &x);
    while (x != 0)
    {
        Push(&s1, x);
        scanf("%d", &x);
    }

    if (Top(s1) == 0)
    {
        palindrome = true;
    }
    else if (Top(s1) == 1)
    {
        if (InfoTop(s1) == s1.T[0])
        {
            palindrome = true;
        }
    }
    else
    {
        for (int i = 0; i < Top(s1) / 2; i++)
        {
            Push(&s2, InfoTop(s1));
            Pop(&s1, &y);
            if (s1.T[i] == s2.T[i])
            {
                palindrome = true;
            }
        }
    }

    if (palindrome)
    {
        printf("Angka palindrome");
    }
    else
    {
        printf("Bukan palindrome");
    }
}
