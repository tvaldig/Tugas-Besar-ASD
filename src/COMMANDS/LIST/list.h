#ifndef LIST_H
#define LIST_H

// Definisikan struktur penyanyi, album, dan lagu
typedef struct {
    char name[100];
    char albums[10][100];
    int albumCount;
} Singer;

typedef struct {
    char name[100];
    char songs[20][100];
    int songCount;
} Album;

typedef struct {
    char name[100];
} Song;

// Prototipe fungsi-fungsi
void ListSingers(Singer singers[], int singerCount);
void ListAlbums(Singer singer);
void ListSongs(Album album);
void ListPlaylists(char *playlists[], int playlistCount);

#endif // LIST_H
