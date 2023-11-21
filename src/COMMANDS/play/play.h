#ifndef PLAY_H
#define PLAY_H

#include "../../ADT/ADT.h"
#include "../startload/startload.h"

typedef int currentid;
extern currentid currentIdPlaylist;

/**
 * Memainkan lagu yang dipilih ; mengosongkan riwayat dan antrian
*/
void PlaySong ();

/**
 * Memainkan playlist yang dipilih
*/
void PlayPlaylist ();

/**
 * Membuat lagu yang dimainkan menjadi tidak ada/idx undef
*/
void NotPlaying ();

/**
 * Membuat playlist yang dimainkan menjadi tidak ada/idx undef
*/
void NotPlayingPlaylist();

/**
 * Mengembalikan nilai true jika tidak ada playlist yang dimainkan
*/
boolean isNotPlayingPlaylist();

/**
 * Mengembalikan nilai true jika tidak ada lagu yang dimainkan
*/
boolean isNotPlaying();
#endif 