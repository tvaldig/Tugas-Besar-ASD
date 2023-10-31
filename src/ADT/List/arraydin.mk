all: run clean

driver: arraydin.h arraydin.c driver-arraydin.c
	gcc -o main arraydin.c driver-arraydin.c

run: driver
	./main.exe

clean:
	del main.exe
