all : run clean

driver: circular_queue.h driver-test-queue.c circular_queue.c
	gcc -o main driver-test-queue.c circular_queue.c

run: driver
	./main.exe

clean:
	del main.exe