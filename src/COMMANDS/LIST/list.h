#ifndef LIST_H
#define LIST_H

#include "../startload/startload.h"
#include "../../ADT/ADT.h"
// Prototipe fungsi-fungsi

// Fungsi untuk menampilkan daftar penyanyi
void ListSingers(TabInt ArrayP, int singerCount);

// Fungsi untuk menampilkan daftar album penyanyi
void ListAlbums(MapAlbum MapAlb, Word NamaPenyanyi);

// Fungsi untuk menampilkan daftar lagu dalam album
void ListSongs(Set setlagu[], Word NamaAlbum, int idpenyanyi);

// Fungsi untuk menampilkan daftar playlist pengguna
void ListPlaylists(ArrayDin Playlist, int playlistCount);


void listDefaultFunction();
void listPlaylistFunction();
#endif // LIST_H