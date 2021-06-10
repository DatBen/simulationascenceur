#include "person.h"

#include <stdlib.h>

#include "elevator.h"

Person *createPerson(int src, int dest) {
    Person *p = (Person *)malloc(sizeof(Person));
    p->dest = dest;
    p->src = src;
    return p;
}

PersonList *insert(Person *p, PersonList *list) {
    PersonList *l = (PersonList *)malloc(sizeof(PersonList));

    l->next = list;
    l->person = p;
    return l;
}

int len(PersonList *l) {
    int i = 0;
    while (l) {
        l = l->next;
        i++;
    }
    return (i);
}