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
    printf("Masukan ID playlist yang ingin di-enhance : \n");
    STARTCOMMAND(false);
    handleSemicolon(currentCommand);
    int id = ConvertWordToInt(currentCommand);
    if(SearchArrayDin(playlists, id) == -1){
        printf("Gagal. Playlist tidak ditemukan.\n");
    } else{
        playlist ply = playlists.A[id];
        
    }

}