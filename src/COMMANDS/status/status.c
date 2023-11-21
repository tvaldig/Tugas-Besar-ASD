#include <stdio.h>
#include "status.h"

void status(Queue * q, TabInt ArrayP, Set setlagu[], MapAlbum map) {
    Queue temp;
    CreateQueue(&temp);
   
    if(!isNotPlayingPlaylist()){
        char namaplaylist[100];
        Word NamaPlaylist = GetNamaPlaylist(playlists, currentIdPlaylist);
        ConvertWordToString(&NamaPlaylist, namaplaylist);
        printf("Current Playlist: %s.\n", namaplaylist);
    }
    printf("\n");
    printf("Now Playing:\n");
    if(isNotPlaying()){
         printf("Belum pernah ada lagu yang dimainkan. Gunakan fitur PLAY dan SONG untuk memainkan lagu.\n");
    } else {
        printCurrent();
    }
    printf("\n"); 
    printf("Queue: \n");
    if (IsEmptyQueue(*q)) {
        printf("Queue kosong.\n\n");
    } else {
        int i = 1;
        IdxType penyanyi, album, lagu;
        char namapenyanyi[100], namalagu[100], namaalbum[100];
        while (!IsEmptyQueue(*q)) {
            dequeue(q, &penyanyi, &album, &lagu);
            printf("%d. ", i);
            Set s = setlagu[Value(map, album)];
            Word nama = GetNamaPenyanyi(ArrayP, penyanyi);
            ConvertWordToString(&nama, namapenyanyi);
            ConvertWordToString(&mapAlbum.Elements[album].AlbumName, namaalbum);
            ConvertWordToString(&s.AlbumLagu[lagu].JudulLagu, namalagu);
            printf("%s - %s - %s\n", &namapenyanyi, &namalagu, &namaalbum);
            enqueue(&temp, penyanyi, album, lagu);
            i++;
        }
        while (!IsEmptyQueue(temp)) {
            dequeue(&temp, &penyanyi, &album, &lagu);
            enqueue(q, penyanyi, album, lagu);
        }
    }
}
