#include "queue.h"
#include "../startload/startload.h"
#include "../list/list.h"


Word SearchJudulFromId(int idalbum, int idlagu){
    return SetLagu[Value(mapAlbum, idalbum)].AlbumLagu[idlagu].JudulLagu;
}

boolean isIdFound(Queue *q, int id){
    for (int i = IDX_HEAD(*q); i < IDX_HEAD(*q) + LengthQueue(*q); i++)
    {
        if(i == id){
            return true;
        }
    }
    return false;
}


void ClearQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
    printf("Queue berhasil dikosongkan.\n");
}

void QueueSong(Queue *q){
    char namapenyanyi[100];
    char judullagu[100];

    //prosedur memberikan list penyanyi
    ListSingers(ArrayPenyanyi, ArrayPenyanyi.Neff);

    //prosedur untuk memilih nama penyanyi
    printf("Masukkan Nama Penyanyi : ");
    STARTCOMMAND(false);
    handleSemicolon(currentCommand);
    int idpenyanyi = searchidpenyanyi(ArrayPenyanyi, currentCommand);
    ConvertWordToString(&currentCommand, namapenyanyi);
  
    //prosedur memberikan list album
    ListAlbums(mapAlbum, currentCommand);

    //prosedur untuk memilih nama album
    printf("Masukkan Nama Album yang dipilih :");
    STARTCOMMAND(false);
    handleSemicolon(currentCommand);
    Word NamaAlbum = currentCommand;

    //prosedur memberikan list lagu
    ListSongs(SetLagu, currentCommand, idpenyanyi);

    //prosedur untuk memilih ID lagu
    printf("Masukkan ID Lagu yang dipilih: ");
    STARTCOMMAND(false);
    handleSemicolon(currentCommand);
    int idlagu = ConvertWordToInt(currentCommand);

    //mencari judul lagu menggunakan ID
    Word JudulLaguWord = GetJudulLagu(SetLagu, NamaAlbum, idlagu, idpenyanyi);
    ConvertWordToString(&JudulLaguWord, judullagu);

    if(IsStringEqual(judullagu, "NOTFOUND")){ //jika id tidak ditemukan maka queue gagal
        printf("Queue Song Gagal. ID Lagu tidak ditemukan!\n");
    } else {
        NotPlayingPlaylist();
        printf("%d\n", isNotPlayingPlaylist());
        enqueue(q, idpenyanyi, searchidalbum(ArrayPenyanyi, idpenyanyi, NamaAlbum, mapAlbum), idlagu-1);
        printf("Berhasil menambahkan lagu %s oleh %s ke queue.\n", judullagu, namapenyanyi);
    }   
    
}

void QueuePlaylist(Queue *q, ArrayDin *playlists){
    printf("Masukan ID Playlist: ");
    STARTCOMMAND(false);
    handleSemicolon(currentCommand);
    int idplaylist = ConvertWordToInt(currentCommand);
    if(idplaylist > playlists->Neff){
        printf("Queue Playlist gagal. ID Playlist tidak ditemukan!\n");
    } else {
        playlist ply = playlists->A[idplaylist];
        addressnode P = First(ply);
        while (P != null)
        {
            enqueue(q, PENYANYI(P), ALBUM(P), LAGU(P));
            P = Next(P);
        }
        if(idplaylist != currentIdPlaylist){
            NotPlayingPlaylist();
        }
        printf("Berhasil menambahkan playlist %s ke queue.\n", ply.namaplaylist.TabWord);
    }
}

void QueueRemove(Queue *q, int id)
{
    int idlagu, idpenyanyi, idalbum;
    char judullagu[100], namapenyanyi[100];
    if (id > IDX_TAIL(*q) || id < 0)
    {
        printf("Lagu dengan urutan ke %d tidak ada.\n", id);
    } else if(id < 0){
        printf("Urutan lagu tidak valid.\n");
    }
    else
    {
        for (int i = IDX_HEAD(*q); i < IDX_HEAD(*q) + LengthQueue(*q); i++)
        {
            if (i == id)
            {
                idlagu = q->Tab[i].lagu;
                idpenyanyi = q->Tab[i].penyanyi;
                idalbum = q->Tab[i].album;
                
                for (int j = i; j < i +  LengthQueue(*q); j++)
                {
                    q->Tab[j % (IDX_MAX + 1)].album = q->Tab[(j + 1) % (IDX_MAX + 1 )].album;
                    q->Tab[j % (IDX_MAX + 1)].lagu = q->Tab[(j + 1) % (IDX_MAX + 1)].lagu;
                    q->Tab[j % (IDX_MAX + 1)].penyanyi = q->Tab[(j + 1) % (IDX_MAX + 1)].penyanyi;
                    q->Tab[(j + 1) % (IDX_MAX + 1)].album = IDX_UNDEF;
                    q->Tab[(j + 1) % (IDX_MAX + 1)].lagu = IDX_UNDEF;
                    q->Tab[(j + 1) % (IDX_MAX + 1)].penyanyi = IDX_UNDEF;
                    
                }
                break;
            }
            
        }
        IDX_TAIL(*q)
        --;
        ConvertWordToString(&ArrayPenyanyi.penyanyi[idpenyanyi].namapenyanyi, namapenyanyi);
        Word judul = SearchJudulFromId(idalbum, idlagu);
        ConvertWordToString(&judul, judullagu);
        printf("Lagu %s oleh %s telah dihapus dari queue!\n", judullagu, namapenyanyi);
    }
}

void QueueSwap(Queue *q, int id1, int id2){
    char judullagu1[100];
    char judullagu2[100];
    if(isIdFound(q, id1) && isIdFound(q, id2)){
        int tempalbum = q->Tab[id1].album;
        int temppenyanyi = q->Tab[id1].penyanyi;
        int templagu = q->Tab[id1].lagu;

        q->Tab[id1].album = q->Tab[id2].album;
        q->Tab[id1].penyanyi = q->Tab[id2].penyanyi;
        q->Tab[id1].lagu = q->Tab[id2].lagu;

        q->Tab[id2].album = tempalbum;
        q->Tab[id2].penyanyi = temppenyanyi;
        q->Tab[id2].lagu = templagu;

        Word judul1 = SearchJudulFromId(tempalbum, templagu);
        ConvertWordToString(&judul1, judullagu1);
        Word judul2 = SearchJudulFromId(q->Tab[id1].album, q->Tab[id1].lagu);
        ConvertWordToString(&judul2, judullagu2);
        printf("Lagu %s berhasil ditukar dengan %s \n", judullagu1, judullagu2);
    } else if(isIdFound(q, id1) && !isIdFound(q, id2)){
        printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", id2);
    }
    else if (!isIdFound(q, id1) && isIdFound(q, id2)){
        printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", id1);
    } else {
        printf("Lagu dengan urutan ke %d dan urutan ke %d tidak terdapat dalam queue!\n", id1, id2);
    }
}