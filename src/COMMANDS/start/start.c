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
    displayWord(currentWord);
    for(int i = 0; i < n; i++){
        ADVOnEnter(true); //true karena dia mau baca integer jumlah album

        //menerima jumlah album dan nama penyanyi
        m = ConvertWordToInt(currentWord);
        penyanyi.jumlahalbum = m;
        ADVCONTINUE();// setelah blank dilanjut
        penyanyi.nama = currentWord;

        // masukin penyanyi ke array statis
        ArrayPenyanyi.TI[i] = i;
        ArrayPenyanyi.data_penyanyi = penyanyi;
 
        for(int j = 0; j < m; j++){
            ADVOnEnter(true); //true karena dia mau baca integer jumlah lagu
            l = ConvertWordToInt(currentWord);
            displayWord(currentWord);
            ADVCONTINUE();// setelah blank dilanjut
            displayWord(currentWord);
            // masukin ke Map
            album.nama = currentWord;
            album.jumlahlagu = l;
            for(int k = 0; k < l; k++){
                ADVOnEnter(false); //false karena dia mau baca string
                // Masukin lagu ke set
                displayWord(currentWord);
            }
        }
    }
}