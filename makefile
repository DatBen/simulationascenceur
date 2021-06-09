all: main

person.o: person.c person.h
	gcc -c person.c
elevator.o: elevator.c elevator.h
	gcc -c elevator.c

main.o: main.o 
	gcc -c main.o 

main : main.o elevator.o person.o
	gcc -o main main.o elevator.o person.o -lncurses

make clean:
	rm -f *.o ./main