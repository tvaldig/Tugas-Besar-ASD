#include <stdio.h>
#include "start.h"

TabInt ArrayPenyanyi;
Penyanyi penyanyi;
TabInt MapAlbum;
Album album;
TabInt LaguDalamAlbum;

void startFunction(){
    int n, m, l;
    STARTFROMFILE("../save/new.txt");
    n = ConvertWordToInt(currentWord);
    for(int i = 0; i < n; i++){
        ADVOnEnter(true); //true karena dia mau baca integer jumlah album
        m = ConvertWordToInt(currentWord);
        ArrayPenyanyi.TI[i] = i;
        displayWord(currentWord);
        ADVCONTINUE();// setelah blank dilanjut
        displayWord(currentWord);
        penyanyi.nama = currentWord;
        penyanyi.jumlahalbum = m;
        ArrayPenyanyi.nama = penyanyi.nama;
        //masukin penyanyi ke array statis
        for(int j = 0; j < m; j++){
            ADVOnEnter(true); //true karena dia mau baca integer jumlah lagu
            l = ConvertWordToInt(currentWord);
            displayWord(currentWord);
            ADVCONTINUE();// setelah blank dilanjut
            displayWord(currentWord);
            // masukin ke Map
            album.nama = currentWord;
            album.jumlahlagu = l;
            for(int k = 0; k < l; l++){
                ADVOnEnter(false); //false karena dia mau baca string
                // Masukin lagu ke set
                displayWord(currentWord);
            }
        }
    }
}