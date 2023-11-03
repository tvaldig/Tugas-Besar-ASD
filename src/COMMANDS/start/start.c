#include <stdio.h>
#include "start.h"

void copyword(Word source, Word hasilcopy){
    for(int i = 0; i < source.Length; i++){
        hasilcopy.TabWord[i] = source.TabWord[i];
    }
}

void startFunction(){
    int keyCounter = 0;
    int n, m, l;
    char namaPenyanyi[100];
    STARTFROMFILE("../save/new.txt");
    n = ConvertWordToInt(currentWord);
    album.Value = SetLagu;
    for(int i = 0; i < n; i++){
        ADVOnEnter(true); //true karena dia mau baca integer jumlah album
      
        //menerima jumlah album dan nama penyanyi
        m = ConvertWordToInt(currentWord);
        penyanyi.jumlahalbum = m;
        ADVCONTINUE(); // setelah blank dilanjut
        penyanyi.namapenyanyi = currentWord;
        // masukin penyanyi ke array statis
        ArrayPenyanyi.data_penyanyi = penyanyi;
        for(int j = 0; j < m; j++){
            ADVOnEnter(true); //true karena dia mau baca integer jumlah lagu
            l = ConvertWordToInt(currentWord);
            album.Key = keyCounter;
            keyCounter++;
            ADVCONTINUE();// setelah blank dilanjut
            album.AlbumName = currentWord;
            // masukin ke Map
            mapAlbum.Elements[j] = album;
            for(int k = 0; k < l; k++){
                ADVOnEnter(false); //false karena dia mau baca string
                // Masukin lagu ke set
                copyword(currentWord, SetLagu.lagu[k]);
            }
        }
    }
}