#include <stdio.h>
#include "startload.h"


boolean inSession = false;
boolean isLogin = false;
Penyanyi penyanyi;
Album album;
MapAlbum mapAlbum;
TabInt ArrayPenyanyi;
Set SetLagu[100];
Queue antrian;
Stack riwayat;
ArrayDin playlists;
NowPlaying current;
UserSession Users[10];
int idLogged = -1;
int JumlahUser = -1;

void startLoadFunction(Word fname, boolean loadiftrue)
{
    keytype keyCounter = 0;
    
    int n, m, l, idSet = 0, laguAlbum = 0;
    MakeEmpty(&ArrayPenyanyi);
    CreateEmptyMap(&mapAlbum);
    NotPlaying();
    NotPlayingPlaylist();
    STARTFROMFILE(fname.TabWord); // memulai Mesin Kata

    if (finish)
    {
        printf("\nMasukkan nama file yang benar!\n\n");
        ENDCOMMAND();
        return;
    }

    if (loadiftrue){
        int i = 0;
        printf("\n");
        while(currentCommand.TabWord[i] != '.'){
            printf("%c", currentCommand.TabWord[i]);
            i++;
        }
        printf(" berhasil dibaca. WayangWave berhasil dijalankan.\n\n");
    }

    inSession = true;

    n = ConvertWordToInt(currentWord); // membaca jumlah penyanyi
    for (int i = 0; i < n; i++)
    {                     // iterasi untuk setiap penyanyi
        ADVOnEnter(true); // true untuk mengaktifkan ADV selanjutnya dengan akuisisi sebelum BLANK

        // membaca jumlah album pada penyanyi
        m = ConvertWordToInt(currentWord);
        penyanyi.jumlahalbum = m;
        ADVCONTINUE(); // setelah blank dilanjutkan akuisisi sampai ENTER
        // membaca nama penyanyi
        penyanyi.namapenyanyi = currentWord;
        SetPenyanyi(&ArrayPenyanyi, i, penyanyi);
        // memasukan tipe data penyanyi ke array penyanyi

        for (int j = 0; j < m; j++)
        {                     // melakukan iterasi untuk setiap album penyanyi
            ADVOnEnter(true); // true untuk mengaktifkan ADV selanjutnya dengan akuisisi sebelum BLANK

            // membaca jumlah lagu pada setiap album
            l = ConvertWordToInt(currentWord);
            ADVCONTINUE(); // setelah blank dilanjutkan akuisisi sampai ENTER

            // Membuat set lagu untuk setiap album
            CreateEmptySet(&SetLagu[keyCounter + 1]);
            // melakukan Insert pada Map
            InsertMap(&mapAlbum, keyCounter, keyCounter + 1, currentWord);

            // melakukan konfigurasi untuk id album pertama dari penyanyi
            if (j == 0)
            {
                SetIdAlbumPertamaPenyanyi(&ArrayPenyanyi, i, keyCounter);
            }

            for (int k = 0; k < l; k++)
            {
                ADVOnEnter(false); // false karena dia mau baca string
                // Masukin lagu ke set
                InsertSetLagu(&SetLagu[keyCounter + 1], keyCounter, keyCounter + 1, currentWord);
            }
            idSet++;
            laguAlbum++;
            keyCounter++;
        }
    }
    ADVOnEnter(false);
    JumlahUser = ConvertWordToInt(currentWord);
    for(int a = 0; a < JumlahUser; a++){
        ADVOnEnter(false);
        Users[a].namauser = currentWord;
        // inisialisasi Queue dan Stack kosong untuk menyimpan data dari file
        CreateQueue(&Users[a].antrian);

        CreateEmptyStack(&Users[a].riwayat); // membuat stack kosong

        Users[a].playlists = MakeArrayDin(); // membuat arraydin playlists kosong
        Users[a].current.album = IdxUndef;
        Users[a].current.penyanyi = IdxUndef;
        Users[a].current.lagu = IdxUndef;
    }
  
    if (!finish)
    {
        int idxpenyanyi, idxalbum, idxlagu;
        for(int b = 0; b < JumlahUser; b++){
            ADVSEMICOLON();
            if(UNDEF){
                Users[b].current.penyanyi = IdxUndef;
                Users[b].current.album = IdxUndef;
                Users[b].current.lagu = IdxUndef;
                UNDEF = false;
                ADVOnEnter(false);
            } else {
                Users[b].current.penyanyi = searchidpenyanyi(ArrayPenyanyi, currentWord);
                ADVSEMICOLON();
                Users[b].current.album = searchidalbum(ArrayPenyanyi, Users[b].current.penyanyi, currentWord, mapAlbum);
                ADVSEMICOLON();
                Users[b].current.lagu = searchidlagu(SetLagu, mapAlbum, Users[b].current.album, currentWord);
                ADVOnEnter(false);
            }
                             // Mulai membaca sesi bagian queue (antrian)
            n = ConvertWordToInt(currentWord); // n = berapa banyak jumlah antrian (jumlah queue)
            for (int i = 0; i < n; i++)
            {
                ADVSEMICOLON();
                idxpenyanyi = searchidpenyanyi(ArrayPenyanyi, currentWord); // mencari idxpenyanyi dari file
                ADVSEMICOLON();
                idxalbum = searchidalbum(ArrayPenyanyi, idxpenyanyi, currentWord, mapAlbum); // mencari idxalbum dari file
                ADVSEMICOLON();
                idxlagu = searchidlagu(SetLagu, mapAlbum, idxalbum, currentWord); // mencari idxlagu dari file

                enqueue(&Users[b].antrian, idxpenyanyi, idxalbum, idxlagu); // menambahkan idxpenyanyi, idxalbum, idxlagu ke queue antrian
            }
            ADVOnEnter(false);                 // mulai membaca sesi bagian riwayat (stack)
            n = ConvertWordToInt(currentWord); // n = berapa banyak jumlah riwayat (jumlah stack)

            for (int i = 0; i < n; i++)
            {
                ADVSEMICOLON();
                idxpenyanyi = searchidpenyanyi(ArrayPenyanyi, currentWord); // mencari idxpenyanyi dari file
                ADVSEMICOLON();
                idxalbum = searchidalbum(ArrayPenyanyi, idxpenyanyi, currentWord, mapAlbum); // mencari idxalbum dari file
                ADVSEMICOLON();
                idxlagu = searchidlagu(SetLagu, mapAlbum, idxalbum, currentWord); // mencari idxlagu dari file

                Push(&Users[b].riwayat, idxpenyanyi, idxalbum, idxlagu); // menambahkan idxpenyanyi, idxalbum, idxlagu ke stack riwayat
            }

            Reversestack(&Users[b].riwayat); // karena urutan riwayat di text adalah dari yang terbaru maka isi stack perlu direverse

            ADVOnEnter(false);
            n = ConvertWordToInt(currentWord); // n = berapa banyak jumlah playlist
            for (int i = 0; i < n; i++)
            {
                ADVOnEnter(true);
                m = ConvertWordToInt(currentWord);

                ADVCONTINUE();
                InsertLastArrayDin(&Users[b].playlists, currentWord);

                CreateEmpty(&(Users[b].playlists.A[i])); // membuat satu playlist baru di arraydin playlists

                for (int j = 0; j < m; j++)
                {
                    ADVSEMICOLON();
                    idxpenyanyi = searchidpenyanyi(ArrayPenyanyi, currentWord); // mencari idxpenyanyi dari file
                    ADVSEMICOLON();
                    idxalbum = searchidalbum(ArrayPenyanyi, idxpenyanyi, currentWord, mapAlbum); // mencari idxalbum dari file
                    ADVSEMICOLON();
                    idxlagu = searchidlagu(SetLagu, mapAlbum, idxalbum, currentWord); // mencari idxlagu dari file

                    addressnode temp = alokasi(idxpenyanyi, idxalbum, idxlagu); // membuat sebuah node baru berisi idxpenyanyi, idxalbum, idxlagu
                    InsertLast(&(Users[b].playlists.A[i]), temp);                        // memasukkan data dari node yang sudah dibuat ke playlists
                }
            } 
        }
    }
}

