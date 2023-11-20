#include "enhance.h"
#include "time.h"
#include "sys/time.h"

void delaytime()
{
    int delay;
    for (int i = 0; i < 100000999; i++)
    {
        delay = i;
    }
}

int tauswortheNumberGenerator(int min, int max){
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    unsigned int s1 = 13, s2 = 19 , s3 = 21;
    unsigned int mask = 0xffffffffUL;
   
    int output, seed = currentTime.tv_usec;
    seed = (seed & mask) << s1 ^ ((seed << s2) & mask);
    seed = (seed & mask) ^ ((seed >> s3) & mask);
    output = (seed % (max-min)) + min;
   
    return output;
}


void ENHANCE(){
    PrintArrayDin(playlists);
    printf("\nMasukan ID playlist yang ingin di-enhance : ");
    STARTCOMMAND(false);
    handleSemicolon(currentCommand);
    int idplaylist = ConvertWordToInt(currentCommand);
    if(SearchArrayDin(playlists, idplaylist) == -1){
        printf("Gagal. Playlist tidak ditemukan.\n");
    } else{
        playlist ply = playlists.A[idplaylist];
        displayPlaylist(playlists, idplaylist);

        printf("\nRekomendasi Lagu yang dapat ditambahkan:\n");
        int number = tauswortheNumberGenerator(1, 5);
        int temppenyanyi[number];
        int tempalbum[number];
        int templagu[number];
        for (int i = 0; i < number; i++)
        {
            delaytime();
            int numpenyanyi = tauswortheNumberGenerator(0, ArrayPenyanyi.Neff);
            Penyanyi P = ArrayPenyanyi.penyanyi[numpenyanyi];
            int idalbumpertama = P.IdAlbumPertama;
            int jumlahalbum = P.jumlahalbum;

            int numalbum = tauswortheNumberGenerator(idalbumpertama, idalbumpertama + jumlahalbum);
            Album A = mapAlbum.Elements[numalbum];

            delaytime();
            int numlagu = tauswortheNumberGenerator(0, SetLagu[Value(mapAlbum, A.Key)].Count);
            Word judullagu = SetLagu[Value(mapAlbum, A.Key)].AlbumLagu[numlagu].JudulLagu;
            printf("%d. %s - %s - %s\n", i + 1, P.namapenyanyi.TabWord, A.AlbumName.TabWord, judullagu.TabWord);
            temppenyanyi[i] = numpenyanyi;
            tempalbum[i] = numalbum;
            templagu[i] = numlagu;
        }
        printf("Masukkan ID rekomendasi yang diinginkan : ");
        STARTCOMMAND(false);
        handleSemicolon(currentCommand);
        int id = ConvertWordToInt(currentCommand);
        if(id < 1 || id > number){
            printf("Gagal memasukan rekomendasi, ID tidak ditemukan\n");
        } else{
            id--;
            InsertUnique(&ply, temppenyanyi[id], tempalbum[id], templagu[id]);
            printf("\nLagu berhasil ditambahkan!\n");
            displayPlaylist(playlists, idplaylist);
        }
    }

}