#include "queue.h"
#include "../startload/startload.h"
#include "../list/list.h"

boolean isEqual(int a, int b){
    return a == b;
}
Word GetJudulLagu(Set SetLagu[], Word namaalbum, int idlagu)
{
    boolean found = false;
    Word NotFound = {"NOTFOUND",8};
    int idAlbum = GetIdAlbum(namaalbum);
    int i = 0, index;
    Set S = SetLagu[Value(mapAlbum, idAlbum)];
    idlagu = idlagu-1;

    while(i < S.Count && !found){
        if(i == idlagu){
            return S.AlbumLagu[i].JudulLagu;
        }
        i++;
    }        
    return NotFound;
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
    Word WNamaPenyanyi = currentCommand;
    ConvertWordToString(&currentCommand, namapenyanyi);

    //prosedur memberikan list album
    ListAlbums(mapAlbum, currentCommand);

    //prosedur untuk memilih nama album
    printf("Masukkan Nama Album yang dipilih :");
    STARTCOMMAND(false);
    handleSemicolon(currentCommand);
    Word NamaAlbum = currentCommand;

    //prosedur memberikan list lagu
    ListSongs(SetLagu, currentCommand);

    //prosedur untuk memilih ID lagu
    printf("Masukkan ID Lagu yang dipilih: ");
    STARTCOMMAND(false);
    handleSemicolon(currentCommand);
    int idlagu = ConvertWordToInt(currentCommand);

    //mencari judul lagu menggunakan ID
    Word JudulLaguWord = GetJudulLagu(SetLagu, NamaAlbum, idlagu);
    ConvertWordToString(&JudulLaguWord, judullagu);

    if(IsStringEqual(judullagu, "NOTFOUND")){ //jika id tidak ditemukan maka queue gagal
        printf("Queue Song Gagal. ID Lagu tidak ditemukan!\n");
    } else {
        enqueue(q, SearchPenyanyi(WNamaPenyanyi), GetIdAlbum(NamaAlbum), idlagu);
        printf("Berhasil menambahkan lagu %s oleh %s ke queue.\n", judullagu, namapenyanyi);
    }   
    
}

void QueuePlaylist(Queue *q){

}

void QueueRemove(Queue *q, int id)
{
    int idlagu, idpenyanyi, idalbum;
    char judullagu[100], namapenyanyi[100];
    if (id > IDX_TAIL(*q))
    {
        printf("Lagu dengan urutan ke %d tidak ada.\n", id);
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
                
                for (int j = i; j < IDX_HEAD(*q) + LengthQueue(*q); j++)
                {
                    q->Tab[j % (IDX_MAX)].album = q->Tab[j + 1 % (IDX_MAX )].album;
                    q->Tab[j % (IDX_MAX)].lagu = q->Tab[j + 1 % (IDX_MAX )].lagu;
                    q->Tab[j % (IDX_MAX)].penyanyi = q->Tab[j + 1 % (IDX_MAX)].penyanyi;
                    q->Tab[j + 1 % (IDX_MAX)].album = IDX_UNDEF;
                    q->Tab[j + 1 % (IDX_MAX)].lagu = IDX_UNDEF;
                    q->Tab[j + 1 % (IDX_MAX)].penyanyi = IDX_UNDEF;
                    if(IDX_TAIL(*q) == 0){
                        IDX_TAIL(*q) == IDX_MAX;
                    } else {
                        IDX_TAIL(*q)
                        --;
                    }
                   
                }
            }
            
        }
        ConvertWordToString(&ArrayPenyanyi.penyanyi[idpenyanyi].namapenyanyi, namapenyanyi);
        Word Wjudullagu = SetLagu[Value(mapAlbum, idalbum)].AlbumLagu->JudulLagu;
        ConvertWordToString(&Wjudullagu, judullagu);
        displayQueue(*q);
        printf("Lagu %s oleh %s telah dihapus dari queue!\n", judullagu, namapenyanyi);
    }
}