#include <stdio.h>
#include "boolean.h"
#include "./COMMANDS/commands.h"


int main()
{
    boolean program = false;
    char command[100];
    char nextcommand[100];
    //welcomeMenu();
    while(!program){
        printf(">>");
        STARTCOMMAND(true);
        ConvertWordToString(&currentCommand, command);
        if(!inSession){
            if (checkCommand(command, inSession))
            {
                if(IsStringEqual(command, "START;")){
                    Word fname = {"../save/new.txt",15};
                    startLoadFunction(fname, false);
                    printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n\n");

                }else if(IsStringEqual(command, "LOAD")){
                    STARTCOMMAND();
                    if(IsCommandWithSemicolon(currentCommand)){
                        handleSemicolon(currentCommand);
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

