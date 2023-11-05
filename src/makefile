all: run clean

test: main.c COMMANDS/welcomeMenu/welcomemenu.c COMMANDS/start/start.c ADT/MesinKata/mesinkata.c ADT/MesinKarakter/mesinkarakter.c ADT/List/array.c COMMANDS/invalidCommand/invalidCommand.c COMMANDS/help/help.c ./ADT/Queue/circular_queue.c ./ADT/Stack/stack.c ./ADT/List/arraydin.c ./ADT/Linked-List/linked_list.c
	gcc -o main main.c COMMANDS/welcomeMenu/welcomemenu.c COMMANDS/start/start.c ADT/MesinKata/mesinkata.c ADT/MesinKarakter/mesinkarakter.c ADT/List/array.c COMMANDS/invalidCommand/invalidCommand.c COMMANDS/help/help.c ./ADT/Queue/circular_queue.c ./ADT/Stack/stack.c ./ADT/List/arraydin.c ./ADT/Linked-List/linked_list.c

run: test
	./main.exe

clean:
	del main.exe