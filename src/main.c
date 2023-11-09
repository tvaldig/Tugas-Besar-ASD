#include <stdio.h>
#include "boolean.h"
#include "./COMMANDS/commands.h"


int main()
{
    boolean program = false;
    char command[100];
    while(!program){
        printf(">>");
        STARTCOMMAND();
        ConvertWordToString(&currentCommand, command);
        if (checkCommand(command, inSession))
        {
            if(IsStringEqual(command, "START;")){
                Word fname = {"../save/new.txt",15};
                startLoadFunction(fname, false);
                printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");

            }else if(IsStringEqual(command, "LOAD")){
                STARTCOMMAND();
                if(currentCommand.TabWord[currentCommand.Length-1] == ';'){
                    currentCommand.TabWord[currentCommand.Length-1] = '\0';
                    currentCommand.Length--;
                    Word direktori = {"../save/",8};
                    startLoadFunction(ConcatString(direktori, currentCommand), true);
                }else{
                    unknownCommand();
                }
                

                }else if(IsStringEqual(command, "HELP")) {
                    help(inSession);
                }
            }
        }else{
            if(checkCommand(command, inSession)){
                if(IsStringEqual, "PLAYLIST"){
                    PLAYLIST();
                }
            }   
        }
    
    }
    
}