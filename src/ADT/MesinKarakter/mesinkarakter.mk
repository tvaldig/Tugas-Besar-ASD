all : run clean

driver: 
	gcc -o main driver-mesin-karakter.c mesinkarakter.c

run: driver
	./main.exe

clean:
	del main.exe