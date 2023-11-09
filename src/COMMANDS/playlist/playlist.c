#include "playlist.h"
#include "stdio.h"
#include "../commands.h"

void PLAYLIST(){
    STARTCOMMAND();
    if(IsStringEqual(currentCommand.TabWord,"CREATE;")){
        CREATE_PLAYLIST();

     }else{ // bila tidak diakhiri dengan ';'
        unknownCommand();
        return;
     }
}

void CREATE_PLAYLIST(){
    printf("\nMasukkan nama playlist yang ingin dibuat : ");
    STARTCOMMANDONELINE();

    int i = 0, count = 0;

    while(currentCommand.Length > i){
        if(currentCommand.TabWord[i] != ' '){
            count++;
        }
        i++;
    }

    if(currentCommand.TabWord[currentCommand.Length-1] == ';'){
        REMOVESEMICOLON();
    }else{
        unknownCommand();
        return;
    }

    if(count >= 3){
        InsertLastArrayDin(&playlists, currentCommand);
        printf("\nPlaylist %s berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n\n", currentCommand.TabWord);
    }else{
        printf("\nMinimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n\n");
    }

    PrintArrayDin(playlists);
    CreateEmpty(&(playlists.A[playlists.Neff-1]));
    printf("%s\n", playlists.A[playlists.Neff-1].namaplaylist.TabWord);
    PrintInfo(playlists.A[playlists.Neff-1]);

}