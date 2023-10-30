
all: run clean

test: main.c COMMANDS/console.c ADT/MesinKata/mesinkata.c ADT/MesinKarakter/mesinkarakter.c
	gcc -o main main.c COMMANDS/console.c ADT/MesinKata/mesinkata.c ADT/MesinKarakter/mesinkarakter.c

run: test
	./main.exe

clean:
	del main.exe