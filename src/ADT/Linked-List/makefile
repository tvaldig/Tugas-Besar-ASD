all: run clean

driver: driver-linked-list.c linked_list.c linked_list.h
	gcc -o main driver-linked-list.c linked_list.c

run: driver
	./main.exe

clean:
	del main.exe