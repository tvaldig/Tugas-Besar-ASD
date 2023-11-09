#include "playlist.h"
#include "stdio.h"
#include "../commands.h"

int idxplaylist, idxpenyanyi, idxalbum, idxlagu, idxset;

void PLAYLIST(){
    STARTCOMMAND();
    if(IsStringEqual(currentCommand.TabWord,"CREATE;")){
        CREATE_PLAYLIST();
    }else if(IsStringEqual(currentCommand.TabWord, "ADD")){
        STARTCOMMAND();
        if(IsStringEqual(currentCommand.TabWord,"SONG;")){
            ADD_SONG_PLAYLIST();
        }else if (IsStringEqual(currentCommand.TabWord,"ALBUM;")){
            ADD_ALBUM_PLAYLIST();
        }else{
            unknownCommand();
        }

     }else{ // bila tidak diakhiri dengan ';'
        unknownCommand();
        return;
     }
}

void CREATE_PLAYLIST(){
    printf("\nMasukkan nama playlist yang ingin dibuat : "); // Menerima input nama playlist
    STARTCOMMANDONELINE();

    int i = 0, count = 0;

    if(currentCommand.TabWord[currentCommand.Length-1] == ';'){ // Mengecek apakah inputan terakhir dari user merupakan semicolon
        handleSemicolon(currentCommand);
    }else{
        unknownCommand();
        return;
    }

    while(currentCommand.Length > i){ // Mengecek apakah syarat minimum 3 karakter selain whitespace terpenuhi atau tidak
        if(currentCommand.TabWord[i] != ' '){
            count++;
        }
        i++;
    }

    if(count >= 3){
        InsertLastArrayDin(&playlists, currentCommand); // Menambahkan playlist dengan nama sesuai dengan keinginan user
        CreateEmpty(&(playlists.A[playlists.Neff-1])); // Mendeclare playlist kosong
        printf("\nPlaylist %s berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n\n", currentCommand.TabWord);
    }else{
        printf("\nMinimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n\n"); // Bila tidak memenuhi syarat minimum 3 karakter
    }

}

void ADD_ALBUM_PLAYLIST(){
    printPenyanyi(); // Menampilkan list penyanyi yang ada di program

    printf("\nMasukkan Nama Penyanyi yang dipilih : ");
    STARTCOMMANDONELINE(); // Menerima input penyanyi dari user
    
    if(IsCommandWithSemicolon(currentCommand))
    { // Mengecek apakah command diakhiri dengan semicolon
        handleSemicolon(currentCommand); // Menghilangkan semicolon di input
        
        idxpenyanyi = searchidpenyanyi(ArrayPenyanyi, currentCommand); // Mencari idpenyanyi berdasarkan nama yang diinput oleh user

        if(idxpenyanyi != -1)
        { 
            printAlbum(idxpenyanyi); // Menampilkan album yang dimiliki oleh penyanyi tersebut

            printf("\nMasukkan Judul Album yang dipilih : ");
            STARTCOMMANDONELINE(); // Menerima input album dari user

            if(IsCommandWithSemicolon(currentCommand))
            {
                handleSemicolon(currentCommand); // Menghilangkan semicolon di input

                idxalbum = searchidalbum(ArrayPenyanyi, idxpenyanyi, currentCommand, mapAlbum); // Mencari idxalbum dari inputan user

                if(idxalbum == -1)
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

    printPlaylist(); // Menampilkan daftar playlist

    printf("\nMasukkan ID Playlist yang dipilih : "); // Menerima input ID Playlist dari user
    STARTCOMMANDONELINE();

    if(IsCommandWithSemicolon(currentCommand)){
        handleSemicolon(currentCommand); // Menghilangkan semicolon dari inputan user
        idxplaylist = ConvertWordToInt(currentCommand) - 1; // Mengubah word menjadi sebuah int

        if((idxplaylist > playlists.Neff-1) || (idxplaylist < 0))
        {
            printf("\nID Playlist %s tidak ada dalam daftar. Silakan coba lagi.\n\n", currentCommand.TabWord); // Bila inputan ID playlist diluar list yang diperbolehkan
            return;
        }
    }else{
        unknownCommand(); // Bila inputan tidak diakhiri dengan semicolon
        return;
    }

    idxset = Value(mapAlbum, idxalbum); // Mencari idxset dari Key idxalbum

    for(int i = 0; i < SetLagu[idxset].Count; i++){ // Memasukkan semua lagu dari Album ke Playlist
        InsertUnique(&(playlists.A[idxplaylist]),idxpenyanyi,idxalbum, i); 
    }
}


void ADD_SONG_PLAYLIST(){
    printPenyanyi(); // Menampilkan list penyanyi yang ada di program

    printf("\nMasukkan Nama Penyanyi yang dipilih : ");
    STARTCOMMANDONELINE(); // Menerima input penyanyi dari user
    
    if(IsCommandWithSemicolon(currentCommand))
    { // Mengecek apakah command diakhiri dengan semicolon
        handleSemicolon(currentCommand); // Menghilangkan semicolon di input
        
        idxpenyanyi = searchidpenyanyi(ArrayPenyanyi, currentCommand); // Mencari idpenyanyi berdasarkan nama yang diinput oleh user

        if(idxpenyanyi != -1)
        { 
            printAlbum(idxpenyanyi); // Menampilkan album yang dimiliki oleh penyanyi tersebut

            printf("\nMasukkan Judul Album yang dipilih : ");
            STARTCOMMANDONELINE(); // Menerima input album dari user

            if(IsCommandWithSemicolon(currentCommand))
            {
                handleSemicolon(currentCommand); // Menghilangkan semicolon di input

                idxalbum = searchidalbum(ArrayPenyanyi, idxpenyanyi, currentCommand, mapAlbum); // Mencari idxalbum dari inputan user

                if(idxalbum != -1)
                {
                    printLagu(idxalbum, idxpenyanyi); // Menampilkan lagu yang dimiliki oleh album tersebut

                    printf("\nMasukkan ID Lagu yang dipilih : ");
                    STARTCOMMAND(); // Menerima input lagu dari user

                    if(IsCommandWithSemicolon(currentCommand))
                    {
                        handleSemicolon(currentCommand); // Menghilangkan semicolon di input

                        idxlagu = ConvertWordToInt(currentCommand) - 1;

                        idxset = Value(mapAlbum, idxalbum); // Mencari idxset dari ID album yang diinput oleh user

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
  
    printPlaylist(); // Menampilkan daftar playlist

    printf("\nMasukkan ID Playlist yang dipilih : "); // Menerima input ID Playlist dari user
    STARTCOMMANDONELINE();

    if(IsCommandWithSemicolon(currentCommand)){
        handleSemicolon(currentCommand); // Menghilangkan semicolon dari inputan user
        idxplaylist = ConvertWordToInt(currentCommand) - 1; // Mengubah word menjadi sebuah int

        if((idxplaylist > playlists.Neff-1) || (idxplaylist < 0))
        {
            printf("\nID Playlist %s tidak ada dalam daftar. Silakan coba lagi.\n\n", currentCommand.TabWord); // Bila inputan ID playlist diluar list yang diperbolehkan
            return;
        }
    }else{
        unknownCommand(); // Bila inputan tidak diakhiri dengan semicolon
        return;
    }

    InsertUnique(&(playlists.A[idxplaylist]),idxpenyanyi, idxalbum, idxlagu); // Memasukkan lagu ke dalam playlist
}
