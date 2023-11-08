#include "playlist.h"
#include "stdio.h"

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
    STARTCOMMAND();
    
}