#include "heap.h"

int parentOf(int n)
{
    if (n == 1) return(-1);
    else return((int) n/2);
}

int youngChildOf(int n)
{
    return(2 * n);
}

void priorityQueueSwap(priorityQueue *q, int x, int y)
{
    int placeholder;

    placeholder = q->queue[x];
    q->queue[x] = q->queue[y];
    q->queue[y] = placeholder;
}

void bubbleUp(priorityQueue *q, int p)
{
    if (parentOf(p) == -1) return;

    if (q->queue[parentOf(p)] > q->queue[p])
    {
        priorityQueueSwap(q, p, parentOf(p));
        bubbleUp(q, parentOf(p));
    }
}

void bubbleDown(priorityQueue *q, int p)
{
    int child;
    int i, minIndex;

    child = youngChildOf(p);
    minIndex = p;

    for (i = 0; i <= 1; i++)
    {
        if ((child + i) <= q->length)
        {
            if (q->queue[minIndex] > q->queue[child + i])
            {
                minIndex = child + i;
            }
        }
    }

    if (minIndex != p)
    {
        priorityQueueSwap(q, p, minIndex);
        bubbleDown(q, minIndex);
    }
}

void priorityQueueInsert(priorityQueue *q, int item)
{
    if (q->length >= SIZE)
        printf("Warning: Priority queue overflow insert x = %d\n", item);
    else
    {
        q->length++;
        q->queue[q->length] = item;
        bubbleUp(q, q->length);
    }
}
// Time Complexity: O(logn) where n is the number of elements

void priorityQueueInit(priorityQueue *q, int items[], int length)
{
    int i;

    q->length = 0;

    for (i = 0; i < length; i++)
        priorityQueueInsert(q, items[i]);
}
// Time Complexity: O(nlogn) where n is the number of elements

int extractMin(priorityQueue *q)
{
    int min = -1;

    if (q->length <= 0) printf("Warning: empty priority queue.\n");
    else
    {
        min = q->queue[1];

        q->queue[1] = q->queue[q->length];
        q->length--;
        bubbleDown(q, 1);
    }

    return(min);
}

int heapSort(int items[], int length)
{
    int i;
    priorityQueue q;

    priorityQueueInit(&q, items, length);

    for (i = 0; i < length; i++)
        items[i] = extractMin(&q);
}