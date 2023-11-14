#include "play.h"

NowPlaying current;

void PlaySong (){
    char namapenyanyi[100];
    char judullagu[100];
    //Menuliskan daftar penyanyi
    ListSingers(ArrayPenyanyi, ArrayPenyanyi.Neff);

    //Menerima input nama penyanyi dari user dan mencari idpenyanyi tersebut 
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    STARTCOMMAND(false);
    handleSemicolon(currentCommand);
    ConvertWordToString(&currentCommand, namapenyanyi);
    IdxType idPenyanyi = searchidpenyanyi(ArrayPenyanyi, currentCommand);

    //Menuliskan daftar album
    ListAlbums(mapAlbum, currentCommand);

    //Menerima input nama album dari user dan mencari idalbum tersebut
    printf("Masukkan Nama Album yang dipilih : ");
    STARTCOMMAND(false);
    handleSemicolon(currentCommand);
    Word NamaAlbum = currentCommand;
    IdxType idAlbum = searchidalbum(ArrayPenyanyi, idPenyanyi, currentCommand, mapAlbum);

    //Menuliskan daftar lagu
    ListSongs(SetLagu, currentCommand, idPenyanyi);

    //Menerima input id lagu dari user
    printf("Masukkan ID Lagu yang dipilih : ");
    STARTCOMMAND(false);
    handleSemicolon(currentCommand);
    IdxType idLagu = ConvertWordToInt(currentCommand);
    Word JudulLaguWord = GetJudulLagu(SetLagu, NamaAlbum, idLagu, idPenyanyi);
    ConvertWordToString(&JudulLaguWord, judullagu);

    //Memasukkan id dari tiap input ke lagu yang dimainkan
    (&current)->lagu = idLagu;
    (&current)->album = idAlbum;
    (&current)->penyanyi = idPenyanyi;

    //Mengosongkan antrian dan riwayat
    CreateQueue(&antrian);
    CreateEmptyStack(&riwayat);
    printf("Memutar lagu %s oleh %s.\n", judullagu, namapenyanyi);
}

void PlayPlaylist() {
    printf("Masukkan ID Playlist: ");
    STARTCOMMAND(false);
    handleSemicolon(currentCommand);
    int idPlaylist = ConvertWordToInt(currentCommand)-1;
    if(idPlaylist > playlists.Neff){
        printf("ID Playlist tidak ditemukan!\n");
    }
    else{
    playlist p = playlists.A[idPlaylist];
    addressnode P = First(p);
    CreateQueue(&antrian);
    CreateEmptyStack(&riwayat);
    while( P != null){
        enqueue(&antrian, PENYANYI(P), ALBUM(P), LAGU(P));
        Push(&riwayat,PENYANYI(P), ALBUM(P), LAGU(P));
        P=Next(P);
    }
    Reversestack(&riwayat);
    dequeue(&antrian, &(&current)->penyanyi, &(&current)->album, &(&current)->lagu);
    printf("Memutar playlist %s", p.namaplaylist.TabWord);
    }
}
    
    
void NotPlaying (){
    (&current)->penyanyi = IdxUndef;
    (&current)->album = IdxUndef;
    (&current)->lagu = IdxUndef;
}

boolean isPlaying (){
    return current.penyanyi == IdxUndef && 
    current.album == IdxUndef && 
    current.lagu == IdxUndef;
}