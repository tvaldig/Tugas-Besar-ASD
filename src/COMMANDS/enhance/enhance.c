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
    int id = ConvertWordToInt(currentCommand);
    if(SearchArrayDin(playlists, id) == -1){
        printf("Gagal. Playlist tidak ditemukan.\n");
    } else{
        playlist ply = playlists.A[id];
        displayPlaylist(playlists, id);

        TulisIsi(ArrayPenyanyi);
        printf("\nRekomendasi Lagu yang dapat ditambahkan:\n");
        for(int i = 0; i < tauswortheNumberGenerator(1,5); i++){
            delaytime();
            Penyanyi P = ArrayPenyanyi.penyanyi[tauswortheNumberGenerator(0, ArrayPenyanyi.Neff)];
            int idalbumpertama = P.IdAlbumPertama;
            int jumlahalbum = P.jumlahalbum;
            Album A = mapAlbum.Elements[tauswortheNumberGenerator(idalbumpertama, idalbumpertama+jumlahalbum)];
            delaytime();
            Word judullagu = SetLagu[Value(mapAlbum,A.Key)].AlbumLagu[tauswortheNumberGenerator(0, SetLagu[Value(mapAlbum, A.Key)].Count)].JudulLagu;
            printf("%d. %s - %s - %s\n", i + 1, P.namapenyanyi.TabWord, A.AlbumName.TabWord, judullagu.TabWord);
        }
    }

}