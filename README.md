# Tugas-Besar - SPOTIFILE
## IF2111 Algoritma dan Struktur Data STI

> Program WayangWave yang dapat meluluhkan hati Roro 

Dibuat oleh Kelompok 1 K01

1. Bihurin Salsabila Firdaus (18222015)
2. David Dewanto (18222027)
3. Muhammad Rafi Dhiyaulhaq (18222069)
4. Alvin Fadhilah Akmal (18222079)
5. Timotius Vivaldi Gunawan (18222091)

## Deskripsi Singkat Laporan
WayangWave merupakan program simulasi media player layaknya walkman. WayangWave memiliki fitur utama yang dapat dilakukan oleh pengguna yaitu memutar lagu, menampilkan daftar lagu, membuat dan menghapus playlist, mengatur urutan dimainkannya lagu, menampilkan status dari aplikasi. Semua perubahan yang kita lakukan terhadap program pada saat memutar musik seperti menambahkan dan juga menghapus playlist dapat disimpan pada sebuah file.

## Cara Kompilasi Program
> -C src -f run.mk

## Configuration File yang Tersedia
> save/konfigurasi.txt

## Save File yang Tersedia
> save/new.txt

> save/test.txt

## Struktur Program
```
.
├── .vscode
│   ├─── c_cpp_properties.json		    
│   ├─── launch.json		     
│   └─── settings.json                   
│
├── docs 
│    ├─── Form Asistensi Tugas Besar_TB1_01_01.pdf
│    ├─── IF2111_TB1_01_01.pdf
│    └─── Spesifikasi Tugas Besar IF2111 2023/2024.pdf 
│
├── save
│   ├─── 0.txt
│   ├─── 1.txt
│   ├─── konfigurasi.txt	  # config yang akan dibaca
│   ├─── new.txt		      # file yang disimpan oleh user
│   └───wayangwave.txt                        
│ 
├── src
│   ├─── boolean.h
│   ├─── main.c                # implementasi of all commands
│   ├─── main.exe
│   ├─── makefile
│   ├─── testing.mk     
│   ├─── ADT				   
│   │      ├─── Linked_List
│   │      │       ├─── driver-linked-list,c
│   │      │       ├─── linked_list.c
│   │      │       ├─── linked_list.h
│   │      │       └───  makefile
│   │      │
│   │      ├─── List
│   │      │       ├─── array.c
│   │      │       ├─── array.h
│   │      │       ├─── arraydin.c
│   │      │       ├─── arraydin.h
│   │      │       ├─── arraydin.mk
│   │      │       └─── driver-arraydin.c
│   │      │
│   │      ├─── Map
│   │      │       ├─── map.c
│   │      │       └───  map.h
│   │      │
│   │      ├─── MesinKarakter
│   │      │       ├─── mesinkarakter.c
│   │      │       └─── mesinkarakter.h
│   │      │
│   │      ├─── MesinKata
│   │      │       ├─── mesinkata.c
│   │      │       └───  mesinkata.h
│   │      │
│   │      ├─── Queue
│   │      │       ├─── circular_queue.c
│   │      │       ├─── circular_queue.h
│   │      │       ├───  driver-queue.c
│   │      │       └─── makefile
│   │      │
│   │      └─── Set
│   │      │       ├─── driver-set.c
│   │      │       ├─── main.exe
│   │      │       ├───  set.c
│   │      │       └─── set.h
│   │      └─── Stack
│   │      │      ├─── driver-stack.c
│   │      │      ├─── makefile
│   │      │      ├─── stack.c
│   │      │      └─── stack.h
│   │      │ 
│   │      └─── ADT.h
│   │
│   └─── COMMANDS
│           ├─── LIST
│           │       ├─── list.c
│           │       └─── list.h
│           ├─── enchance
│           │       ├─── enchance.c
│           │       └─── enchance.h
│           ├─── help
│           │       ├─── help.c
│           │       └─── help.h
│           ├─── invalidCommand
│           │       ├─── invalidCommand.c
│           │       └─── invalidCommand.h
│           ├─── play
│           │       ├─── play.c
│           │       └─── play.h
│           ├─── playlist
│           │       ├─── playlist.c
│           │       └─── playlist.h
│           ├─── queue
│           │       ├─── queue.c
│           │       └─── queue.h
│           ├─── save
│           │       ├─── save.c
│           │       └─── save.h
│           ├─── search-print
│           │       ├─── searchprint.c
│           │       └─── searchprint.h
│           ├─── song
│           │       ├─── song.c
│           │       └─── song.h
│           ├─── starload
│           │       ├─── starload.c
│           │       └─── starload.h
│           ├─── status
│           │       ├─── status.c
│           │       └─── status.h
│           ├─── welcomeMenu
│           │       ├─── welcomemenu.c
│           │       └─── welcomemenu.h
│           └─── commands.h
│
└─── README.md
 ```
 