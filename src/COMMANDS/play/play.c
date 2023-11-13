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

void PlaySong (Queue *antrian, Stack *riwayat){

    CreateQueue(antrian);
    CreateEmptyStack(riwayat);
}

void PlayPlaylist(Queue *antrian, Stack *riwayat, ArrayDin *playlists) {
    ArrayDin array;
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
    while( P != null){
        enqueue(antrian, PENYANYI(P), ALBUM(P), LAGU(P));
        Push(riwayat,PENYANYI(P), ALBUM(P), LAGU(P));
        P=Next(P);
    }
    Reversestack(riwayat);
    printf("Memutar playlist %s", p.namaplaylist.TabWord);
    }
}
    
    
    // printf("Daftar Penyanyi: \n");
    // for (int i = 0 ; i < ArrPenyanyi.Neff; i++ ){
    //     printf("%d. ", (i+1));
    //     displayWord(ArrPenyanyi.penyanyi[i].namapenyanyi);
    // }
    // Word pilihanPenyanyi;
    // printf("Masukkan Nama Penyanyi yang dipilih : ");
    
