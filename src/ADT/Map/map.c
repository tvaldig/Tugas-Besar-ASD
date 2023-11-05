#include <stdio.h>
#include "map.h"

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
    Set MT;
    CreateEmptySet(&MT);
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
        return Undefined;
    }
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */


void InsertMap(MapAlbum *M,  keytype k, valuetype v, Word albumname)
{
    if(!IsMemberMap(*M,k)){
        M->Elements[M->Count+1].Key = k;
        M->Elements[M->Count+1].AlbumName = albumname;
        M->Elements[M->Count + 1].Value = v;
        M->Count++;
    }
   
}


/* Menambahkan Elmt sebagai elemen MapAlbum M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

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

void PrintMap(MapAlbum M){
    if(IsEmptyMap(M)){
        printf("Map Kosong");
    } else {
        for(int i = 0; i <= M.Count; i++){
            
            printf("Key: %d, IdSet:%d, Judul Album: %s\n", M.Elements[i].Key, M.Elements[i].Value, M.Elements[i].AlbumName.TabWord);
        }
    }
}