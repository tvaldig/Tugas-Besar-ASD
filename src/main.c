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
    welcomeMenu();
    while(!program){
        printf(">>");STARTCOMMAND();
        ConvertWordToString(&currentCommand, command);
        if (checkCommand(command, false))
        {
            if(IsStringEqual(command, "START")){
                printf("Start berhasil\n");
            } else if(IsStringEqual(command, "LOAD")){
                printf("Load berhasil\n");
            } else if(IsStringEqual(command, "HELP")) {
                help(false);
            }
        }
    
    }
    
}