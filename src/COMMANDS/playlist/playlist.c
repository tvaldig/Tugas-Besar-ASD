#include "playlist.h"
#include "stdio.h"
#include "../commands.h"

void PLAYLIST(){
    STARTCOMMAND();
    if(IsStringEqual(currentCommand.TabWord,"CREATE;")){
        CREATE_PLAYLIST();
    }else if(IsStringEqual(currentCommand.TabWord, "ADD")){
        STARTCOMMAND();
        if(IsStringEqual(currentCommand.TabWord,"SONG;")){
            ADD_SONG_PLAYLIST();
        }else if (IsStringEqual(currentCommand.TabWord,"ALBUM;")){
            printf("add album\n");
        }else{
            unknownCommand();
        }

     }else{ // bila tidak diakhiri dengan ';'
        unknownCommand();
        return;
     }
}

void CREATE_PLAYLIST(){
    printf("\nMasukkan nama playlist yang ingin dibuat : ");
    STARTCOMMANDONELINE();

    int i = 0, count = 0;

    if(currentCommand.TabWord[currentCommand.Length-1] == ';'){
        handleSemicolon(currentCommand);
    }else{
        unknownCommand();
        return;
    }

    while(currentCommand.Length > i){
        if(currentCommand.TabWord[i] != ' '){
            count++;
        }
        i++;
    }

    if(count >= 3){
        InsertLastArrayDin(&playlists, currentCommand);
        CreateEmpty(&(playlists.A[playlists.Neff-1]));
        printf("\nPlaylist %s berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n\n", currentCommand.TabWord);
    }else{
        printf("\nMinimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n\n");
    }

}

void ADD_SONG_PLAYLIST(){
    printPenyanyi();
}