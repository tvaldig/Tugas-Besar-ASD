#include <stdio.h>
#include "boolean.h"
#include "COMMANDS/welcomeMenu/welcomemenu.h"
#include "COMMANDS/start/start.h"
#include "COMMANDS/invalidCommand/invalidCommand.h"
#include "COMMANDS/help/help.h"
#include "ADT/ADT.h"




int main()
{
    boolean program = false, inSession = false;
    char command[100];
    char tes[100];
    char lagu[100];
    //welcomeMenu();
    while(!program){
        printf(">>");STARTCOMMAND();
        ConvertWordToString(&currentCommand, command);
        printf("%s\n", currentCommand.TabWord);
        if (checkCommand(command, false))
        {
            if(IsStringEqual(command, "START")){
                Word fname = {"../save/new.txt",15};
                startFunction(fname, false);
                inSession = true;
                printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");

            }else if(IsStringEqual(command, "LOAD")){
                CONTINUECOMMAND();
                Word direktori = {"../save/",8};
                startFunction(ConcatString(direktori, currentCommand), true);

            }else if(IsStringEqual(command, "HELP")) {
                help(inSession);
            }
        }
    }
    
}