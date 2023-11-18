#include <stdio.h>
#include "boolean.h"
#include  "./COMMANDS/commands.h"


int main()
{
    boolean program = false;
    char command[100];
    char nextcommand[100];
    //welcomeMenu();
    NotPlaying();
    while(!program){
        printf(">> ");
        STARTCOMMAND(true);
        ConvertWordToString(&currentCommand, command);
        if (checkCommand(command, inSession))
        {
            if(IsStringEqual(command, "START;")){
                Word fname = {"../save/new.txt", 15};
                startLoadFunction(fname, false);
                printf("\nFile konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n\n");
                inSession = true;
            }else if(IsStringEqual(command, "LOAD")){
                STARTCOMMAND(false);
                if(IsCommandWithSemicolon(currentCommand)){
                    handleSemicolon(currentCommand);
                    Word direktori = {"../save/",8};
                    startLoadFunction(ConcatString(direktori, currentCommand), true);
                }else{
                    unknownCommand();
                }
            }else if(IsStringEqual(command, "HELP;")) {
                help(inSession);
            } else if(IsStringEqual(command, "LIST"))
            {
                    STARTCOMMAND(false);
                    if (IsCommandWithSemicolon(currentCommand))
                    {
                        ConvertWordToString(&currentCommand, nextcommand);
                        if (IsStringEqual(nextcommand, "DEFAULT;"))
                        {
                            listDefaultFunction();
                        } else if(IsStringEqual(nextcommand, "PLAYLIST;"))
                        {
                            listPlaylistFunction();
                        }
                        else {
                            unknownCommand();
                        }
                }
            } else if(IsStringEqual(command, "QUEUE")){
                STARTCOMMAND(true);
                ConvertWordToString(&currentCommand, nextcommand);
                if (IsCommandWithSemicolon(currentCommand)){
                        if (IsStringEqual(nextcommand, "SONG;"))
                        {
                            QueueSong(&antrian);
                        }
                        else if (IsStringEqual(nextcommand, "CLEAR;"))
                        {
                            ClearQueue(&antrian);
                        }
                        else if (IsStringEqual(nextcommand, "PLAYLIST;"))
                        {
                            QueuePlaylist(&antrian, &playlists);  
                        }
                        else{
                            unknownCommand();
                        }
                } else {
                    if(IsStringEqual(nextcommand, "REMOVE")){
                        STARTCOMMAND(false);
                        if (IsCommandWithSemicolon(currentCommand))
                            {
                                handleSemicolon(currentCommand);
                                int inputval = ConvertWordToInt(currentCommand);
                                QueueRemove(&antrian, inputval);
                        } else {
                            unknownCommand();
                        }
                    } else if(IsStringEqual(nextcommand, "SWAP")){
                        STARTCOMMAND(true);
                        if(IsCommandWithSemicolon(currentCommand)){
                            printf("Masukan id selanjutnya!\n");
                        } else {
                            int inputval1 = ConvertWordToInt(currentCommand);
                            STARTCOMMAND(false);
                            if (IsCommandWithSemicolon(currentCommand))
                            {
                                handleSemicolon(currentCommand);
                                int inputval2 = ConvertWordToInt(currentCommand);
                                QueueSwap(&antrian, inputval1, inputval2);
                            }
                        }
                        
                    } else {
                        unknownCommand();
                    }
                    
                }
            
            }else if(IsStringEqual(command, "PLAYLIST"))
            {
                PLAYLIST();
            }else if(IsStringEqual(command, "SAVE"))
            {
                SAVE();
            } 
            else if(IsStringEqual(command, "PLAY")){
                STARTCOMMAND(false);
                ConvertWordToString(&currentCommand, nextcommand);
                if(IsCommandWithSemicolon(currentCommand)){
                    if(IsStringEqual(nextcommand, "SONG;")){
                        PlaySong();
                    }
                    else if (IsStringEqual(nextcommand, "PLAYLIST;"))
                    {
                        PlayPlaylist();
                    }
                    else
                    {
                        unknownCommand();
                    }
                }
                else{
                    unknownCommand();
                }
            } 
            else if(IsStringEqual(command, "SONG"))
            {
                STARTCOMMAND(false);
                ConvertWordToString(&currentCommand, nextcommand);
                if (IsCommandWithSemicolon(currentCommand))
                {
                    if (IsStringEqual(nextcommand, "NEXT;"))
                    {
                        SongNext();
                    }
                    else if (IsStringEqual(nextcommand, "PREVIOUS;"))
                    {
                        SongPrevious();
                    }
                    else
                    {
                        unknownCommand();
                    }
                }
            }
            else if (IsStringEqual(command, "STATUS;")){
                status(&antrian,ArrayPenyanyi, SetLagu, mapAlbum);
            }
        }
    }
}
    
    

    
