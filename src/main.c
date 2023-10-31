#include <stdio.h>
#include "boolean.h"
#include "COMMANDS/welcomeMenu/welcomemenu.h"
#include "COMMANDS/start/start.h"

int main()
{
    TabInt ListDefault;
    MakeEmpty(&ListDefault);
    char command[100];
    welcomeMenu();
    STARTCOMMAND();
    ConvertWordToString(&currentCommand, command);
    if (IsStringEqual(command, "START"))
    {
        startFunction(&ListDefault);
        if(currentWord.Length != 0) printf("selesai\n");
    }

    
}