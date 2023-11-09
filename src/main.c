#include <stdio.h>
#include "boolean.h"
#include "COMMANDS/welcomeMenu/welcomemenu.h"
#include "COMMANDS/startload/startload.h"
#include "COMMANDS/invalidCommand/invalidCommand.h"
#include "COMMANDS/help/help.h"
#include "COMMANDS/list/list.h"
#include "ADT/ADT.h"


int main()
{
    boolean program = false;
    char command[100];
    //welcomeMenu();
    while(!program){
        printf(">>");
        STARTCOMMAND();
        ConvertWordToString(&currentCommand, command);
        if (checkCommand(command, inSession))
        {
            if(IsStringEqual(command, "START;")){
                Word fname = {"../save/new.txt",15};
                Word np = {"BLACKPINK", 9};
                Word p = {"BORN PINK", 9};
                Word s = {"SHUT DOWN", 9};
                startLoadFunction(fname, false);
                printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
                ListSingers(ArrayPenyanyi, ArrayPenyanyi.Neff);
                ListAlbums(mapAlbum, np);
                ListSongs(SetLagu, p, s);
            }else if(IsStringEqual(command, "LOAD")){
                STARTCOMMAND();
                if(currentCommand.TabWord[currentCommand.Length-1] == ';'){
                    currentCommand.TabWord[currentCommand.Length-1] = '\0';
                    currentCommand.Length--;
                    Word direktori = {"../save/",8};
                    startLoadFunction(ConcatString(direktori, currentCommand), true);
                }else{
                    unknownCommand();
                }
                

            }else if(IsStringEqual(command, "HELP")) {
                help(inSession);
            }
        }
    
    }
    
}