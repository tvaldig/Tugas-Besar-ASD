#include "playlist.h"
#include "stdio.h"
#include "../commands.h"

int idxplaylist, idxpenyanyi, idxalbum, idxlagu, idxset;
boolean state, statealbum; // state menunjukkan apakah salah satu function yang direferences function lain mendapatkan suatu command yang salah; statealbum menunjukkan apakah command playlist add album atau add song yang diambil

void PLAYLIST(){
    STARTCOMMAND(true);
    if(IsStringEqual(currentCommand.TabWord,"CREATE;"))
    {
        CREATE_PLAYLIST();
    }else if(IsStringEqual(currentCommand.TabWord, "ADD"))
    {
        STARTCOMMAND(true);
        if(IsStringEqual(currentCommand.TabWord,"SONG;")){
            ADD_SONG_PLAYLIST();
        }else if (IsStringEqual(currentCommand.TabWord,"ALBUM;")){
            statealbum = true;
            ADD_ALBUM_PLAYLIST();
        }else{
            unknownCommand();
        }
    }else if(IsStringEqual(currentCommand.TabWord, "SWAP"))
    {
        SWAP_PLAYLIST();
    }else
     { // bila tidak diakhiri dengan ';'
        unknownCommand();
        return;
     }
}

void CREATE_PLAYLIST(){
    printf("\nMasukkan nama playlist yang ingin dibuat : "); // Menerima input nama playlist
    STARTCOMMAND(false);

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
    state = true; // Menunjukkan belum ada error dalam program
    ListSingers(ArrayPenyanyi, ArrayPenyanyi.Neff); // Menampilkan list penyanyi yang ada di program

    printf("\nMasukkan Nama Penyanyi yang dipilih : ");
    STARTCOMMAND(false); // Menerima input penyanyi dari user
    
    if(IsCommandWithSemicolon(currentCommand))
    { // Mengecek apakah command diakhiri dengan semicolon
        handleSemicolon(currentCommand); // Menghilangkan semicolon di input
        
        idxpenyanyi = searchidpenyanyi(ArrayPenyanyi, currentCommand); // Mencari idpenyanyi berdasarkan nama yang diinput oleh user

        if(idxpenyanyi != -1)
        { 
            ListAlbums(mapAlbum, currentCommand); // Menampilkan album yang dimiliki oleh penyanyi tersebut

            printf("\nMasukkan Judul Album yang dipilih : ");
            STARTCOMMAND(false); // Menerima input album dari user

            if(IsCommandWithSemicolon(currentCommand))
            {
                handleSemicolon(currentCommand); // Menghilangkan semicolon di input
                idxalbum = searchidalbum(ArrayPenyanyi, idxpenyanyi, currentCommand, mapAlbum); // Mencari idxalbum dari inputan user
                if(idxalbum == -1)
                {
                    printf("Album %s tidak ada dalam daftar. Silakan coba lagi.\n\n", currentCommand.TabWord);
                    state = false;
                    return;
                }
            }else
            { // Bila command tidak diakhiri dengan semicolon
                state = false;
                unknownCommand();
                return;
            }

        }else
        { // Bila inputan user salah
            printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi.\n\n", currentCommand.TabWord);
            state = false;
            return;
        }
    }else
    { // Bila command tidak diakhiri dengan semicolon
        state = false;
        unknownCommand();
        return;
    }

    if(statealbum)
    {
        INPUT_PLAYLIST();

        if(state)
        {
            idxset = Value(mapAlbum, idxalbum); // Mencari idxset dari Key idxalbum

            for(int i = 0; i < SetLagu[idxset].Count; i++){ // Memasukkan semua lagu dari Album ke Playlist
                InsertUnique(&(playlists.A[idxplaylist]),idxpenyanyi,idxalbum, i); // Meastikan tidak ada duplikat lagu di playlist
            }

            printf("Album dengan judul \"%s\" berhasil ditambahkan ke dalam playlist pengguna \"%s\".\n\n", mapAlbum.Elements[idxalbum].AlbumName.TabWord,playlists.A[idxplaylist].namaplaylist.TabWord);
        }
    }
}


