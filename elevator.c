#include "elevator.h"
#include "person.h"
#include <stdlib.h>

PersonList *exitElevator(Elevator *e)
{
    int currentfloor = (e->currentFloor);
    PersonList *l = (e->persons);
    while (l)
    {
        if (((l->person)->dest) = currentfloor)
        {
            l = l->next;
        }
    }
    return l;
}

PersonList *enterElevator(Elevator *e, PersonList *waitingList)
{
    PersonList *h = (PersonList *)malloc(sizeof(PersonList));
    int currentfloor = (e->currentFloor);
    while (waitingList && (len(e->persons) < (e->capacity)))
    {
        if (((waitingList->person)->dest) = currentfloor)
        {
            e->persons = insert(h->person, e->persons);
            waitingList = waitingList->next;
        }
        else
        {
            h = insert(waitingList->person, h);
        }
    }
    return h;
}