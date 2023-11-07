#ifndef _START_H
#define _START_H

#include "../../ADT/ADT.h"
extern Penyanyi penyanyi;
extern MapAlbum mapAlbum;
extern Album album;
extern TabInt ArrayPenyanyi;
extern Set SetLagu;
extern Queue antrian;
extern Stack riwayat;
extern ArrayDin playlists;
extern boolean inSession;

void startLoadFunction(Word fname, boolean loadiftrue);

#endif