#include "play.h"
// void Play (){
//     STARTCOMMAND(true);
//     if(IsStringEqual(currentCommand.TabWord, "SONG;")){
//         PlaySong();
//     }
//     else if(IsStringEqual(currentCommand.TabWord, "PLAYLIST;"))
//     {
//         PlayPlaylist();
//     }else
//      { // bila tidak diakhiri dengan ';'
//         unknownCommand();
//         return;
//      }
// }

void PlaySong (Queue *antrian, Stack *riwayat, TabInt ArrPenyanyi, NowPlaying *current){
    printf("Daftar Penyanyi: \n");
    for (int i = 0 ; i < ArrPenyanyi.Neff; i++ ){
        printf("%d. ", (i+1));
        displayWord(ArrPenyanyi.penyanyi[i].namapenyanyi);
    }
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    STARTCOMMAND(false);
    handleSemicolon(currentCommand);


    CreateQueue(antrian);
    CreateEmptyStack(riwayat);
}

void PlayPlaylist(Queue *antrian, Stack *riwayat, ArrayDin *playlists, NowPlaying *current) {
    printf("Masukkan ID Playlist: ");
    STARTCOMMAND(false);
    handleSemicolon(currentCommand);
    int idPlaylist = ConvertWordToInt(currentCommand);
    if(idPlaylist > playlists->Neff){
        printf("ID Playlist tidak ditemukan!\n");
    }
    else{
    playlist p = playlists->A[idPlaylist];
    addressnode P = First(p);
    CreateQueue(antrian);
    CreateEmptyStack(riwayat);
    while( P != null){
        enqueue(antrian, PENYANYI(P), ALBUM(P), LAGU(P));
        Push(riwayat,PENYANYI(P), ALBUM(P), LAGU(P));
        P=Next(P);
    }
    Reversestack(riwayat);
    dequeue(antrian, (*current).penyanyi, (*current).album, (*current).lagu);
    printf("Memutar playlist %s", p.namaplaylist.TabWord);
    }
}
    
    
void NotPlaying (NowPlaying *current){
    (*current).penyanyi = IdxUndef;
    (*current).album = IdxUndef;
    (*current).lagu = IdxUndef;
}

boolean isPlaying (NowPlaying current){
    return current.penyanyi == IdxUndef && 
    current.album == IdxUndef && 
    current.lagu == IdxUndef;
}