#include "person.h"

#include <stdlib.h>

#include "elevator.h"

Person *createPerson(int src, int dest) {
    Person *p = (Person *)malloc(sizeof(Person));
    p->dest = dest;
    p->src = src;
    return p;
}

PersonList *insert_front(Person *p, PersonList *list) {
    PersonList *l = (PersonList *)malloc(sizeof(PersonList));

    l->next = list;
    l->person = p;
    return l;
}

void insert_back(Person *p, PersonList *list) {
    if (list->next == NULL) {
        PersonList *l = insert_front(p, NULL);
        list->next = l;

    } else {
        insert_back(p, list->next);
    }
}

int len(PersonList *l) {
    int i = 0;
    while (l) {
        l = l->next;
        i++;
    }
    return (i);
}