void loginFunction(){
    if(isLogin){
        printf("Silakan Logout terlebih dahulu!\n\n");
    } else{
        printf("Masukkan username user WayangWave : ");
        STARTCOMMAND(false);
        if (IsCommandWithSemicolon(currentCommand))
        {
            handleSemicolon(currentCommand);
            idLogged = SearchUser(Users, currentCommand);
            if (idLogged == -999)
            {
                printf("Username tidak ditemukan!\n");
            }
            else
            {
                current.album = Users[idLogged].current.album;
                current.lagu = Users[idLogged].current.lagu;
                current.penyanyi = Users[idLogged].current.penyanyi;
                antrian = Users[idLogged].antrian;
                riwayat = Users[idLogged].riwayat;
                playlists = Users[idLogged].playlists;
                isLogin = true;
                printf("Berhasil Login dengan user %s!\n", currentCommand.TabWord);
            }
        }
        else
        {
            unknownCommand();
        }
    }   
    
}
void logoutFunction()
    {
        if (isLogin)
        {
            Users[idLogged].current.album = current.album;
            Users[idLogged].current.lagu = current.lagu;
            Users[idLogged].current.penyanyi = current.penyanyi;
            Users[idLogged].antrian = antrian;
            Users[idLogged].riwayat = riwayat;
            Users[idLogged].playlists = playlists;
            isLogin = false;
            printf("Berhasil Logout!\n");
        }
        else
        {
            printf("Belum Login ke akun.\n");
        }
 } 


int SearchUser(UserSession u[], Word Nama){
    for(int i = 0; i < 10; i++){
        if(IsStringEqual(u[i].namauser.TabWord, Nama.TabWord)){
            return i;
        }
    }
    return -999;
}