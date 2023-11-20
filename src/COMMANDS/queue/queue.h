#ifndef _QUEUE_H
#define _QUEUE_H

#include "../../ADT/ADT.h"
#include "../commands.h"

/**
 * Mengosongkan antrian
*/
void ClearQueue(Queue *q);

/**
 * Memasukkan lagu ke dalam antrian
*/
void QueueSong(Queue *q);

/**
 * Mengubah posisi lagu 1 dan lagu 2 dalam antrian
*/
void QueueSwap(Queue *q, int id1, int id2);

/**
 * Memasukkan suatu playlist ke dalam antrian
*/
void QueuePlaylist(Queue *q, ArrayDin *playlists);

/**
 * Menghapus satu lagu dari antrian
*/
void QueueRemove(Queue *q, int inputId);

#endif
