all: run clean

driver: driver-load.c load.c ../../ADT/Linked-List/linked_list.c ../../ADT/Linked-List/linked_list.h ../../ADT/List/array.c ../../ADT/List/array.h ../../ADT/List/arraydin.c ../../ADT/List/array.h ../../ADT/MesinKarakter/mesinkarakter.c ../../ADT/MesinKarakter/mesinkarakter.h ../../ADT/MesinKata/mesinkata.c ../../ADT/MesinKata/mesinkata.h ../../ADT/Queue/circular_queue.c ../../ADT/Queue/circular_queue.h ../../ADT/Stack/stack.c ../../ADT/Stack/stack.h 
	gcc -o main driver-load.c load.c ../../ADT/Linked-List/linked_list.c ../../ADT/List/array.c ../../ADT/List/arraydin.c ../../ADT/MesinKarakter/mesinkarakter.c ../../ADT/MesinKata/mesinkata.c ../../ADT/Queue/circular_queue.c ../../ADT/Stack/stack.c

run: driver
	./main

clean:
	del main.exe
