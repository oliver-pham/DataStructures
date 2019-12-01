#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void initializeGraph(Graph *g, int directed)
{
    int i;

    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;

    for (i = 0; i < MAXV; i++)
    {
        g->degree[i] = 0;
        g->edges[i] = NULL;
    }
    
}

void readGraph(Graph *g, int directed)
{
    int i;
    int e;                          /* number of edges */
    int x, y;                       /* vertices in edge (x, y) */
    
    initializeGraph(g, directed);

    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &(g->nvertices), &e);

    for (i = 0; i < e; i++)
    {
        printf("Enter two adjacent vertices: ");
        scanf("%d %d", &x, &y);
        insertEdge(g, x, y, directed);
    }
}

void insertEdge(Graph *g, int x, int y, int directed)
{
    Edgenode *p;

    p = malloc(sizeof(Edgenode));
    p->weight = NULL;
    p->y = y;
    p->next = g->edges[x];

    g->edges[x] = p;                /* insert at head of list */
    g->degree[x]++;

    if (directed == 0)
        insertEdge(g, y, x, 1);
    else
        g->nedges++;
}

void printGraph(Graph *g)
{
    int i;
    Edgenode *p;

    for (i = 0; i < g->nvertices; i++)
    {
        printf("%d: ", i + 1);
        p = g->edges[i];
        while (p != NULL)
        {
            printf(" %d", p->y);
            p = p->next;
        }
        printf("\n");
    }
}