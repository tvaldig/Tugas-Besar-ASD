all: run clean

driver: arraydin.c arraydin.h driver-arraydin.c
	gcc -o main arraydin.c driver-arraydin.c

run: driver
	./main

clean:
	del main.exe