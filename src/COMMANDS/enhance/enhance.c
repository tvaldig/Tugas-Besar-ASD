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
    printf("\n");
    PrintArrayDin(playlists);
    printf("\nMasukan ID playlist yang ingin di-enhance : ");
    STARTCOMMAND(false);
    handleSemicolon(currentCommand);
    int idplaylist = ConvertWordToInt(currentCommand);
    if(SearchArrayDin(playlists, idplaylist) == -1){
        printf("\nGagal. Playlist tidak ditemukan.\n\n");
    } else{
        displayPlaylist(playlists, idplaylist);

        printf("\nRekomendasi Lagu yang dapat ditambahkan:\n");
        int number = tauswortheNumberGenerator(3, 5);
        int temppenyanyi[number];
        int tempalbum[number];
        int templagu[number];

        int numpenyanyi, idalbumpertama, jumlahalbum, numalbum, numlagu;
        Penyanyi P;
        Album A;
        Word judullagu;

        for (int i = 0; i < number; i++)
        {
            if(countPlaylist(playlists.A[idplaylist]) == NbElmt(ArrayPenyanyi)){
                if(i == 0){
                    printf("\nPlaylist sudah memiliki semua lagu. Tidak dapat menjalankan fitur ENHANCE!\n\n");
                }
                break;
            }
            do{
                delaytime();
                numpenyanyi = tauswortheNumberGenerator(0, ArrayPenyanyi.Neff);
                P = ArrayPenyanyi.penyanyi[numpenyanyi];
                idalbumpertama = P.IdAlbumPertama;
                jumlahalbum = P.jumlahalbum;

                numalbum = tauswortheNumberGenerator(idalbumpertama, idalbumpertama + jumlahalbum);
                A = mapAlbum.Elements[numalbum];

                delaytime();
                numlagu = tauswortheNumberGenerator(0, SetLagu[Value(mapAlbum, A.Key)].Count);
                judullagu = SetLagu[Value(mapAlbum, A.Key)].AlbumLagu[numlagu].JudulLagu;
            }while(IsMember(playlists.A[idplaylist], numpenyanyi, numalbum, numlagu));

            printf("%d. %s - %s - %s\n", i + 1, P.namapenyanyi.TabWord, A.AlbumName.TabWord, judullagu.TabWord);
            temppenyanyi[i] = numpenyanyi;
            tempalbum[i] = numalbum;
            templagu[i] = numlagu;
        }
        printf("\nMasukkan ID rekomendasi yang diinginkan : ");
        STARTCOMMAND(false);
        handleSemicolon(currentCommand);
        int id = ConvertWordToInt(currentCommand);
        if(id < 1 || id > number){
            printf("\nGagal memasukan rekomendasi, ID tidak ditemukan\n\n");
        } else{
            id--;
            InsertUnique(&(playlists.A[idplaylist]), temppenyanyi[id], tempalbum[id], templagu[id]);
            printf("\nLagu berhasil ditambahkan!\n\n");
            displayPlaylist(playlists, idplaylist);
            printf("\n");
        }
    }

}