#include <stdio.h>
#include "list.h"

int SearchPenyanyi(Word Nama){
    char penyanyiarr[100];
    char nama[100];
    ConvertWordToString(&Nama, nama);
    for (int i = 0; i < ArrayPenyanyi.Neff; i++)
    {
        ConvertWordToString(&ArrayPenyanyi.penyanyi[i].namapenyanyi, penyanyiarr);
        if(IsStringEqual(penyanyiarr, nama)){
            return i;
        }
    }
}

int GetIdAlbum(Word NamaAlbum)
{
    char namaalbumarr[100];
    char nama[100];
    ConvertWordToString(&NamaAlbum, nama);
    for (int i = 0; i < mapAlbum.Count; i++)
    {
        ConvertWordToString(&mapAlbum.Elements[i].AlbumName, namaalbumarr);
        if (IsStringEqual(namaalbumarr,nama))
        {
            return mapAlbum.Elements[i].Key;
        }
    }
}

int SearchLagu(Word Lagu)
{
    for (int i = 0; i < SetLagu->Count; i++)
    {
        if (SetLagu->AlbumLagu[i].JudulLagu.TabWord == Lagu.TabWord)
        {
            return i;
        }
    }
}
// Fungsi untuk menampilkan daftar penyanyi
void ListSingers(TabInt ArrayP, int singerCount)
{
    printf("Daftar Penyanyi:\n");
    for (int i = 0; i < singerCount; i++) {
        printf("%d. %s\n", i + 1, GetNamaPenyanyi(ArrayP, i).TabWord);
    }
}

// Fungsi untuk menampilkan daftar album penyanyi
void ListAlbums(MapAlbum MapAlb, Word NamaPenyanyi){
    int idalbumpertama = GetIdAlbumPertama(ArrayPenyanyi, SearchPenyanyi(NamaPenyanyi));
    int jumlahalbum = GetJumlahAlbum(ArrayPenyanyi, SearchPenyanyi(NamaPenyanyi));
    printf("Daftar Album oleh %s:\n", NamaPenyanyi.TabWord);
    for (int i = idalbumpertama; i < jumlahalbum; i++) {
        printf("%d. %s\n", i + 1, mapAlbum.Elements[i].AlbumName.TabWord);
    }
}

// Fungsi untuk menampilkan daftar lagu dalam album
void ListSongs(Set setLagu[], Word NamaAlbum, Word JudulLagu) {
    int idAlbum = GetIdAlbum(NamaAlbum);
    Set s = setLagu[Value(mapAlbum,idAlbum)];
    printf("Daftar Lagu di %s:\n", NamaAlbum.TabWord);
    for (int i = 0; i < s.Count; i++) {
        printf("%d. %s\n", i + 1, s.AlbumLagu[i].JudulLagu.TabWord);
    }
}

// Fungsi untuk menampilkan daftar playlist pengguna
void ListPlaylists(ArrayDin Playlist, int playlistCount)
{
    printf("Daftar playlist yang kamu miliki:\n");
    for (int i = 0; i < playlistCount; i++) {
        printf("%d. %s\n", i + 1, Playlist.A[i].namaplaylist.TabWord);
    }
}

void listDefaultFunction(){
    char yn[2];
    ListSingers(ArrayPenyanyi,ArrayPenyanyi.Neff);
    printf("Ingin melihat album yang ada?(Y/N) :");
    STARTCOMMAND();
    if(IsCommandWithSemicolon(currentCommand)){
        handleSemicolon(currentCommand);
        ConvertWordToString(&currentCommand, yn);
        if(IsStringEqual(yn, "Y")){
            printf("Pilih penyanyi untuk melihat album mereka: \n");
            ADVCOMMAND();
            handleSemicolon(currentCommand);
            ListAlbums(mapAlbum, currentCommand);
            printf("Ingin melihat lagu yang ada?(Y/N): ");
            ADVCOMMAND();
            handleSemicolon(currentCommand);
            ConvertWordToString(&currentCommand, yn);
            if (IsStringEqual(yn, "Y"))
            {
            }
    }
}