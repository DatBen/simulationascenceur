


all: main

elevator.o: elevator.c elevator.h
	gcc -c elevator.c

person.o: person.c person.h


main.o: main.c
	gcc -c main.c

main : main.o person.o elevator.o
	gcc -o main main.o person.o elevator.o -lncurses