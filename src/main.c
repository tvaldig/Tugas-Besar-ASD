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
        STARTCOMMAND();
        ConvertWordToString(&currentCommand, command);
        if (IsStringEqual(command, "START"))
        {
            if(checkCommand(command, false)){
                program = true;
                startFunction();
                printf(" start berhasil dijalankan\n");
            } else {
                wrongCommand();
            }
        }
        else if (IsStringEqual(command, "LOAD")){
            if (checkCommand(command, false))
            {
                program = true;
                printf("load berhasil dijalankan\n");
            }
            else
            {
                wrongCommand();
            }
        }
        else if (IsStringEqual(command, "HELP"))
        {
            if (checkCommand(command, false))
            {
                help(true);
                program = true;
            }
            else
            {
                wrongCommand();
            }
        } else {
            unknownCommand();
        }
    }
    

    
}