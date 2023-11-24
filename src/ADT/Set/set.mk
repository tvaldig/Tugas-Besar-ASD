all: run clean

driver: 
	gcc -o main driver-set.c set.c ../MesinKata/mesinkata.c ../MesinKarakter/mesinkarakter.c

run: driver
	./main

clean:
	rm main