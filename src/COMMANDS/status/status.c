#include <stdio.h>
#include "status.h"

void status(Queue * q, TabInt ArrayP, Set setlagu[], MapAlbum map) {
    Queue temp;
    CreateQueue(&temp);
    printf("Now Playing:\n");
    if(!isNotPlayingPlaylist()){
        
        printf("Current Playlist: %s");
    }
    if(isNotPlaying()){
         printf("No songs have been played yet. Please search for a song to begin playback.\n");
    } else {
        printCurrent();
    }
    printf("\n"); 
    printf("Queue: \n");
    if (IsEmptyQueue(*q)) {
        printf("Your queue is empty.\n");
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
