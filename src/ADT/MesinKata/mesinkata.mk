all : run clean

driver: 
	gcc -o main driver-mesin-kata.c mesinkata.c ../MesinKarakter/mesinkarakter.c

run: driver
	./main.exe

clean:
	del main.exe