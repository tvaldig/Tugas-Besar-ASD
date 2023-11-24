#include <stdio.h>
#include "list.h"

void ListSingers(TabInt ArrayP, int singerCount)
{
    printf("\nDaftar Penyanyi : \n");
    for (int i = 0; i < singerCount; i++) {
        printf("%d. %s\n", i + 1, GetNamaPenyanyi(ArrayP, i).TabWord);
    }
}


void ListAlbums(MapAlbum MapAlb, Word NamaPenyanyi){
    int number = 0;
    int idalbumpertama = GetIdAlbumPertama(ArrayPenyanyi, searchidpenyanyi(ArrayPenyanyi, NamaPenyanyi));
    int jumlahalbum = GetJumlahAlbum(ArrayPenyanyi, searchidpenyanyi(ArrayPenyanyi, NamaPenyanyi));
    printf("\nDaftar Album oleh %s : \n", NamaPenyanyi.TabWord);
    for (int i = idalbumpertama; i < idalbumpertama + jumlahalbum; i++) {
        printf("%d. %s\n", number + 1, mapAlbum.Elements[i].AlbumName.TabWord);
        number++;
    }
}


void ListSongs(Set setLagu[], Word NamaAlbum, int idpenyanyi) {
    int idAlbum = searchidalbum(ArrayPenyanyi, idpenyanyi, NamaAlbum, mapAlbum);
    Set s = setLagu[Value(mapAlbum,idAlbum)];
    printf("Daftar Lagu di %s : \n", NamaAlbum.TabWord);
    for (int i = 0; i < s.Count; i++) {
        printf("%d. %s\n", i + 1, s.AlbumLagu[i].JudulLagu.TabWord);
    }
}


void ListPlaylists(ArrayDin Playlist, int playlistCount)
{
    for (int i = 0; i < playlistCount; i++) {
        printf("%d. %s\n", i + 1, Playlist.A[i].namaplaylist.TabWord);
    }
    printf("\n");
}

void listDefaultFunction(){
    char yn[2];
    ListSingers(ArrayPenyanyi,ArrayPenyanyi.Neff);
    printf("\nIngin melihat album yang ada?(Y/N) : ");
    STARTCOMMAND(false);
    ConvertWordToString(&currentCommand, yn);
    if(IsStringEqual(yn, "Y;"))
    {
        printf("\nPilih penyanyi untuk melihat album mereka : ");
        STARTCOMMAND(false); 
        handleSemicolon(currentCommand);
        int idpenyanyi = searchidpenyanyi(ArrayPenyanyi, currentCommand);
        if(idpenyanyi == -1){
            printf("\nNama penyanyi tidak ditemukan!\n\n");
        } else {
            ListAlbums(mapAlbum, currentCommand);
            printf("\nIngin melihat lagu yang ada?(Y/N) : ");
            STARTCOMMAND(false);
            ConvertWordToString(&currentCommand, yn);
            if (IsStringEqual(yn, "Y;"))
            {
                printf("\nPilih album untuk melihat lagu yang ada di album : ");
                STARTCOMMAND(false);
                printf("\n");
                handleSemicolon(currentCommand);
                int idalbum = searchidalbum(ArrayPenyanyi, idpenyanyi, currentCommand, mapAlbum);
                if(idalbum == -1) {
                    printf("Nama album tidak ditemukan!\n\n");
                } else {
                    ListSongs(SetLagu, currentCommand, idpenyanyi);
                    printf("\n");
                }           
            }
            else if (IsStringEqual(yn, "N;"))
            {
                printf("\n");
            } else {
                printf("\nGagal. Masukan bukan Y/N.\n\n");
            }
        }
    } else if(IsStringEqual(yn, "N;")){
      printf("\n");
    } else{
        printf("\nGagal. Masukan bukan Y/N.\n\n");
    }
}

void listPlaylistFunction(){
    printf("\nDaftar playlist yang kamu miliki : \n") ;
    if (IsEmptyArrayDin(playlists))
    {
        printf("Kamu tidak memiliki playlist.\n\n");
    } else {
        ListPlaylists(playlists, playlists.Neff);
    }
}