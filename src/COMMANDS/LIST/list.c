#include <stdio.h>
#include "list.h"

// Fungsi untuk menampilkan daftar penyanyi
void ListSingers(TabInt ArrayP, int singerCount)
{
    printf("\nDaftar Penyanyi : \n");
    for (int i = 0; i < singerCount; i++) {
        printf("%d. %s\n", i + 1, GetNamaPenyanyi(ArrayP, i).TabWord);
    }
}

// Fungsi untuk menampilkan daftar album penyanyi
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

// Fungsi untuk menampilkan daftar lagu dalam album
void ListSongs(Set setLagu[], Word NamaAlbum, int idpenyanyi) {
    int idAlbum = searchidalbum(ArrayPenyanyi, idpenyanyi, NamaAlbum, mapAlbum);
    Set s = setLagu[Value(mapAlbum,idAlbum)];
    printf("\nDaftar Lagu di %s : \n", NamaAlbum.TabWord);
    for (int i = 0; i < s.Count; i++) {
        printf("%d. %s\n", i + 1, s.AlbumLagu[i].JudulLagu.TabWord);
    }
}

// Fungsi untuk menampilkan daftar playlist pengguna
void ListPlaylists(ArrayDin Playlist, int playlistCount)
{
    for (int i = 0; i < playlistCount; i++) {
        printf("%d. %s\n", i + 1, Playlist.A[i].namaplaylist.TabWord);
    }
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
        STARTCOMMAND(false); printf("\n");
        handleSemicolon(currentCommand);
        int idpenyanyi = searchidpenyanyi(ArrayPenyanyi, currentCommand);
        if(idpenyanyi == -1){
            printf("\nNama penyanyi tidak ditemukan!\n");
        } else {
            ListAlbums(mapAlbum, currentCommand);
            printf("\nIngin melihat lagu yang ada?(Y/N) : ");
            STARTCOMMAND(false);
            printf("\n");
            ConvertWordToString(&currentCommand, yn);
            if (IsStringEqual(yn, "Y;"))
            {
                printf("\nPilih album untuk melihat lagu yang ada di album : ");
                STARTCOMMAND(false);
                printf("\n");
                handleSemicolon(currentCommand);
                int idalbum = searchidalbum(ArrayPenyanyi, idpenyanyi, currentCommand, mapAlbum);
                if(idalbum == -1) {
                    printf("\nNama album tidak ditemukan!\n");
                } else {
                    ListSongs(SetLagu, currentCommand, idpenyanyi);
                }           
            }
            else if (IsStringEqual(yn, "N;"))
            {
                
            } else {
                printf("\nGagal. Masukan bukan Y/N.\n");
            }
        }
    } else if(IsStringEqual(yn, "N;")){
      
    } else{
        printf("\nGagal. Masukan bukan Y/N.\n");
    }
}

void listPlaylistFunction(){
    printf("\nDaftar playlist yang kamu miliki : \n") ;
    if (IsEmptyArrayDin(playlists))
    {
        printf("\nKamu tidak memiliki playlist.\n");
    } else {
        ListPlaylists(playlists, playlists.Neff);
    }
}