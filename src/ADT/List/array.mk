all: run clean

driver: 
	gcc -o main array.c array.h driver-array.c ../MesinKata/mesinkata.c ../MesinKarakter/mesinkarakter.c

run: driver
	./main

clean:
	del main.exe