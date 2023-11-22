#include "save.h"

void SAVE(){
    if(isLogin){
        printf("Silahkan logout terlebih dahulu.\n");
    } else {
        STARTCOMMAND(false);

        if (!IsCommandWithSemicolon(currentCommand))
        {
            unknownCommand();
            return;
        }

        handleSemicolon(currentCommand);

        Word direktori = {"../save/", 8};

        if (!(currentCommand.TabWord[currentCommand.Length - 4] == '.' && currentCommand.TabWord[currentCommand.Length - 3] == 't' && currentCommand.TabWord[currentCommand.Length - 2] == 'x' && currentCommand.TabWord[currentCommand.Length - 1] == 't'))
        {
            printf("Proses save gagal. Masukkan format file yang benar! (nama file harus diakhir .txt)\n\n");
            return;
        }

        NEWFILE(ConcatString(direktori, currentCommand).TabWord);

        WRITEINT(ArrayPenyanyi.Neff);

        WRITEENTER();

        for (int i = 0; i < ArrayPenyanyi.Neff; i++)
        {
            WRITEINT(ArrayPenyanyi.penyanyi[i].jumlahalbum);
            WRITEBLANK();
            WRITESTRING(ArrayPenyanyi.penyanyi[i].namapenyanyi.TabWord);
            WRITEENTER();

            for (int j = ArrayPenyanyi.penyanyi[i].IdAlbumPertama; j < ArrayPenyanyi.penyanyi[i].jumlahalbum + ArrayPenyanyi.penyanyi[i].IdAlbumPertama; j++)
            {
                int jumlahalbum = SetLagu[Value(mapAlbum, j)].Count;
                WRITEINT(jumlahalbum);
                WRITEBLANK();
                WRITESTRING(mapAlbum.Elements[j].AlbumName.TabWord);
                WRITEENTER();

                for (int k = 0; k < jumlahalbum; k++)
                {
                    WRITESTRING(SetLagu[Value(mapAlbum, j)].AlbumLagu[k].JudulLagu.TabWord);
                    WRITEENTER();
                }
            }
        }
        WRITEINT(JumlahUser);
        WRITEENTER();
        for (int a = 0; a < JumlahUser; a++)
        {
            WRITESTRING(Users[a].namauser.TabWord);
            WRITEENTER();
        }
        for (int a = 0; a < JumlahUser; a++)
        {
            if (isNotPlaying() || Users[a].current.album == IdxUndef)
            {
                WRITESTRING("-");
                WRITEENTER();
            }
            else
            {
                WRITESTRING(ArrayPenyanyi.penyanyi[Users[a].current.penyanyi].namapenyanyi.TabWord);
                WRITESEMICOLON();
                WRITESTRING(mapAlbum.Elements[Users[a].current.album].AlbumName.TabWord);
                WRITESEMICOLON();
                int idxset = Value(mapAlbum, Users[a].current.album);
                WRITESTRING(SetLagu[idxset].AlbumLagu[Users[a].current.lagu].JudulLagu.TabWord);
                WRITEENTER();
            }
            int panjangantrian = LengthQueue(Users[a].antrian);

            WRITEINT(panjangantrian);

            WRITEENTER();

            for (int i = 0; i < panjangantrian; i++)
            {
                WRITESTRING(ArrayPenyanyi.penyanyi[Users[a].antrian.Tab[i].penyanyi].namapenyanyi.TabWord);
                WRITESEMICOLON();
                WRITESTRING(mapAlbum.Elements[Users[a].antrian.Tab[i].album].AlbumName.TabWord);
                WRITESEMICOLON();
                int idxset = Value(mapAlbum, antrian.Tab[i].album);
                WRITESTRING(SetLagu[idxset].AlbumLagu[Users[a].antrian.Tab[i].lagu].JudulLagu.TabWord);
                WRITEENTER();
            }

            int panjangstack = Users[a].riwayat.TOP + 1;

            WRITEINT(panjangstack);

            WRITEENTER();

            for (int i = panjangstack - 1; i >= 0; i--)
            {
                WRITESTRING(ArrayPenyanyi.penyanyi[Users[a].riwayat.T[i].penyanyi].namapenyanyi.TabWord);
                WRITESEMICOLON();
                WRITESTRING(mapAlbum.Elements[Users[a].riwayat.T[i].album].AlbumName.TabWord);
                WRITESEMICOLON();
                int idxset = Value(mapAlbum, Users[a].riwayat.T[i].album);
                WRITESTRING(SetLagu[idxset].AlbumLagu[Users[a].riwayat.T[i].lagu].JudulLagu.TabWord);
                WRITEENTER();
            }

            WRITEINT(Users[a].playlists.Neff);

            if (Users[a].playlists.Neff != 0)
            {
                WRITEENTER();

                for (int i = 0; i < Users[a].playlists.Neff; i++)
                {
                    int jumlahlagu = countPlaylist(Users[a].playlists.A[i]);
                    WRITEINT(jumlahlagu);
                    WRITEBLANK();
                    WRITESTRING(Users[a].playlists.A[i].namaplaylist.TabWord);

                    if (jumlahlagu != 0 || i != Users[a].playlists.Neff - 1)
                    {
                        WRITEENTER();
                    }

                    addressnode p = First(Users[a].playlists.A[i]);

                    for (int j = 0; j < jumlahlagu; j++)
                    {
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
                    }
                }
            }
            if(a != JumlahUser -1)
            WRITEENTER();
        }

        int i = 0;
        printf("\n");
        while (currentCommand.TabWord[i] != '.')
        {
            printf("%c", currentCommand.TabWord[i]);
            i++;
        }
        printf(" berhasil disimpan.\n\n");

        WRITEFINISH();
    }
    
}