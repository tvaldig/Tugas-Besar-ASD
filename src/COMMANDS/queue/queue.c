#include "queue.h"
#include "../startload/startload.h"
#include "../list/list.h"

Word GetJudulLagu(Set SetLagu[], Word namaalbum, int idlagu)
{
    boolean found = false;
    Word NotFound = {"NOTFOUND",8};
    int idAlbum = GetIdAlbum(namaalbum), i = 0;
    Set S = SetLagu[Value(mapAlbum, idAlbum)];
    while(i < S.Count && !found){
        if(S.AlbumLagu[i].IdLagu == idlagu){
            found = true;
        } else{
            i++;
        }
    }
    if(found){
        return S.AlbumLagu[i].JudulLagu;
    } else {
        return NotFound;
    }
}
void queueFunction(){
    printf("ini untuk handle queue function\n");
}

void ClearQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
    printf("Queue berhasil dikosongkan.");
}

void QueueSong(Queue *q){
    char namapenyanyi[100];
    char judullagu[100];
    ListSingers(ArrayPenyanyi, ArrayPenyanyi.penyanyi);
    printf("Masukkan Nama Penyanyi : ");
    STARTCOMMAND(false);
    handleSemicolon(currentCommand);
    ConvertWordToString(&currentCommand, namapenyanyi);
    ListAlbums(mapAlbum, currentCommand);
    printf("Masukkan Nama Album yang dipilih :");
    STARTCOMMAND(false);
    handleSemicolon(currentCommand);
    Word NamaAlbum = currentCommand;
    ListSongs(SetLagu, currentCommand);
    printf("Masukkan ID Lagu yang dipilih: ");
    STARTCOMMAND(false);
    handleSemicolon(currentCommand);
    int idlagu = ConvertWordToInt(currentCommand);
    Word JudulLaguWord = GetJudulLagu(SetLagu, NamaAlbum, idlagu);
    ConvertWordToString(&JudulLaguWord, judullagu);
    printf("Berhasil menambahkan lagu %s oleh %s ke queue.", judullagu, namapenyanyi);
}