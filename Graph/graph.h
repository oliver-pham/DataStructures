#define MAXV 10               /* maximum number of vertices */

typedef struct Edgenode
{
    int y;                      /* adjacency info */
    int weight;                 /* edge weight, if any */
    struct Edgenode *next;      /* next edge in list */
} Edgenode;

typedef struct Graph
{
    Edgenode *edges[MAXV + 1];  /* adjacency info */
    int degree[MAXV + 1];       /* outdegree of each vertex */
    int nvertices;              /* number of vertices in graph */
    int nedges;                 /* number of edges in graph */
    int directed;              /* is the graph directed? */
} Graph;