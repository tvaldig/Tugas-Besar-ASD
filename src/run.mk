all: run clean 

test: main.c COMMANDS/welcomeMenu/welcomemenu.c COMMANDS/LIST/list.c COMMANDS/quit/quit.c COMMANDS/play/play.c  COMMANDS/enhance/enhance.c COMMANDS/status/status.c  COMMANDS/save/save.c COMMANDS/song/song.c COMMANDS/playlist/playlist.c COMMANDS/queue/queue.c COMMANDS/search-print/searchprint.c   COMMANDS/startload/startload.c ADT/MesinKata/mesinkata.c ADT/MesinKarakter/mesinkarakter.c ADT/List/array.c COMMANDS/invalidCommand/invalidCommand.c COMMANDS/help/help.c ./ADT/Queue/circular_queue.c ./ADT/Stack/stack.c ./ADT/List/arraydin.c ./ADT/Linked-List/linked_list.c ./ADT/Map/map.c ./ADT/Set/set.c 
	gcc -o main main.c COMMANDS/welcomeMenu/welcomemenu.c COMMANDS/LIST/list.c COMMANDS/quit/quit.c COMMANDS/play/play.c  COMMANDS/enhance/enhance.c COMMANDS/status/status.c COMMANDS/save/save.c COMMANDS/song/song.c COMMANDS/playlist/playlist.c  COMMANDS/queue/queue.c  COMMANDS/search-print/searchprint.c COMMANDS/startload/startload.c ADT/MesinKata/mesinkata.c ADT/MesinKarakter/mesinkarakter.c ADT/List/array.c COMMANDS/invalidCommand/invalidCommand.c COMMANDS/help/help.c ./ADT/Queue/circular_queue.c ./ADT/Stack/stack.c ./ADT/List/arraydin.c ./ADT/Linked-List/linked_list.c ./ADT/Map/map.c ./ADT/Set/set.c 

run: test
	./main

clean:
	del main.exe
	
