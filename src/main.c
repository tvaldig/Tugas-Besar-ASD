#include <stdio.h>
#include "boolean.h"
#include "COMMANDS/welcomeMenu/welcomemenu.h"
#include "COMMANDS/start/start.h"
#include "ADT/ADT.h"

int main()
{
    Penyanyi P[100];
    TabInt ListDefault;
    MakeEmpty(&ListDefault);
    char command[100];
    welcomeMenu();
    STARTCOMMAND();
    ConvertWordToString(&currentCommand, command);
    if (IsStringEqual(command, "START"))
    {
        startFunction(&ListDefault);
    }

    
}