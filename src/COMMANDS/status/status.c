#include <stdio.h>
#include "status.h"

void status(Queue * q, TabInt ArrayP, Set setlagu[], MapAlbum map) {
    Queue temp;
    CreateQueue(&temp);
    printf("Queue: \n");
    if (IsEmptyQueue(*q)) {
        printf("Your queue is empty.\n");
    } else {
        int i = 1;
        IdxType penyanyi, album, lagu;
        char namapenyanyi, namalagu, namaalbum;
        while (!isEmpty(*q)) {
            dequeue(&q, &penyanyi, &album, &lagu);
            printf("%d. ", i);
            Set s = setlagu[Value(map, album)];
            ConvertWordToString(GetNamaPenyanyi(ArrayP, penyanyi).TabWord, &namapenyanyi);
            ConvertWordToString(mapAlbum.Elements[album].AlbumName.TabWord, &namaalbum);
            ConvertWordToString(s.AlbumLagu[lagu].JudulLagu.TabWord, &lagu);
            printf("%s - %s - %s\n", &namapenyanyi, &namalagu, &namaalbum);
            enqueue(&temp, penyanyi, album, lagu);
            i++;
        }
        while (!IsEmptyQueue(temp)) {
            dequeue(&temp, &penyanyi, &album, &lagu);
            enqueue(&q, penyanyi, album, lagu);
        }
    }
}
