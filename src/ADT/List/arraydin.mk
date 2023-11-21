all: run clean

driver: 
	gcc -o main arraydin.c driver-arraydin.c

run: driver
	./main

clean:
	del main.exe