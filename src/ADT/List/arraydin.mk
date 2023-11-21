all: run clean

driver: 
	gcc -o main arraydin.c driver-arraydin.c ../MesinKata/mesinkata.c ../MesinKarakter/mesinkarakter.c

run: driver
	./main

clean:
	del main.exe