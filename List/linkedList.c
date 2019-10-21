#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

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

void insertList(List **head, int item)
{
    List *p; // Temporary pointer

    p = malloc(sizeof(List));
    p->item = item;
    p->next = *head;
    *head = p;
    printf("Inserted a list successfully.\n");
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