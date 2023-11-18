#ifndef SEARCH_PRINT
#define SEARCH_PRINT

#include "../commands.h"

int searchidpenyanyi(TabInt p, Word input);

int searchidalbum(TabInt p, int idpenyanyi, Word input, MapAlbum map);

int searchidlagu(Set *s, MapAlbum map, int idalbum, Word input);

Word GetNamaAlbum(TabInt p, int idpenyanyi, int idalbum, MapAlbum map);

Word GetJudulLagu(Set SetLagu[], Word namaalbum, int idlagu, int idpenyanyi);

Word GetNamaAlbum(TabInt p, int idpenyanyi, int idalbum, MapAlbum map);

Word GetNamaPlaylist(ArrayDin Playlists, int idplaylist);

void printCurrent();

#endif
