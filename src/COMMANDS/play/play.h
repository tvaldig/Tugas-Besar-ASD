#ifndef PLAY_H
#define PLAY_H

#include "../../ADT/ADT.h"
#include "../startload/startload.h"

typedef int currentid;
extern currentid currentIdPlaylist;

void PlaySong ();

void PlayPlaylist ();

void NotPlaying ();

void NotPlayingPlaylist();

boolean isNotPlayingPlaylist();

boolean isNotPlaying();
#endif 