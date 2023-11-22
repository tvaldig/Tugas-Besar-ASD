all : run clean

driver: 
	gcc -o main driver-queue.c circular_queue.c

run: driver
	./main.exe

clean:
	del main.exe