all : run clean

driver: circular_queue.h driver-queue.c circular_queue.c ../MesinKata/mesinkata.h ../MesinKata/mesinkata.c ../MesinKarakter/mesinkarakter.c ../MesinKarakter/mesinkarakter.h
	gcc -o main driver-queue.c circular_queue.c ../MesinKata/mesinkata.c ../MesinKarakter/mesinkarakter.c

run: driver
	./main.exe

clean:
	del main.exe