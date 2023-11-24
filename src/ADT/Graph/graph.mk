all: run clean

driver: 
	gcc -o main graph.c driver-graph.c

run: driver
	./main

clean:
	rm main