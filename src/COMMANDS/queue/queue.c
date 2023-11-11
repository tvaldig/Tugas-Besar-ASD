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
    printf("%d\n", S.idSet);
    idlagu = idlagu-1;

    while(i < S.Count && !found){
        if(i == idlagu){
            return S.AlbumLagu[i].JudulLagu;
        }
        i++;
    }        
    return NotFound;
}
void queueFunction(){
    printf("ini untuk handle queue function\n");
}

void ClearQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
    displayQueue(*q);
    printf("Queue berhasil dikosongkan.\n");
}

void QueueSong(Queue *q){
    char namapenyanyi[100];
    char judullagu[100];
    ListSingers(ArrayPenyanyi, ArrayPenyanyi.Neff);
    printf("Masukkan Nama Penyanyi : ");
    STARTCOMMAND(false);
    handleSemicolon(currentCommand);
    Word WNamaPenyanyi = currentCommand;
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
    if(IsStringEqual(judullagu, "NOTFOUND")){
        printf("Queue Song Gagal. ID Lagu tidak ditemukan!\n");
    } else {
        enqueue(q, SearchPenyanyi(WNamaPenyanyi), GetIdAlbum(NamaAlbum), idlagu);
        printf("Berhasil menambahkan lagu %s oleh %s ke queue.\n", judullagu, namapenyanyi);
    }   
    
}