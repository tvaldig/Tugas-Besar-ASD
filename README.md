# Tugas-Besar - SPOTIFILE
## IF2111 Algoritma dan Struktur Data STI


Dibuat oleh Kelompok 1 K01

1. Bihurin Salsabila Firdaus (18222015)
2. David Dewanto (18222027)
3. Muhammad Rafi Dhiyaulhaq (18222069)
4. Alvin Fadhilah Akmal (18222079)
5. Timotius Vivaldi Gunawan (18222091)

## Deskripsi Singkat Laporan

## Cara Kompilasi Program
> gcc -o main main.c COMMANDS/welcomeMenu/welcomemenu.c COMMANDS/list/list.c COMMANDS/play/play.c COMMANDS/save/save.c COMMANDS/song/song.c COMMANDS/playlist/playlist.c  COMMANDS/queue/queue.c  COMMANDS/search-print/searchprint.c COMMANDS/startload/startload.c ADT/MesinKata/mesinkata.c ADT/MesinKarakter/mesinkarakter.c ADT/List/array.c COMMANDS/invalidCommand/invalidCommand.c COMMANDS/help/help.c ./ADT/Queue/circular_queue.c ./ADT/Stack/stack.c ./ADT/List/arraydin.c ./ADT/Linked-List/linked_list.c ./ADT/Map/map.c ./ADT/Set/set.c 

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
├── save
│   ├─── konfigurasi.txt		    
│   ├─── new.txt		     
│   ├─── test.txt	
│   ├─── testing.txt
│   └───wayangwave.txt                        
│ 
├── source
│   ├─── boolean.h
│   ├─── main.c
│   ├─── main.exe
│   ├─── makefile
│   ├─── testing.mk     
│   ├─── ADT				    # folder berisikan main
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
 

