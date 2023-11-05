#include <stdio.h>
#include "boolean.h"
#include "COMMANDS/welcomeMenu/welcomemenu.h"
#include "COMMANDS/start/start.h"
#include "COMMANDS/invalidCommand/invalidCommand.h"
#include "COMMANDS/help/help.h"
#include "ADT/ADT.h"




int main()
{
    boolean program = false;
    char command[100];
    char tes[100];
    char lagu[100];
    welcomeMenu();
    while(!program){
        printf(">>");STARTCOMMAND();
        ConvertWordToString(&currentCommand, command);
        if (checkCommand(command, false))
        {
            if(IsStringEqual(command, "START")){
                if(currentChar == ' '){
                    STARTCOMMAND();
                    printf("Command tidak diketahui\n");
                }else{
                    Word fname = {"../save/new.txt",15};
                    startFunction(fname);
                    printf("Start berhasil\n");
                }
            } else if(IsStringEqual(command, "LOAD")){
                if(currentChar == '\n'){
                    printf("Command tidak diketahui\n");
                }else{
                    STARTCOMMAND();
                    Word direktori = {"../save/",8};
                    startFunction(ConcatString(direktori, currentCommand));
                    printf("Load berhasil\n");
                }
            } else if(IsStringEqual(command, "HELP")) {
                help(false);
            }
        }
    
    }
    
}