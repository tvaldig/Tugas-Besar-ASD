#include <stdio.h>
#include "startload.h"


boolean inSession = false;
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

void startLoadFunction(Word fname, boolean loadiftrue)
{
    keytype keyCounter = 0;
    
    int n, m, l, idSet = 0, laguAlbum = 0;
    MakeEmpty(&ArrayPenyanyi);
    CreateEmptyMap(&mapAlbum);
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
    int z = ConvertWordToInt(currentWord);
    for(int a = 0; a < z; a++){
        ADVOnEnter(false);
        Users[a].namauser = currentWord;
        // inisialisasi Queue dan Stack kosong untuk menyimpan data dari file
        CreateQueue(&Users[a].antrian);

        CreateEmptyStack(&Users[a].riwayat); // membuat stack kosong

        Users[a].playlists = MakeArrayDin(); // membuat arraydin playlists kosong
    }
  
    printf("flag1\n");
    if (!finish)
    {
        
        int idxpenyanyi, idxalbum, idxlagu;
        for(int b = 0; b < z; b++){
            ADVSEMICOLON();
            Users[b].current.penyanyi = searchidpenyanyi(ArrayPenyanyi, currentWord);
            ADVSEMICOLON();
            Users[b].current.album = searchidalbum(ArrayPenyanyi, current.penyanyi, currentWord, mapAlbum);
            ADVSEMICOLON();
            Users[b].current.lagu = searchidlagu(SetLagu, mapAlbum, current.album, currentWord);
            ADVOnEnter(false);                 // Mulai membaca sesi bagian queue (antrian)
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
    printf("flag3\n");
}