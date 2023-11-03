#include <stdio.h>
#include "start.h"

Penyanyi penyanyi;
MapAlbum mapAlbum;
TabInt ArrayPenyanyi;
Set SetLagu;

void startFunction(){
    keytype keyCounter = 0, laguAlbum = 0;
    int countAlbum, n, m, l;
    STARTFROMFILE("../save/new.txt");  // memulai Mesin Kata
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

        // memasukan tipe data penyanyi ke array penyanyi
        ArrayPenyanyi.penyanyi[i] = penyanyi;
        ArrayPenyanyi.Neff++;
        for (int j = 0; j < m; j++)
        {                     // melakukan iterasi untuk setiap album penyanyi
            ADVOnEnter(true); // true untuk mengaktifkan ADV selanjutnya dengan akuisisi sebelum BLANK

            // membaca jumlah lagu pada setiap album
            l = ConvertWordToInt(currentWord);
            ADVCONTINUE(); // setelah blank dilanjutkan akuisisi sampai ENTER

            // melakukan konfigurasi untuk key, value, dan nama album
            mapAlbum.Elements[keyCounter].Key = keyCounter;
            mapAlbum.Elements[keyCounter].Value = SetLagu;
            mapAlbum.Elements[keyCounter].AlbumName = currentWord;

            // melakukan konfigurasi untuk id album pertama dari penyanyi
            if (j == 0)
            {
                penyanyi.IdAlbumPertama = keyCounter;
            }
            keyCounter++;
            mapAlbum.Count++;
            for (int k = 0; k < l; k++)
            {                      // iterasi untuk membaca lagu
                ADVOnEnter(false); // false untuk mengaktifkan ADV selanjutnya dengan akuisisi sebelum ENTER

                // Melakukan konfigurasi lagu ke dalam set
                mapAlbum.Elements[laguAlbum].Value.lagu[k].JudulLagu = currentWord;
                mapAlbum.Elements[laguAlbum].Value.Count = l;
            }
            laguAlbum++;
        }
    }
}
