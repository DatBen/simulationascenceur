#include "person.h"

#include <stdlib.h>

#include "elevator.h"

Person *createPerson(int src, int dest)
{
    Person *p = (Person *)malloc(sizeof(Person));
    p->dest = dest;
    p->src = src;
    return p;
}

PersonList *insert_front(Person *p, PersonList *list)
{
    PersonList *l = (PersonList *)malloc(sizeof(PersonList));

    l->next = list;
    l->person = p;
    return l;
}

PersonList *insert_back(Person *p, PersonList *list)
{
    PersonList *l = NULL;
    l = insert_front(p, l);
    if (list = NULL)
    {
        return l;
    }
    else
    {
        PersonList *temp = list;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = l;
        return list;
    }
}

int len(PersonList *l)
{
    int i = 0;
    while (l)
    {
        l = l->next;
        i++;
    }
    return (i);
}