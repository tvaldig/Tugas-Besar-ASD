#include "song.h"

void SongNext(){
    Word JudulLagu;
    Word NamaPenyanyi;
    Word NamaAlbum;
    char namaPenyanyi[100];
    char judulLagu[100];
    if (isNotPlaying() && IsEmptyQueue (antrian)){
        printf("Queue kosong dan tidak ada lagu yang sedang dimainkan\n");
    }
    else if (IsEmptyQueue(antrian)){
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
        dequeue(&antrian, &(&current)->penyanyi, &(&current)->album, &(&current)->lagu);
        
        //Mencari Judul Lagu yang akan dimainkan
        NamaAlbum = GetNamaAlbum(ArrayPenyanyi, current.penyanyi, current.album, mapAlbum);
        JudulLagu = GetJudulLagu(SetLagu, NamaAlbum, current.lagu+1, current.penyanyi);
        
        //Mencari Nama Penyanyi
        NamaPenyanyi = GetNamaPenyanyi(ArrayPenyanyi, current.penyanyi);

        //Mengubah Judul Lagu dan Nama Penyanyi menjadi string
        ConvertWordToString(&JudulLagu, judulLagu);
        ConvertWordToString(&NamaPenyanyi, namaPenyanyi);

        //Output
        printf("Memutar lagu selanjutnya\n");
        printf("\"%s\" oleh \"%s\"\n", judulLagu, namaPenyanyi);
    }
}

void SongPrevious(){
    /*
    Word JudulLagu;
     Word NamaPenyanyi;
     Word NamaAlbum;
     char namaPenyanyi[100];
     char judulLagu[100];
     if (isNotPlaying() && IsEmptyStack (riwayat)){
         printf("Riwayat lagu kosong dan tidak ada lagu yang sedang dimainkan");
     }
     if(IsEmptyStack(riwayat)){
         //Mencari Judul Lagu yang sedang dimainkan
         NamaAlbum = GetNamaAlbum(ArrayPenyanyi, current.penyanyi, current.album, mapAlbum);
         JudulLagu = GetJudulLagu(SetLagu, NamaAlbum, current.lagu, current.penyanyi);
         //Mencari Nama Penyanyi
         NamaPenyanyi = GetNamaPenyanyi(ArrayPenyanyi, current.penyanyi);

         //Mengubah Judul Lagu dan Nama Penyanyi menjadi string
         ConvertWordToString(&JudulLagu, judulLagu);
         ConvertWordToString(&NamaPenyanyi, namaPenyanyi);

         //Output
         printf("Riwayat lagu kosong, memutar kembali lagu\n");
         printf("\"%s\" oleh \"%s\"", judulLagu, namaPenyanyi);
     }
     else {
         //Membuat temporary queue agar lagu yang dimainkan bisa ditaruh di head
         Queue temp;
         IdxType penyanyitemp;
         IdxType albumtemp;
         IdxType lagutemp;
         CreateQueue(&temp);

         //Memasukkan lagu yang dimainkan ke temp dan memasukkan sisanya dari antrian
         enqueue(&temp, current.penyanyi, current.album, current.lagu);
         while (!IsEmptyQueue(antrian)){
             dequeue(&antrian, &penyanyitemp, &albumtemp, &lagutemp);
             enqueue(&temp, penyanyitemp, albumtemp, lagutemp);
         }

         //Memindahkan kembali isi temp ke antrian
         while(!IsEmptyQueue(temp)){
             dequeue(&temp, &penyanyitemp, albumtemp, lagutemp);
             enqueue(&antrian, penyanyitemp, albumtemp, lagutemp);

         //Mengganti lagu ke lagu sebelumnya
         Pop(&riwayat, current.penyanyi, current.album, current.lagu);

         //Mencari Judul Lagu akan dimainkan
         NamaAlbum = GetNamaAlbum(ArrayPenyanyi, current.penyanyi, current.album, mapAlbum);
         JudulLagu = GetJudulLagu(SetLagu, NamaAlbum, current.lagu, current.penyanyi);

         //Mencari Nama Penyanyi
         NamaPenyanyi = GetNamaPenyanyi(ArrayPenyanyi, current.penyanyi);

         //Mengubah Judul Lagu dan Nama Penyanyi menjadi string
         ConvertWordToString(&JudulLagu, judulLagu);
         ConvertWordToString(&NamaPenyanyi, namaPenyanyi);

         //Output
         printf("Memutar lagu sebelumnya\n");
         printf("\"%s\" oleh \"%s\"", judulLagu, namaPenyanyi);
         }
     }
    */
}
