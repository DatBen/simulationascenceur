#include "elevator.h"

#include <stdio.h>
#include <stdlib.h>

#include "person.h"

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

PersonList *exitElevator(Elevator *e) {
    int currentfloor = (e->currentFloor);
    PersonList *l = (e->persons);
    PersonList *h = (PersonList *)malloc(sizeof(PersonList));
    int n = len(l);
    int i = 0;
    while (i < n) {
        if (((l->person)->dest) != currentfloor) {
            h = insert(l->person, h);
        }
        l = l->next;
        i++;
    }
    return h;
}

PersonList *enterElevator(Elevator *e, PersonList *waitingList) {
    PersonList *h = (PersonList *)malloc(sizeof(PersonList));
    int currentfloor = (e->currentFloor);
    while (waitingList && (len(e->persons) < (e->capacity))) {
        e->persons = insert(h->person, e->persons);
        waitingList = waitingList->next;
    }
    return waitingList;
}