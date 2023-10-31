all : run clean

driver: driver-stack.c ../MesinKata/mesinkata.h ../MesinKata/mesinkata.c ../MesinKarakter/mesinkarakter.c ../MesinKarakter/mesinkarakter.h
	gcc -o main driver-stack.c stack.c

run: driver
	./main.exe

clean:
	del main.exe