#include "elevator.h"
#include "person.h"
#include <stdlib.h>

PersonList *exitElevator(Elevator *e)
{
    int currentfloor = (e->currentFloor);
    PersonList *l = (e->persons);
    PersonList *h = (PersonList *)malloc(sizeof(PersonList));
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