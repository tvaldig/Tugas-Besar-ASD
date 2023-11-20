all : run clean

driver: mesinkarakter.h driver-mesin-karakter.c mesinkarakter.c
	gcc -o main driver-mesin-karakter.c mesinkarakter.c

run: driver
	./main.exe

clean:
	del main.exe