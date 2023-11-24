all: run clean

driver: 
	gcc -o main map.c driver-map.c ../MesinKarakter/mesinkarakter.c ../MesinKata/mesinkata.c

run: driver
	./main

clean:
	rm main