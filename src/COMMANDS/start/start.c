#include <stdio.h>
#include "start.h"

Penyanyi penyanyi;
MapAlbum mapAlbum;
TabInt ArrayPenyanyi;
Set SetLagu;

int searchidpenyanyi(TabInt p, Word w){
    int i = 0;
    boolean found = false;
    while(!(found)){
        if(p.penyanyi[i].namapenyanyi.Length == w.Length){
            if(IsStringEqual(p.penyanyi->namapenyanyi.TabWord, w.TabWord)){
                return i;
            }
        }
        i++;
    }
}

void copyword(Word source, Word hasilcopy){
    for(int i = 0; i < source.Length; i++){
        hasilcopy.TabWord[i] = source.TabWord[i];
    }
}

void startFunction(){
    keytype keyCounter = 0;
    int countAlbum;
    char test[100];
    int n, m, l;
    STARTFROMFILE("../save/new.txt");
    n = ConvertWordToInt(currentWord);
    for(int i = 0; i < n; i++){
        ADVOnEnter(true); //true karena dia mau baca integer jumlah album
        //menerima jumlah album dan nama penyanyi
        m = ConvertWordToInt(currentWord);
        penyanyi.jumlahalbum = m;
        ADVCONTINUE(); // setelah blank dilanjut
        penyanyi.namapenyanyi = currentWord;
        displayWord(currentWord);

        penyanyi.Id = i;
        // masukin penyanyi ke array statis
        ArrayPenyanyi.Neff++;
        ArrayPenyanyi.penyanyi[i] = penyanyi;
        for(int j = 0; j < m; j++){
            ADVOnEnter(true); //true karena dia mau baca integer jumlah lagu
            l = ConvertWordToInt(currentWord);
            ADVCONTINUE();// setelah blank dilanjut
            mapAlbum.Elements[j].Key = keyCounter;
            keyCounter++;
            printf("%d\n", keyCounter);
            mapAlbum.Elements[j].AlbumName = currentWord;
            mapAlbum.Elements[j].Value = SetLagu;
            // masukin ke Map
            mapAlbum.Count++;
            for(int k = 0; k < l; k++){
                ADVOnEnter(false); //false karena dia mau baca string
                // Masukin lagu ke set
                mapAlbum.Elements[j].Value.lagu[k].JudulLagu = currentWord;
                mapAlbum.Elements[j].Value.Count++;

            }
        }
    }

    Queue antrian;
    Stack riwayat;
    printf("%s\n", ArrayPenyanyi.penyanyi[0].namapenyanyi.TabWord);

    Word a = {"BLACKPINK", 9};


    printf("id penyanyi: %d\n", searchidpenyanyi(ArrayPenyanyi,a));
}