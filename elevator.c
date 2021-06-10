#include "elevator.h"

#include <stdio.h>
#include <stdlib.h>

Elevator *create_elevator(int capacity, int current_floor,
                          PersonList *persons) {
    Elevator *res = (Elevator *)malloc(sizeof(Elevator));
    res->capacity = capacity;
    res->currentFloor = current_floor;
    res->persons = persons;

    return res;
}

Building *create_building(int nbFloor, Elevator *elevator,
                          PersonList **waitingLists) {
    Building *res = (Building *)malloc(sizeof(Building));
    res->elevator = elevator;
    res->nbFloor = nbFloor;
    res->waitingLists = waitingLists;

    return res;
}

void stepElevator(Building *b) {
    int cursor = ((b->elevator->currentFloor) - (b->elevator->targetFloor));
    if (cursor == 0) {
        b->elevator->persons = exitElevator(b->elevator);

        PersonList *pl = *((b->waitingLists) + (b->elevator->currentFloor));

        *((b->waitingLists) + (b->elevator->currentFloor)) =
            enterElevator(b->elevator, pl);

    } else if (cursor < 0) {
        b->elevator->currentFloor++;
    } else if (cursor > 0) {
        b->elevator->currentFloor--;
    }
}