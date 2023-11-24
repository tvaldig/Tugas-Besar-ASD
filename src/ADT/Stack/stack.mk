all : run clean

driver: 
	gcc -o main driver-stack.c stack.c

run: driver
	./main

clean:
	rm main