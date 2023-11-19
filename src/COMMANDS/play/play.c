#include "play.h"

NowPlaying current;
currentid currentIdPlaylist;
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
    IdxType idLagu = ConvertWordToInt(currentCommand)-1;
    Word JudulLaguWord = GetJudulLagu(SetLagu, NamaAlbum, idLagu+1, idPenyanyi);
    ConvertWordToString(&JudulLaguWord, judullagu);

    //Memasukkan id dari tiap input ke lagu yang dimainkan
    (&current)->lagu = idLagu;
    (&current)->album = idAlbum;
    (&current)->penyanyi = idPenyanyi;

    //Mengosongkan antrian dan riwayat
    CreateQueue(&antrian);
    CreateEmptyStack(&riwayat);

    NotPlayingPlaylist();
    printf("Memutar lagu \"%s\" oleh \"%s\".\n", judullagu, namapenyanyi);
}

void PlayPlaylist() {
    printf("Masukkan ID Playlist: ");
    
    //Menerima input
    STARTCOMMAND(false);
    handleSemicolon(currentCommand);
    int idPlaylist = ConvertWordToInt(currentCommand);
    currentIdPlaylist = idPlaylist;
    //Mengecek ada tidaknya input di playlist
    if(idPlaylist > playlists.Neff){
        printf("ID Playlist tidak ditemukan!\n");
    }
    else{
    playlist p = playlists.A[idPlaylist];
    addressnode P = First(p);

    //Mengosongkan antrian dan riwayat
    CreateQueue(&antrian);
    CreateEmptyStack(&riwayat);

    while( P != null){
        //Memasukkan seluruh isi playlist ke antrian
        enqueue(&antrian, PENYANYI(P), ALBUM(P), LAGU(P));
        P=Next(P);
        //Memasukkan isi playlist ke stack dimulai dari lagu kedua
        if (P!=null){
            Push(&riwayat,PENYANYI(P), ALBUM(P), LAGU(P));
        }
    }
    //Membalikkan isi riwayat
    Reversestack(&riwayat);
    
    //Mengambil lagu pertama dari antrian menjadi current song; antrian sekarang dimulai dari lagu kedua
    dequeue(&antrian, &(&current)->penyanyi, &(&current)->album, &(&current)->lagu);

    //Output
    printf("Memutar playlist \"%s\".\n", p.namaplaylist.TabWord);
    }
}
    
    
void NotPlaying(){
    (&current)->penyanyi = IdxUndef;
    (&current)->album = IdxUndef;
    (&current)->lagu = IdxUndef;
}

void NotPlayingPlaylist(){
    currentIdPlaylist = IdxUndef;
}

boolean isNotPlayingPlaylist(){
    return currentIdPlaylist == IdxUndef;
}

boolean isNotPlaying (){
    return current.penyanyi == IdxUndef && 
    current.album == IdxUndef && 
    current.lagu == IdxUndef;
}