#include <stdio.h>
#include "boolean.h"
#include "COMMANDS/welcomeMenu/welcomemenu.h"
#include "COMMANDS/start/start.h"
#include "ADT/ADT.h"




int main()
{
    char command[100];
    char tes[100];
    char lagu[100];
    welcomeMenu();
    STARTCOMMAND();
    if (IsStringEqual(currentCommand.TabWord, "START"))
    {
        startFunction();
        
        ConvertWordToString(&ArrayPenyanyi.penyanyi[0].namapenyanyi, tes);
        printf("%s\n", tes);

        ConvertWordToString(&mapAlbum.Elements[2].AlbumName, tes);
        printf("%s\n", tes);
        for(int i = 0; i < mapAlbum.Count;i++){

           printf("%d\n", mapAlbum.Elements[i].Key);
        }
      
        }
}