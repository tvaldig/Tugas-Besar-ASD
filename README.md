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
> save/0.txt

> save/1.txt

> save/new.txt

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
│   └─── wayangwave.txt                        
│ 
├── src
│   ├─── ADT
│   │      ├─── Graph
│   │      │       ├─── driver-graph.c
│   │      │       ├─── graph.c
│   │      │       ├─── graph.h
│   │      │       └─── graph.mk
│   │      │				   
│   │      ├─── Linked_List
│   │      │       ├─── driver-linked-list.c
│   │      │       ├─── linked_list.c
│   │      │       ├─── linked_list.h
│   │      │       └─── linkedlist.mk
│   │      │
│   │      ├─── List
│   │      │       ├─── array.c
│   │      │       ├─── array.h
│   │      │       ├─── array.mk
│   │      │       ├─── arraydin.c
│   │      │       ├─── arraydin.h
│   │      │       ├─── arraydin.mk
│   │      │       ├─── driver-array.c
│   │      │       └─── driver-arraydin.c
│   │      │
│   │      ├─── Map
│   │      │      ├─── driver-map.c
│   │      │      ├─── map.c
│   │      │      ├─── map.h
│   │      │      └─── map.mk
│   │      │
│   │      ├─── MesinKarakter
│   │      │       ├─── driver-mesin-karakter.c
│   │      │       ├─── driver.txt
│   │      │       ├─── mesinkarakter.c
│   │      │       ├─── mesinkarakter.h
│   │      │       ├─── mesinkarakter.mk
│   │      │       └─── new.txt
│   │      │
│   │      ├─── MesinKata
│   │      │       ├─── driver-mesin-kata.c
│   │      │       ├─── mesinkata.c
│   │      │       ├─── mesinkata.h
│   │      │       └─── mesinkata.mk
│   │      │
│   │      ├─── Queue
│   │      │       ├─── circular_queue.c
│   │      │       ├─── circular_queue.h
│   │      │       ├─── driver-queue.c
│   │      │       └─── queue.mk
│   │      │
│   │      └─── Set
│   │      │       ├─── driver-set.c
│   │      │       ├─── set.c
│   │      │       ├─── set.h
│   │      │       └─── set.mk
│   │      └─── Stack
│   │      │      ├─── driver-stack.c
│   │      │      ├─── stack.c
│   │      │      ├─── stack.h
│   │      │      └─── stack.mk
│   │      │ 
│   │      └─── ADT.h
│   │
│   └─── COMMANDS
│   │       ├─── LIST
│   │       │       ├─── list.c
│   │       │       └─── list.h
│   │       ├─── enchance
│   │       │       ├─── enchance.c
│   │       │       └─── enchance.h
│   │       ├─── help
│   │       │       ├─── help.c
│   │       │       └─── help.h
│   │       ├─── invalidCommand
│   │       │       ├─── invalidCommand.c
│   │       │       └─── invalidCommand.h
│   │       ├─── play
│   │       │       ├─── play.c
│   │       │       └─── play.h
│   │       ├─── playlist
│   │       │       ├─── playlist.c
│   │       │       └─── playlist.h
│   │       ├─── queue
│   │       │       ├─── queue.c
│   │       │       └─── queue.h
│   │       ├─── quit
│   │       │       ├─── quit.c
│   │       │       ├─── quit.exe
│   │       │       └─── quit.h
│   │       ├─── radio
│   │       │       ├─── radio.c
│   │       │       └─── radio.h
│   │       ├─── save
│   │       │       ├─── save.c
│   │       │       └─── save.h
│   │       ├─── search-print
│   │       │       ├─── searchprint.c
│   │       │       └─── searchprint.h
│   │       ├─── song
│   │       │       ├─── song.c
│   │       │       └─── song.h
│   │       ├─── starload
│   │       │       ├─── starload.c
│   │       │       └─── starload.h
│   │       ├─── status
│   │       │       ├─── status.c
│   │       │       └─── status.h
│   │       ├─── welcomeMenu
│   │       │       ├─── welcomemenu.c
│   │       │       └─── welcomemenu.h
│   │       └─── commands.h
│   │
│   ├─── boolean.h
│   ├─── main.c                # implementasi of all commands
│   ├─── run.mk
│   └─── runonlinux.mk  
│
└─── README.md
 ```
 