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

typedef int currentid;
extern currentid currentIdPlaylist;
extern NowPlaying current;

void PlaySong ();

void PlayPlaylist ();

void NotPlaying ();

void NotPlayingPlaylist();

boolean IsNotPlayingPlaylist();

boolean isNotPlaying();
#endif 