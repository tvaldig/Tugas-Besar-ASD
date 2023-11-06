#include <stdio.h>
#include "set.h"

void CreateEmptySet(Set *S){
    S->Count= Zero;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(Set S){
    return S.Count ==  Zero;
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFullSet(Set S){
    return S.Count == MaxEl;
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void InsertSetLagu(Set *S, int IdLagu, int IdAlbum, Word Elmt){
    if(!(IsMemberSet(*S, Elmt))){
        S->AlbumLagu[S->Count].JudulLagu = Elmt;
        S->AlbumLagu[S->Count].IdLagu = IdLagu;
        S->AlbumLagu[S->Count].IdAlbum = IdAlbum;
        S->Count++;
    }
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

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
        printf("Set Kosong");
    } else {
        for(int i = Zero; i < s.Count; i++){
            printf("%d: ID Album:%d, Judul Lagu %d:%s\n", i, s.AlbumLagu[i].IdAlbum, i+1, s.AlbumLagu[i].JudulLagu.TabWord);
        }
    }
}
