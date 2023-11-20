#include <stdio.h>
#include "set.h"

void CreateEmptySet(Set *S){
    S->Count= Zero;
    S->idSet=-999;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(Set S){
    return S.Count ==  Zero;
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */.

/* ********** Operator Dasar Set ********* */
void InsertSetLagu(Set *S, int IdAlbum, int IdSet, Word Elmt){
    if(!(IsMemberSet(*S, Elmt))){
        S->AlbumLagu[S->Count].JudulLagu = Elmt;
        S->AlbumLagu[S->Count].IdAlbum = IdAlbum;
        S->idSet = IdSet;
        S->Count++;
    }
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

boolean IsMemberSet(Set S, Word Elmt){
    boolean found = false;
    char ElmtOut[100];
    char JudulLaguOut[100];
    int i = 0;
    ConvertWordToString(&Elmt, ElmtOut);
    while(i < S.Count && !found){
        ConvertWordToString(&S.AlbumLagu[i].JudulLagu, JudulLaguOut);
        if(IsStringEqual(JudulLaguOut, ElmtOut)){
            found = true;
        } else {
            i++;
        }
    }
    return found;
}
/* Mengembalikan true jika Elmt adalah member dari S */

void PrintSet(Set s){
    if(IsEmptySet(s)){
        printf("Set Kosong\n");
    } else {
        printf("ID SET: %d\n", s.idSet);
        for(int i = Zero; i < s.Count; i++){
            printf("ID Lagu:%d ID Album:%d, Judul Lagu %d:%s\n", i, s.AlbumLagu[i].IdAlbum, i+1, s.AlbumLagu[i].JudulLagu.TabWord);
        }
    }
}