void ADD_SONG_PLAYLIST(){
    statealbum = false;
    ADD_ALBUM_PLAYLIST();

    if(state) // Apabila proses ADD_ALBUM_PLAYLIST masih berhasil
    {
        ListSongs(SetLagu, currentCommand); // Menampilkan lagu yang dimiliki oleh album tersebut

        printf("\nMasukkan ID Lagu yang dipilih : ");
        STARTCOMMAND(true); // Menerima input lagu dari user

        if(IsCommandWithSemicolon(currentCommand))
        {
            handleSemicolon(currentCommand); // Menghilangkan semicolon di input

            idxlagu = ConvertWordToInt(currentCommand) - 1;

            idxset = Value(mapAlbum, idxalbum); // Mencari idxset dari ID album yang diinput oleh user

            if(idxlagu > SetLagu[idxset].Count -1 || idxlagu < 0){ // Cek apabila ID inputan user diluar yang seharusnya
                printf("Lagu dengan ID %d tidak ada dalam daftar. Silakan coba lagi.\n\n", idxlagu + 1);
                return;
            }
        }else
        { // Bila command tidak diakhiri dengan semicolon 
            unknownCommand();
            return;
        }

        INPUT_PLAYLIST();

        if(state){ // Apabila proses INPUT_PLAYLIST masih berhasil
            InsertUnique(&(playlists.A[idxplaylist]),idxpenyanyi, idxalbum, idxlagu); // Memasukkan lagu ke dalam playlist
            printf("Lagu dengan judul \"%s\" pada album \"%s\" oleh penyanyi \"%s\" berhasil ditambahkan ke dalam playlist \"%s\".\n\n",SetLagu[idxset].AlbumLagu[idxlagu].JudulLagu.TabWord,mapAlbum.Elements[idxalbum].AlbumName.TabWord, ArrayPenyanyi.penyanyi[idxpenyanyi].namapenyanyi.TabWord,playlists.A[idxplaylist].namaplaylist.TabWord);
        }

    }

    
}

void INPUT_PLAYLIST(){
    ListPlaylists(playlists, playlists.Neff); // Menampilkan daftar playlist

    printf("\nMasukkan ID Playlist yang dipilih : "); // Menerima input ID Playlist dari user
    STARTCOMMAND(false);

    if(IsCommandWithSemicolon(currentCommand)){
        handleSemicolon(currentCommand); // Menghilangkan semicolon dari inputan user
        idxplaylist = ConvertWordToInt(currentCommand) - 1; // Mengubah word menjadi sebuah int

        if((idxplaylist > playlists.Neff-1) || (idxplaylist < 0))
        {
            printf("\nID Playlist %s tidak ada dalam daftar. Silakan coba lagi.\n\n", currentCommand.TabWord); // Bila inputan ID playlist diluar list yang diperbolehkan
            state = false;
            return;
        }
    }else{
        state = false;
        unknownCommand(); // Bila inputan tidak diakhiri dengan semicolon
        return;
    }
}

void SWAP_PLAYLIST(){
    STARTCOMMAND(true);

    idxplaylist = ConvertWordToInt(currentCommand) - 1;

    STARTCOMMAND(true);

    int max = countPlaylist(playlists.A[idxplaylist]);

    int idxurutan1 = ConvertWordToInt(currentCommand) - 1;
    
    int idxurutan2;

    STARTCOMMAND(false);

    if(IsCommandWithSemicolon(currentCommand))
    {
        handleSemicolon(currentCommand);
        idxurutan2 = ConvertWordToInt(currentCommand) - 1;
    }else
    {
        printf("masuk sini\n");
        unknownCommand();
        return;
    }

    printf("%d %d %d\n", idxurutan1, idxurutan2, max);
    
    if(idxplaylist > playlists.Neff - 1 || idxplaylist < 0)
    {
        printf("Tidak ada playlist dengan playlist ID %d\n\n", idxplaylist+1);
        ENDCOMMAND();
        return;
    } else if(idxurutan1 > max - 1 || idxurutan1 < 0)
    {
        printf("Tidak ada lagu dengan urutan %d di playlist \"%s\"!\n\n", idxurutan1+1, playlists.A[idxplaylist].namaplaylist.TabWord);
        ENDCOMMAND();
        return;
    } else if(idxurutan2 > max - 1 || idxurutan2 < 0)
    {
        printf("Tidak ada lagu dengan urutan %d di playlist \"%s\"!\n\n", idxurutan2+1, playlists.A[idxplaylist].namaplaylist.TabWord);
        ENDCOMMAND();
        return;
    }

    addressnode p1,p2;
    int idlagutemp, idalbumtemp, idpenyanyitemp;

    p1 = First(playlists.A[idxplaylist]);
    p2 = p1;

    for(int i = 0; i < idxurutan1; i++){
        p1 = Next(p1);
    }
    for(int i = 0; i < idxurutan2; i++){
        p2 = Next(p2);
    }
    idpenyanyitemp = p1->idpenyanyi;
    idalbumtemp = p1->idalbum;
    idlagutemp = p1->idlagu;

    p1->idpenyanyi = p2->idpenyanyi;
    p1->idalbum = p2->idalbum;
    p1->idlagu = p2->idlagu;

    p2->idpenyanyi = idpenyanyitemp;
    p2->idalbum = idalbumtemp;
    p2->idlagu = idlagutemp;
}


