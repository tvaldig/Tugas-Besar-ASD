#ifndef PLAY_H
#define PLAY_H

#include "../../ADT/ADT.h"
#include "../startload/startload.h"
typedef struct
{
    IdxType penyanyi;
    IdxType album;
    IdxType lagu;
} NowPlaying;

extern NowPlaying current;

void PlaySong ();

void PlayPlaylist ();

void NotPlaying ();

boolean isNotPlaying ();
#endif 