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
void InsertSetLagu(Set *S, int IdAlbum, Word Elmt){
    if(!(IsMemberSet(*S, Elmt))){
        S->AlbumLagu[S->Count].JudulLagu = Elmt;
        S->AlbumLagu[S->Count].idAlbum = IdAlbum;
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
    int i = 0;
    while(i < S.Count && !found){
        if(S.AlbumLagu[i].JudulLagu.TabWord == Elmt.TabWord){
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
            
        }
    }
}
