#include <stdio.h>
#include "boolean.h"
#include "COMMANDS/welcomeMenu/welcomemenu.h"
#include "COMMANDS/start/start.h"
#include "ADT/ADT.h"

int main()
{
    char command[100];
    welcomeMenu();
    STARTCOMMAND();
    if (IsStringEqual(currentCommand.TabWord, "START"))
    {
        startFunction();
    }
}