#include <stdio.h>
#include "map.h"
#include "../mesinkata/mesinkata.h"

/* Prototype */
int main(){
    MapAlbum Map;
    Album album;
    CreateEmptyMap(&Map);

    if(IsEmptyMap(Map)){
        printf("\nFungsi IsEmptyMap() berhasil di tes.\n\n");
    }

    
    printf("Masukkan Key dari Map: ");
    scanf("%d", &(album.Key));
    printf("Masukkan Value dari Map: ");
    scanf("%d", &(album.Value));
    
    while(album.Key == album.Value){
        printf("\nNilai Key dan Value tidak boleh sama!\n");
        printf("Masukkan Key dari Map: ");
        scanf("%d", &(album.Key));
        printf("Masukkan Value dari Map: ");
        scanf("%d", &(album.Value));
    }

    char temp;
    scanf("%c", &temp); // untuk menghilangkan \n dari proses pengambilan kata

    printf("Masukkan nama album: ");
    STARTCOMMAND(false);

    InsertMap(&Map, album.Key, album.Value, currentCommand);

    printf("\nMasukkan Key yang ingin dicari Valuenya: ");
    scanf("%d", &(album.Key));

    if(Value(Map, album.Key) == album.Key){ // Sudah dibuat peraturan dalam program bahwa Key dan Value tidak boleh sama ketika diinsert ke dalam Map
        printf("Key yang diinput belum pernah diinisialisasi, value gagal ditemukan!\n\n");
    }else{
        printf("\nValue dari Key yang dicari:%d\n", Value(Map, album.Key));
        printf("Nama album dari Key yang dicari:%s\n\n", Map.Elements[0].AlbumName.TabWord);
    }

    return 0;
}
