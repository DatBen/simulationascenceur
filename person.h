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
void insert_back(Person *p, PersonList *list);
int len(PersonList *l);

#endif
