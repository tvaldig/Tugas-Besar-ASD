#ifndef _START_H
#define _START_H

#include "../../ADT/ADT.h"
#include "../commands.h"

typedef struct
{
    IdxType penyanyi;
    IdxType album;
    IdxType lagu;
} NowPlaying;

extern Penyanyi penyanyi;
extern MapAlbum mapAlbum;
extern Album album;
extern TabInt ArrayPenyanyi;
extern Set SetLagu[100];
extern Queue antrian;
extern Stack riwayat;
extern ArrayDin playlists;
extern boolean inSession;
extern NowPlaying current;

void startLoadFunction(Word fname, boolean loadiftrue);

#endif