#include "enhance.h"
#include "time.h"

void delaytime()
{
    int delay;
    for (int i = 0; i < 100000999; i++)
    {
        delay = i;
    }
}

int tauswortheNumberGenerator(int min, int max){
    unsigned int s1 = 13, s2 = 19 , s3 = 21, seed = time(NULL);
    unsigned int mask = 0xffffffffUL;
    int output;
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
        printf("\nRekomendasi Penyanyi dengan Album :\n");
        for(int i = 0; i < 3; i++){
            Penyanyi P = ArrayPenyanyi.penyanyi[tauswortheNumberGenerator(0, ArrayPenyanyi.Neff)];
            int idalbumpertama = P.IdAlbumPertama;
            int jumlahalbum = P.jumlahalbum;
            Album A = mapAlbum.Elements[tauswortheNumberGenerator(idalbumpertama, jumlahalbum)];
            delaytime();
            delaytime();
            delaytime();
            printf("%d. %s - %s\n", i+1, P.namapenyanyi.TabWord, A.AlbumName.TabWord);
        }
    }

}