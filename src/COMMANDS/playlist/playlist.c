#include "playlist.h"
#include "stdio.h"
#include "../commands.h"

void PLAYLIST(){
    STARTCOMMAND();
    if(IsStringEqual(currentCommand.TabWord,"CREATE;")){
        CREATE_PLAYLIST();
    }else if(IsStringEqual(currentCommand.TabWord, "ADD")){
        STARTCOMMAND();
        if(IsStringEqual(currentCommand.TabWord,"SONG;")){
            ADD_SONG_PLAYLIST();
        }else if (IsStringEqual(currentCommand.TabWord,"ALBUM;")){
            printf("add album\n");
        }else{
            unknownCommand();
        }

     }else{ // bila tidak diakhiri dengan ';'
        unknownCommand();
        return;
     }
}

void CREATE_PLAYLIST(){
    printf("\nMasukkan nama playlist yang ingin dibuat : ");
    STARTCOMMANDONELINE();

    int i = 0, count = 0;

    if(currentCommand.TabWord[currentCommand.Length-1] == ';'){
        handleSemicolon(currentCommand);
    }else{
        unknownCommand();
        return;
    }

    while(currentCommand.Length > i){
        if(currentCommand.TabWord[i] != ' '){
            count++;
        }
        i++;
    }

    if(count >= 3){
        InsertLastArrayDin(&playlists, currentCommand);
        CreateEmpty(&(playlists.A[playlists.Neff-1]));
        printf("\nPlaylist %s berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n\n", currentCommand.TabWord);
    }else{
        printf("\nMinimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n\n");
    }

}

void ADD_SONG_PLAYLIST(){
    printPenyanyi(); // Menampilkan list penyanyi yang ada di program

    printf("\nMasukkan Nama Penyanyi yang dipilih : ");
    STARTCOMMANDONELINE(); // Menerima input penyanyi dari user
    
    if(IsCommandWithSemicolon(currentCommand))
    { // Mengecek apakah command diakhiri dengan semicolon
        handleSemicolon(currentCommand); // Menghilangkan semicolon di input
        
        int idxpenyanyi = searchidpenyanyi(ArrayPenyanyi, currentCommand); // Mencari idpenyanyi berdasarkan nama yang diinput oleh user

        if(idxpenyanyi != -1)
        { 
            printAlbum(idxpenyanyi); // Menampilkan album yang dimiliki oleh penyanyi tersebut

            printf("\nMasukkan Judul Album yang dipilih : ");
            STARTCOMMANDONELINE(); // Menerima input album dari user

            if(IsCommandWithSemicolon(currentCommand))
            {
                handleSemicolon(currentCommand); // Menghilangkan semicolon di input

                int idxalbum = searchidalbum(ArrayPenyanyi, idxpenyanyi, currentCommand, mapAlbum); // Mencari idxalbum dari inputan user

                if(idxalbum != -1)
                {
                    printLagu(idxalbum, idxpenyanyi); // Menampilkan lagu yang dimiliki oleh album tersebut

                    printf("\nMasukkan ID Lagu yang dipilih : ");
                    STARTCOMMAND(); // Menerima input lagu dari user

                    if(IsCommandWithSemicolon(currentCommand))
                    {
                        handleSemicolon(currentCommand); // Menghilangkan semicolon di input

                        int idxlagu = ConvertWordToInt(currentCommand);

                        int idxset = Value(mapAlbum, idxalbum); // Mencari idxset dari ID album yang diinput oleh user

                        if(idxlagu > SetLagu[idxset].Count -1 || idxlagu < 0){ // Cek apabila ID inputan user diluar yang seharusnya
                            printf("Lagu dengan ID %d tidak ada dalam daftar. Silakan coba lagi.\n\n", idxlagu);
                            return;
                        }
                    }else
                    { // Bila command tidak diakhiri dengan semicolon 
                        unknownCommand();
                        return;
                    }

                }else
                {
                    printf("Album %s tidak ada dalam daftar. Silakan coba lagi.\n\n", currentCommand.TabWord);
                    return;
                }
            }else
            { // Bila command tidak diakhiri dengan semicolon
                unknownCommand();
                return;
            }

        }else
        { // Bila inputan user salah
            printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi.\n\n", currentCommand.TabWord);
            return;
        }
    }else
    { // Bila command tidak diakhiri dengan semicolon
        unknownCommand();
        return;
    }

    
    printPlaylist();

}
