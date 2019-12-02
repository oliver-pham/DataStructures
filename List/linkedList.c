#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

List *initializeList(int item)
{
    List *l;

    l = malloc(sizeof(List));
    l->item = item;
    l->next = NULL;
    return l;
}

Queue *initializeQueue(List **head)
{
    Queue *q;
    List *p = &head;

    if (p = NULL) return p;
    while (p->next != NULL)
    {
        p = p->next;
    }

    q->head = &head;
    q->tail = p;
    return q;
}

List *searchList(List *l, int item)
{
    if (l == NULL) return NULL;

    if (l->item == item)
    {
        printf("Found the item!\n");
        return(l);
    }
    else
    {
        return searchList(l->next, item);
    }
}

void push(List **head, int item)
{
    List *l;

    l = malloc(sizeof(List));
    l->item = item;
    l->next = *head;
    *head = l;
    printf("Inserted a list successfully.\n");
}

List *pop(List **head)
{
    List *p;

    p = &head;
    if (p != NULL)
    {
        *head = p->next;
        printf("Popped a list successfully.\n");
        return p;
    }
    else
    {
        printf("Empty List!\n");
        return p;
    }
}

void enqueue(Queue *q, int item)
{
    List *l;

    l = malloc(sizeof(List));
    l->item = item;
    l->next = NULL;
    q->tail->next = l;
    printf("Enqueued a list successfully.\n");
}

List *dequeue(Queue *q)
{
    List *p;

    p = q->head;
    q->head = q->head->next;
    printf("Dequeued a list successfully.\n");
    return p;
}

void deleteList(List **head, int item)
{
    List *p;        // item pointer
    List *pred;     // predecessor pointer
    List *searchList(), *predecessorList();

    p = searchList(*head, item);
    if (p != NULL)
    {
        pred = predecessorList(*head, item);
        if (pred == NULL)
        {
            *head = p->next;
        }
        else
        {
            pred->next = p->next;
        }
        free(p);
        printf("Item deleted successfully.\n");
    }
    else
    {
        printf("Error: item not found.\n");
    }
}

void printList(List *l)
{
    if (l != NULL)
    {
        printf("Item: %d\n", l->item);
        return(printList(l->next));
    }
    else
    {
        return;
    }
}

List *predecessorList(List *l, int item)
{
    if ((l == NULL) || (l->next == NULL))
    {
        printf("Error: predecessor sought on null list.\n");
        return(NULL);
    }

    if ((l->next)->item == item)
    {
        return(l);
    }
    else
    {
        return(predecessorList(l->next, item));
    }
}