#include <stdio.h>
#include "boolean.h"
#include  "./COMMANDS/commands.h"


int main()
{
    boolean program = false;
    char command[100];
    char nextcommand[100];
    //welcomeMenu();
    while(!program){
        printf(">> ");
        STARTCOMMAND(true);
        ConvertWordToString(&currentCommand, command);
        if (checkCommand(command, inSession))
        {
            if(IsStringEqual(command, "START;")){
                Word fname = {"../save/new.txt", 15};
                startLoadFunction(fname, false);
                printf("\nFile konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n\n");
                inSession = true;
            }else if(IsStringEqual(command, "LOAD")){
                STARTCOMMAND(false);
                if(IsCommandWithSemicolon(currentCommand)){
                    handleSemicolon(currentCommand);
                    Word direktori = {"../save/",8};
                    startLoadFunction(ConcatString(direktori, currentCommand), true);
                }else{
                    unknownCommand();
                }
            }else if(IsStringEqual(command, "HELP;")) {
                help(inSession);
            } else if(IsStringEqual(command, "LIST"))
            {
                    STARTCOMMAND(false);
                    if (IsCommandWithSemicolon(currentCommand))
                    {
                        ConvertWordToString(&currentCommand, nextcommand);
                        if (IsStringEqual(nextcommand, "DEFAULT;"))
                        {
                            listDefaultFunction();
                        } else if(IsStringEqual(nextcommand, "PLAYLIST;"))
                        {
                            listPlaylistFunction();
                        } 
                    }
            }else if(checkCommand(command, inSession))
                {
                    if(IsStringEqual, "PLAYLIST")
                    {
                    PLAYLIST();
                    }
                }   
        }
    }
               
}
    

    
