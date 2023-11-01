
all: run clean

test: main.c COMMANDS/welcomeMenu/welcomemenu.c COMMANDS/start/start.c ADT/MesinKata/mesinkata.c ADT/MesinKarakter/mesinkarakter.c ADT/List/array.c
	gcc -o main main.c COMMANDS/welcomeMenu/welcomemenu.c COMMANDS/start/start.c ADT/MesinKata/mesinkata.c ADT/MesinKarakter/mesinkarakter.c ADT/List/array.c

run: test
	./main.exe

clean:
	del main.exe