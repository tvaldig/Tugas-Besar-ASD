#ifndef _QUEUE_H
#define _QUEUE_H

#include "../../ADT/ADT.h"
#include "../commands.h"
void ClearQueue(Queue *q);

void QueueSong(Queue *q);

void QueuePlaylist(Queue *q, ArrayDin *playlists);
void QueueRemove(Queue *q, int id);

#endif
