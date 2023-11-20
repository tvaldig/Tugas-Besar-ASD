all : run clean

driver: mesinkata.h driver-mesin-kata.c mesinkata.c ../MesinKarakter/mesinkarakter.c
	gcc -o main driver-mesin-kata.c mesinkata.c ../MesinKarakter/mesinkarakter.c

run: driver
	./main.exe

clean:
	del main.exe