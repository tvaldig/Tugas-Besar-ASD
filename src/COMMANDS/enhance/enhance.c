#include "enhance.h"
#include "time.h"

int tauswortheNumberGenerator(int min, int max){
    unsigned int s1 = 13, s2 = 19 , s3 = 21, seed = time(NULL);
    unsigned int mask = 0xffffffffUL;
    int output;
    seed = (seed & mask) << s1 ^ ((seed << s2) & mask);
    seed = (seed & mask) ^ ((seed >> s3) & mask);
    output = seed % (min+max+1);
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
        for(int i = 0; i < 2; i++){
            Penyanyi penyanyi = ArrayPenyanyi.penyanyi[tauswortheNumberGenerator(0, ArrayPenyanyi.Neff)];
            printf("%s - %s", penyanyi.namapenyanyi.TabWord, mapAlbum.Elements[tauswortheNumberGenerator(penyanyi.IdAlbumPertama, penyanyi.jumlahalbum)].AlbumName.TabWord);
        }
    }

}