#include "save.h"

void SAVE(){
    STARTCOMMAND(false);

    if(!IsCommandWithSemicolon(currentCommand)){
        unknownCommand();
        return;
    }

    handleSemicolon(currentCommand);

    Word direktori = {"../save/",8};

    NEWFILE(ConcatString(direktori, currentCommand).TabWord);

    WRITEINT(ArrayPenyanyi.Neff);

    WRITEENTER();

    for(int i = 0; i < ArrayPenyanyi.Neff; i++){
        WRITEINT(ArrayPenyanyi.penyanyi[i].jumlahalbum);
        WRITEBLANK();
        WRITESTRING(ArrayPenyanyi.penyanyi[i].namapenyanyi.TabWord);
        WRITEENTER();

        for(int j = ArrayPenyanyi.penyanyi[i].IdAlbumPertama; j < ArrayPenyanyi.penyanyi[i].jumlahalbum + ArrayPenyanyi.penyanyi[i].IdAlbumPertama; j++){
            int jumlahalbum = SetLagu[Value(mapAlbum, j)].Count;
            WRITEINT(jumlahalbum);
            WRITEBLANK();
            WRITESTRING(mapAlbum.Elements[j].AlbumName.TabWord);
            WRITEENTER();

            for(int k = 0; k < jumlahalbum; k++){
                WRITESTRING(SetLagu[Value(mapAlbum, j)].AlbumLagu[k].JudulLagu.TabWord);
                WRITEENTER();
            }
        }
    }

    int panjangantrian = LengthQueue(antrian);

    WRITEINT(panjangantrian);

    WRITEENTER();

    for (int i = 0; i < panjangantrian; i++){
        WRITESTRING(ArrayPenyanyi.penyanyi[antrian.Tab[i].penyanyi].namapenyanyi.TabWord);
        WRITESEMICOLON();
        WRITESTRING(mapAlbum.Elements[antrian.Tab[i].album].AlbumName.TabWord);
        WRITESEMICOLON();
        int idxset = Value(mapAlbum, antrian.Tab[i].album);
        WRITESTRING(SetLagu[idxset].AlbumLagu[antrian.Tab[i].lagu].JudulLagu.TabWord);
        WRITEENTER();
    }

    int panjangstack = riwayat.TOP+1;

    WRITEINT(panjangstack);

    WRITEENTER();

    for (int i = panjangstack-1; i >= 0; i--){
        WRITESTRING(ArrayPenyanyi.penyanyi[riwayat.T[i].penyanyi].namapenyanyi.TabWord);
        WRITESEMICOLON();
        WRITESTRING(mapAlbum.Elements[riwayat.T[i].album].AlbumName.TabWord);
        WRITESEMICOLON();
        int idxset = Value(mapAlbum, riwayat.T[i].album);
        WRITESTRING(SetLagu[idxset].AlbumLagu[riwayat.T[i].lagu].JudulLagu.TabWord);
        WRITEENTER();
    }

    WRITEINT(playlists.Neff);

    if(playlists.Neff != 0){
        WRITEENTER();

        for(int i = 0; i < playlists.Neff; i++){
            int jumlahlagu = countPlaylist(playlists.A[i]);
            WRITEINT(jumlahlagu);
            WRITEBLANK();
            WRITESTRING(playlists.A[i].namaplaylist.TabWord);

            if(jumlahlagu != 0 || i != playlists.Neff-1){
                WRITEENTER();
            }

            addressnode p = First(playlists.A[i]);

            for(int j = 0; j < jumlahlagu; j++){
                int indekspenyanyi = p->idpenyanyi;
                int indeksalbum = p->idalbum;
                int indekslagu = p->idlagu;
                p = Next(p);
                WRITESTRING(ArrayPenyanyi.penyanyi[indekspenyanyi].namapenyanyi.TabWord);
                WRITESEMICOLON();
                WRITESTRING(mapAlbum.Elements[indeksalbum].AlbumName.TabWord);
                WRITESEMICOLON();
                int idxset = Value(mapAlbum, indeksalbum);
                WRITESTRING(SetLagu[idxset].AlbumLagu[indekslagu].JudulLagu.TabWord);
                if (i != playlists.Neff - 1 || j != jumlahlagu - 1){
                    WRITEENTER();
                }
            }

        }
    }

    WRITEFINISH();
}