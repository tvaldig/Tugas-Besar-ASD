all: run clean

driver: main.c 
	gcc -o main driver-linked-list.c linked_list.c

run: driver
	./main.exe

clean:
	del main.exe