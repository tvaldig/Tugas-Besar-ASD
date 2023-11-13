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

void PlaySong (NowPlaying *current);

void PlayPlaylist (NowPlaying *current);

void NotPlaying (NowPlaying *current);

boolean isPlaying (NowPlaying current);
#endif 