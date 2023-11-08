#include <stdio.h>

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

// Fungsi untuk menampilkan daftar penyanyi
void ListSingers(Singer singers[], int singerCount) {
    printf("Daftar Penyanyi:\n");
    for (int i = 0; i < singerCount; i++) {
        printf("%d. %s\n", i + 1, singers[i].name);
    }
}

// Fungsi untuk menampilkan daftar album penyanyi
void ListAlbums(Singer singer) {
    printf("Daftar Album oleh %s:\n", singer.name);
    for (int i = 0; i < singer.albumCount; i++) {
        printf("%d. %s\n", i + 1, singer.albums[i]);
    }
}

// Fungsi untuk menampilkan daftar lagu dalam album
void ListSongs(Album album) {
    printf("Daftar Lagu di %s:\n", album.name);
    for (int i = 0; i < album.songCount; i++) {
        printf("%d. %s\n", i + 1, album.songs[i]);
    }
}

// Fungsi untuk menampilkan daftar playlist pengguna
void ListPlaylists(char *playlists[], int playlistCount) {
    printf("Daftar playlist yang kamu miliki:\n");
    for (int i = 0; i < playlistCount; i++) {
        printf("%d. %s\n", i + 1, playlists[i]);
    }
}