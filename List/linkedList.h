typedef struct List
{
    int item;
    struct List *next;
} List;

typedef struct Queue
{
    List *head;
    List *tail;
} Queue;