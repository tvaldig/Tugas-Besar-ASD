#include <stdio.h>
#include "start.h"

Penyanyi penyanyi;
Album album;
MapAlbum mapAlbum;
TabInt ArrayPenyanyi;
Set SetLagu;

int searchidpenyanyi(TabInt p, Word input){ // Mencari key id penyanyi berdasarkan inputan user
    int i = 0;
    while(i < p.Neff){
        if(p.penyanyi[i].namapenyanyi.Length == input.Length){
            if(IsStringEqual(p.penyanyi[i].namapenyanyi.TabWord, input.TabWord)){
                return i;
            }
        }
        i++;
    }
    return -1;
}

int searchidalbum(TabInt p, int idpenyanyi, Word input, MapAlbum map){
    int i = p.penyanyi[idpenyanyi].IdAlbumPertama;
    while(i < p.penyanyi[idpenyanyi].jumlahalbum + i){
        if(map.Elements[i].AlbumName.Length == input.Length){
            if(IsStringEqual(map.Elements[i].AlbumName.TabWord, input.TabWord)){
                return i;
            }
        }
        i++;
    }
    return -1;
}

int searchidlagu (TabInt p, int idpenyanyi, Word input, MapAlbum map, int idalbum){
    int i = 0;
    while(i < map.Elements[idalbum].Value.Count){
        if(map.Elements[idalbum].Value.lagu[i].JudulLagu.Length == input.Length){
            if(IsStringEqual(map.Elements[idalbum].Value.lagu[i].JudulLagu.TabWord, input.TabWord)){
                return i;
            }
        }
        i++;
    }
    return -1;
}

void copyword(Word source, Word hasilcopy){
    for(int i = 0; i < source.Length; i++){
        hasilcopy.TabWord[i] = source.TabWord[i];
    }
}

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
        displayWord(currentWord);

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
                ArrayPenyanyi.penyanyi[i].IdAlbumPertama = keyCounter;
            }
            keyCounter++;
            mapAlbum.Count++;
            for(int k = 0; k < l; k++){
                ADVOnEnter(false); //false karena dia mau baca string
                // Masukin lagu ke set
                mapAlbum.Elements[laguAlbum].Value.lagu[k].JudulLagu = currentWord;
                mapAlbum.Elements[laguAlbum].Value.Count++;

            }
            laguAlbum++;
        }
    }

    Queue antrian; // inisialisasi Queue dan Stack kosong untuk menyimpan data dari file
    CreateQueue(&antrian);
    
    ADVOnEnter(false); // Mulai membaca sesi bagian queue (antrian)
    n = ConvertWordToInt(currentWord); // n = berapa banyak jumlah antrian (jumlah queue)

    int idxpenyanyi, idxalbum, idxlagu; 

    for(int i = 0; i < n; i++){
        ADVSEMICOLON();
        idxpenyanyi = searchidpenyanyi(ArrayPenyanyi, currentWord); // mencari idxpenyanyi dari file
        ADVSEMICOLON();
        idxalbum = searchidalbum(ArrayPenyanyi, idxpenyanyi, currentWord, mapAlbum); // mencari idxalbum dari file
        ADVSEMICOLON();
        idxlagu = searchidlagu(ArrayPenyanyi, idxpenyanyi, currentWord, mapAlbum, idxalbum); // mencari idxlagu dari file
        
        enqueue(&antrian, idxpenyanyi, idxalbum, idxlagu); // menambahkan idxpenyanyi, idxalbum, idxlagu ke queue antrian
    }

    displayQueue(antrian);

    Stack riwayat;
    CreateEmptyStack(&riwayat);

    ADVOnEnter(false); // mulai membaca sesi bagian riwayat (stack)
    n = ConvertWordToInt(currentWord); // n = berapa banyak jumlah riwayat (jumlah stack)

    for(int i = 0; i < n; i++){
        ADVSEMICOLON();
        idxpenyanyi = searchidpenyanyi(ArrayPenyanyi, currentWord); // mencari idxpenyanyi dari file
        ADVSEMICOLON();
        idxalbum = searchidalbum(ArrayPenyanyi, idxpenyanyi, currentWord, mapAlbum); // mencari idxalbum dari file
        ADVSEMICOLON();
        idxlagu = searchidlagu(ArrayPenyanyi, idxpenyanyi, currentWord, mapAlbum, idxalbum); // mencari idxlagu dari file
        
        Push(&riwayat, idxpenyanyi, idxalbum, idxlagu); // menambahkan idxpenyanyi, idxalbum, idxlagu ke stack riwayat
    }

    Reversestack(&riwayat);
    displayStack(riwayat);

    ArrayDin playlists;

    playlists = MakeArrayDin();

    ADVOnEnter(false);
    n = ConvertWordToInt(currentWord); // n = berapa banyak jumlah playlist

    for(int i = 0; i < n; i++){
        ADVOnEnter(true);
        m = ConvertWordToInt(currentWord);
        
        ADVCONTINUE();
        InsertLastArrayDin(&playlists, -1, -1, -1, currentWord);

        printf("%s\n", currentWord.TabWord);

        PrintArrayDin(playlists);
        
        for(int j = 0; j < m; j++){
            ADVSEMICOLON(); 
            idxpenyanyi = searchidpenyanyi(ArrayPenyanyi, currentWord); // mencari idxpenyanyi dari file
            ADVSEMICOLON();
            idxalbum = searchidalbum(ArrayPenyanyi, idxpenyanyi, currentWord, mapAlbum); // mencari idxalbum dari file
            ADVSEMICOLON();
            idxlagu = searchidlagu(ArrayPenyanyi, idxpenyanyi, currentWord, mapAlbum, idxalbum); // mencari idxlagu dari file
            
            printf("berhasil masuk sini\n");
        }

    }


}
    




/*
    printf("Isi dari penyanyi: %s\n", ArrayPenyanyi.penyanyi[1].namapenyanyi.TabWord);
    printf("Isi dari idalbum penyanyi: %d\n", ArrayPenyanyi.penyanyi[1].IdAlbumPertama);
    printf("Isi dari jumlahalbum penyanyi: %d\n", ArrayPenyanyi.penyanyi[1].jumlahalbum);
    printf("Isi dari album pertama lagu pertama: %s %d\n", mapAlbum.Elements[ArrayPenyanyi.penyanyi[0].IdAlbumPertama].Value.lagu->JudulLagu.TabWord,mapAlbum.Elements[ArrayPenyanyi.penyanyi[0].IdAlbumPertama].Value.lagu->IdLagu);
    printf("Nama dari album pertama penyanyi pertama: %s\n", mapAlbum.Elements[ArrayPenyanyi.penyanyi[0].IdAlbumPertama].AlbumName.TabWord);



*/