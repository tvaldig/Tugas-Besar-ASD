all: run clean

driver: 
	gcc -o main driver-linked-list.c linked_list.c

run: driver
	./main

clean:
	rm main