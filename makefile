all: main

main.o: main.c
	gcc -c main.o

main : main.o
	gcc -o main main.o -lncurses