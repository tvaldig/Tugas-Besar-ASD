#ifndef LIST_H
#define LIST_H

#include "../startload/startload.h"
#include "../../ADT/ADT.h"
// Prototipe fungsi-fungsi
int GetIdAlbum(Word NamaAlbum);
int SearchPenyanyi(Word Nama);
void ListSingers(TabInt ArrayP, int singerCount);
void ListAlbums(MapAlbum MapAlb, Word NamaPenyanyi);
void ListSongs(Set setlagu[], Word NamaAlbum);
void ListPlaylists(ArrayDin Playlist, int playlistCount);
void listDefaultFunction();
void listPlaylistFunction();
#endif // LIST_H