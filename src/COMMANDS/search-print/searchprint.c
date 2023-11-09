#include "searchprint.h"

int searchidpenyanyi(TabInt p, Word input)
{ // Mencari key id penyanyi berdasarkan inputan user
    int i = 0;
    while (i < p.Neff)
    {
        if (p.penyanyi[i].namapenyanyi.Length == input.Length)
        {
            if (IsStringEqual(p.penyanyi[i].namapenyanyi.TabWord, input.TabWord))
            {
                return i;
            }
        }
        i++;
    }
    return -1;
}

int searchidalbum(TabInt p, int idpenyanyi, Word input, MapAlbum map)
{
    int i = p.penyanyi[idpenyanyi].IdAlbumPertama;
    while (i < p.penyanyi[idpenyanyi].jumlahalbum + i)
    {
        if (map.Elements[i].AlbumName.Length == input.Length)
        {
            if (IsStringEqual(map.Elements[i].AlbumName.TabWord, input.TabWord))
            {
                return i;
            }
        }
        i++;
    }
    return -1;
}

int searchidlagu(Set *s, MapAlbum map, int idalbum, Word input)
{
    int idxset = Value(map, idalbum);

    for(int i = 0; i < s[idxset].Count; i++){
        if (s[idxset].AlbumLagu[i].JudulLagu.Length == input.Length)
            {
                if (IsStringEqual(s[idxset].AlbumLagu[i].JudulLagu.TabWord, input.TabWord))
                {
                    return i;
                }
            }
    }
    return -1;
}

void printPenyanyi(){
    printf("\nDaftar Penyanyi : \n");
    for(int i = 0; i < ArrayPenyanyi.Neff; i++){
        printf("    %d. %s\n", i+1, ArrayPenyanyi.penyanyi[i].namapenyanyi.TabWord);
    }
}

void printAlbum(int idpenyanyi){
    printf("\nDaftar Album oleh %s : \n", ArrayPenyanyi.penyanyi[idpenyanyi].namapenyanyi.TabWord);

    int i = ArrayPenyanyi.penyanyi[idpenyanyi].IdAlbumPertama, nomor = 1;

    for(i; i < ArrayPenyanyi.penyanyi[idpenyanyi].jumlahalbum; i++){
        printf("    %d. %s\n", nomor, mapAlbum.Elements[i].AlbumName.TabWord);
        nomor++;
    }
}   

void printLagu(int idalbum, int idpenyanyi){
    printf("\nDaftar Lagu Album %s oleh %s : \n", mapAlbum.Elements[idalbum].AlbumName.TabWord,ArrayPenyanyi.penyanyi[idpenyanyi].namapenyanyi.TabWord);

    int idxset = Value(mapAlbum, idalbum);

    for(int i = 0; i < SetLagu[idxset].Count ; i++){
        printf("    %d. %s\n", i+1, SetLagu[idxset].AlbumLagu[i].JudulLagu.TabWord);
    }
    
}