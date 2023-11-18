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
boolean IsEmptyStack(Stack S)
{
    return S.TOP == NIL;
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStack(Stack S)
{
    return S.TOP == MaxEl - 1;
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, idx penyanyi, idx album, idx lagu)
{
    S->TOP++;
    InfoTopPenyanyi(*S) = penyanyi;
    InfoTopAlbum (*S) = album;
    InfoTopLagu (*S) = lagu;
}
/* Menambahkan X sebagai elemen dari Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. TOP bertambah 1, X menjadi TOP yang baru, */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, idx *penyanyi, idx *album, idx *lagu)
{
    *penyanyi = InfoTopPenyanyi(*S);
    *album = InfoTopAlbum(*S);
    *lagu = InfoTopLagu(*S);

    S->TOP--;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void displayStack(Stack q){
    
    if (IsEmptyStack(q)){
        printf("[]\n");
    }
    else{
        printf ("[");
        printf("%d|",(q).T[0].penyanyi);  
        printf("%d|",(q).T[0].album);        
        printf("%d",(q).T[0].lagu); 
        for (int i = 1; i<= (q).TOP;i++){
            printf(",%d|",(q).T[i].penyanyi);  
            printf("%d|",(q).T[i].album);        
            printf("%d",(q).T[i].lagu);              
    }
    printf("]\n");
    }
}

void Reversestack(Stack *S){
    Stack temp;
    CreateEmptyStack(&temp);

    idx p, l, a;

    while (!IsEmptyStack(*S)){
        Pop(S,&p,&a,&l); 
        Push(&temp,p,a,l);
    } 

    for(int i = 0; i <= temp.TOP; i++){
        S->T[i] = temp.T[i];
    }
    
    S->TOP = temp.TOP;
}