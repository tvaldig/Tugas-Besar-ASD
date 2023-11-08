all: run clean

test: main.c COMMANDS/welcomeMenu/welcomemenu.c COMMANDS/startload/start-test.c ADT/MesinKata/mesinkata.c ADT/MesinKarakter/mesinkarakter.c ADT/List/array.c COMMANDS/invalidCommand/invalidCommand.c COMMANDS/help/help.c ./ADT/Queue/circular_queue.c ./ADT/Stack/stack.c ./ADT/List/arraydin.c ./ADT/Linked-List/linked_list.c ./ADT/Map/map.c ./ADT/Set/set.c 
	gcc -o main main.c COMMANDS/welcomeMenu/welcomemenu.c COMMANDS/startload/start-test.c ADT/MesinKata/mesinkata.c ADT/MesinKarakter/mesinkarakter.c ADT/List/array.c COMMANDS/invalidCommand/invalidCommand.c COMMANDS/help/help.c ./ADT/Queue/circular_queue.c ./ADT/Stack/stack.c ./ADT/List/arraydin.c ./ADT/Linked-List/linked_list.c ./ADT/Map/map.c ./ADT/Set/set.c 

run: test
	./main.exe

clean: del
	./main.exe