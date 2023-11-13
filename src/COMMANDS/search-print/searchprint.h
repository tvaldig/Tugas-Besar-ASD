#ifndef SEARCH_PRINT
#define SEARCH_PRINT

#include "../commands.h"

int searchidpenyanyi(TabInt p, Word input);

int searchidalbum(TabInt p, int idpenyanyi, Word input, MapAlbum map);

int searchidlagu(Set *s, MapAlbum map, int idalbum, Word input);

int GetIdAlbum(Word NamaAlbum);

void printPenyanyi();

void printAlbum(int idpenyanyi);

void printLagu(int idalbum, int idpenyanyi);

void printPlaylist();

#endif
