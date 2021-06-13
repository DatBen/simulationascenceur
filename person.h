#ifndef PERSON_H
#define PERSON_H

typedef struct _Person {
    int src;
    int dest;
} Person;

typedef struct _PersonList {
    Person *person;
    struct _PersonList *next;
} PersonList;

Person *createPerson(int src, int dest);
PersonList *insert_front(Person *p, PersonList *list);
PersonList *insert_back(Person *p, PersonList *list, PersonList *addr);
int len(PersonList *l);

#endif
