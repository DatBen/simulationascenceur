#include "person.h"

#include <stdio.h>
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

PersonList *insert_back(Person *p, PersonList *list, PersonList *addr) {
    if (list == NULL) {
        PersonList *l = insert_front(p, NULL);
        return l;

    } else if (list->next == NULL) {
        PersonList *l = insert_front(p, NULL);
        list->next = l;

        return addr;

    } else {
        insert_back(p, list->next, addr);
        return addr;
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