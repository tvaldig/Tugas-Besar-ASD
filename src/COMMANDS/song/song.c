#include "song.h"

void SongNext(){
    Word JudulLagu;
    Word NamaPenyanyi;
    Word NamaAlbum;
    char namaPenyanyi[100];
    char judulLagu[100];
    if (IsEmptyQueue(antrian)){
        //Mencari Judul Lagu yang sedang dimainkan
        NamaAlbum = GetNamaAlbum(ArrayPenyanyi, current.penyanyi, current.album, mapAlbum);
        JudulLagu = GetJudulLagu(SetLagu, NamaAlbum, current.lagu, current.penyanyi);
        //Mencari Nama Penyanyi
        NamaPenyanyi = GetNamaPenyanyi(ArrayPenyanyi, current.penyanyi);

        //Mengubah Judul Lagu dan Nama Penyanyi menjadi string
        ConvertWordToString(&JudulLagu, judulLagu);
        ConvertWordToString(&NamaPenyanyi, namaPenyanyi);

        //Output
        printf("Queue kosong, memutar kembali lagu\n");
        printf("\"%s\" oleh \"%s\"", judulLagu, namaPenyanyi);
    }
    else{
        //Memasukkan lagu yang dimainkan ke riwayat
        Push(&riwayat, current.penyanyi, current.album, current.lagu);

        //Mengganti lagu yang dimainkan menjadi lagu selanjutnya dalam antrian
        dequeue(&antrian, (&current)->penyanyi, (&current)->album, (&current)->lagu);
        
        //Mencari Judul Lagu yang akan dimainkan
        NamaAlbum = GetNamaAlbum(ArrayPenyanyi, current.penyanyi, current.album, mapAlbum);
        JudulLagu = GetJudulLagu(SetLagu, NamaAlbum, current.lagu, current.penyanyi);
        
        //Mencari Nama Penyanyi
        NamaPenyanyi = GetNamaPenyanyi(ArrayPenyanyi, current.penyanyi);

        //Mengubah Judul Lagu dan Nama Penyanyi menjadi string
        ConvertWordToString(&JudulLagu, judulLagu);
        ConvertWordToString(&NamaPenyanyi, namaPenyanyi);

        //Output
        printf("Memutar lagu selanjutnya\n");
        printf("\"%s\" oleh \"%s\"", judulLagu, namaPenyanyi);
    }
}
