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

typedef struct{
    NowPlaying current;
    Queue antrian;
    Stack riwayat;
    ArrayDin playlists;
    Word namauser;
} UserSession;

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
extern UserSession Users[10];

void startLoadFunction(Word fname, boolean loadiftrue);

#endif