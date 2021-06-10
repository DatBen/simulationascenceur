#include "elevator.h"
#include "person.h"
#include <stdlib.h>

PersonList *exitElevator(Elevator *e)
{
    int currentfloor = (e->currentFloor);
    PersonList *l = (e->persons);
    PersonList *h = NULL;
    int n = len(l);
    int i = 0;
    while (i < n)
    {
        if (((l->person)->dest) != currentfloor)
        {
            h = insert(l->person, h);
        }
        l = l->next;
        i++;
    }
    return h;
}

PersonList *enterElevator(Elevator *e, PersonList *waitingList)
{
    PersonList *h = NULL;
    int currentfloor = (e->currentFloor);
    while (waitingList && (len(e->persons) < (e->capacity)))
    {
        e->persons = insert(h->person, e->persons);
        waitingList = waitingList->next;
    }
    return waitingList;
}