#include <stdio.h>
#include "boolean.h"
#include "COMMANDS/welcomeMenu/welcomemenu.h"
#include "COMMANDS/start/start.h"
#include "ADT/ADT.h"

int main()
{
    /*
    Penyanyi P[100];
    TabInt ListDefault;
    MakeEmpty(&ListDefault);
    char command[100];
    welcomeMenu();
    STARTCOMMAND();
    ConvertWordToString(&currentCommand, command);
    if (IsStringEqual(command, "START"))
    {
        startFunction();
    }
    */
    Penyanyi P[5];

    P[0].nama.Length = 4;
    P[0].nama.TabWord[0] = 't';
    P[0].nama.TabWord[1] = 'e';
    P[0].nama.TabWord[2] = 's';
    P[0].nama.TabWord[3] = 't'; /* Nama Buat Penyanyi */

    P[0].album[0].nama.TabWord[0] = 't'; /* Nama Album */

    P[0].album[0].Lagu.TI[0] = '1'; /* Nama Lagu */

    printf("%s\n", P[0].nama.TabWord);
    printf("%s\n", P[0].album[0].nama.TabWord);
    printf("%s\n", P[0].album[0].Lagu.TI);
    
}