#include <stdio.h>

typedef struct List
{
    int item;
    struct List *next;
} List;