#include <stdio.h>
#include "start.h"

int searchidpenyanyi(TabInt p, Word input)
{ // Mencari key id penyanyi berdasarkan inputan user
    int i = 0;
    while (i < p.Neff)
    {
        if (p.penyanyi[i].namapenyanyi.Length == input.Length)
        {
            if (IsStringEqual(p.penyanyi[i].namapenyanyi.TabWord, input.TabWord))
            {
                return i;
            }
        }
        i++;
    }
    return -1;
}

int searchidalbum(TabInt p, int idpenyanyi, Word input, MapAlbum map)
{
    int i = p.penyanyi[idpenyanyi].IdAlbumPertama;
    while (i < p.penyanyi[idpenyanyi].jumlahalbum + i)
    {
        if (map.Elements[i].AlbumName.Length == input.Length)
        {
            if (IsStringEqual(map.Elements[i].AlbumName.TabWord, input.TabWord))
            {
                return i;
            }
        }
        i++;
    }
    return -1;
}

int searchidlagu(Set *s, Word input)
{
    int i = 0, j = 0;
    while (j < 10)
    {
        while (i < s[j].Count)
        {
            if (s[j].AlbumLagu[i].JudulLagu.Length == input.Length)
            {
                if (IsStringEqual(s[j].AlbumLagu[i].JudulLagu.TabWord, input.TabWord))
                {
                    return i;
                }
            }
            i++;
        }
        j++;
    }

    return -1;
}

void startFunction(Word fname, boolean loadiftrue)
{
    keytype keyCounter = 0;
    Penyanyi penyanyi;
    Album album;
    MapAlbum mapAlbum;
    TabInt ArrayPenyanyi;
    Set SetLagu[100];
    int n, m, l, idSet = 0, laguAlbum = 0;
    MakeEmpty(&ArrayPenyanyi);
    CreateEmptyMap(&mapAlbum);
    STARTFROMFILE(fname.TabWord); // memulai Mesin Kata

    if (finish)
    {
        printf("Masukkan nama file yang benar!\n");
        ENDCOMMAND();
        return;
    }

    if (loadiftrue){
        int i = 0;
        while(currentCommand.TabWord[i] != '.'){
            printf("%c", currentCommand.TabWord[i]);
            i++;
        }
        printf(" berhasil dibaca. WayangWave berhasil dijalankan.\n");
    }

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
                InsertSetLagu(&SetLagu[keyCounter + 1], laguAlbum, keyCounter, keyCounter + 1, currentWord);
            }
            idSet++;
            laguAlbum++;
            keyCounter++;
        }
    }

    Queue antrian; // inisialisasi Queue dan Stack kosong untuk menyimpan data dari file
    CreateQueue(&antrian);

    Stack riwayat;
    CreateEmptyStack(&riwayat); // membuat stack kosong

    ArrayDin playlists;
    playlists = MakeArrayDin(); // membuat arraydin playlists kosong

    if (!finish)
    {
        ADVOnEnter(false);                 // Mulai membaca sesi bagian queue (antrian)
        n = ConvertWordToInt(currentWord); // n = berapa banyak jumlah antrian (jumlah queue)

        int idxpenyanyi, idxalbum, idxlagu;

        for (int i = 0; i < n; i++)
        {
            ADVSEMICOLON();
            idxpenyanyi = searchidpenyanyi(ArrayPenyanyi, currentWord); // mencari idxpenyanyi dari file
            ADVSEMICOLON();
            idxalbum = searchidalbum(ArrayPenyanyi, idxpenyanyi, currentWord, mapAlbum); // mencari idxalbum dari file
            ADVSEMICOLON();
            idxlagu = searchidlagu(SetLagu, currentWord); // mencari idxlagu dari file

            enqueue(&antrian, idxpenyanyi, idxalbum, idxlagu); // menambahkan idxpenyanyi, idxalbum, idxlagu ke queue antrian
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
            idxlagu = searchidlagu(SetLagu, currentWord); // mencari idxlagu dari file

            Push(&riwayat, idxpenyanyi, idxalbum, idxlagu); // menambahkan idxpenyanyi, idxalbum, idxlagu ke stack riwayat
        }

        Reversestack(&riwayat); // karena urutan riwayat di text adalah dari yang terbaru maka isi stack perlu direverse

        ADVOnEnter(false);
        n = ConvertWordToInt(currentWord); // n = berapa banyak jumlah playlist

        for (int i = 0; i < n; i++)
        {
            ADVOnEnter(true);
            m = ConvertWordToInt(currentWord);

            ADVCONTINUE();
            InsertLastArrayDin(&playlists, currentWord);

            CreateEmpty(&(playlists.A[i])); // membuat satu playlist baru di arraydin playlists

            for (int j = 0; j < m; j++)
            {
                ADVSEMICOLON();
                idxpenyanyi = searchidpenyanyi(ArrayPenyanyi, currentWord); // mencari idxpenyanyi dari file
                ADVSEMICOLON();
                idxalbum = searchidalbum(ArrayPenyanyi, idxpenyanyi, currentWord, mapAlbum); // mencari idxalbum dari file
                ADVSEMICOLON();
                idxlagu = searchidlagu(SetLagu, currentWord); // mencari idxlagu dari file

                addressnode temp = alokasi(idxpenyanyi, idxalbum, idxlagu); // membuat sebuah node baru berisi idxpenyanyi, idxalbum, idxlagu
                InsertLast(&(playlists.A[i]), temp);                        // memasukkan data dari node yang sudah dibuat ke playlists
            }
        }
    }
}