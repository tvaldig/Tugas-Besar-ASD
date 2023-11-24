#include "../../boolean.h"
#include "graph.h"


void MakeMatrix(int NB, int NK, BMatrix *M)
{
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
    for (int i = 0; i < NB; i++)
    {
        for (int j = 0; j < NK; j++)
        {
            ELMT_BMatriks(*M, i, j) = false;
        }
    }
}

void CreateGraph(Graph *g)
/* I.S. sembarang             */
/* F.S. Terbentuk Graph kosong */
{
    NUMEDGE(*g) = 0;
    NUMVERTICES(*g) = 0;
    int i, j;
    for (i = 0; i < CAP; i++)
    {
        for (j = 0; j < CAP; j++)
        {
            CONNECTED(*g, i, j) = false;
        }
    }
}

boolean isEmpty_Graph(Graph g)
{
    return NUMVERTICES(g) = 0;
}

void printGraph(Graph g)
{
    int i, j;
    for (i = 0; i < NUMVERTICES(g); i++)
    {
        printf("[");
        for (j = 0; j < NUMVERTICES(g); j++)
        {
            printf("%d", CONNECTED(g, i, j));
            if (j == NUMVERTICES(g) - 1)
                printf("]");
            else
                printf(" ");
        }
        printf("\n");
    }
}

boolean isDirectlyConnected(Graph g, int i, int j)
{
    return CONNECTED(g, i, j) == true;
}

void addEdge(Graph *g, int i, int j)
{
    NUMEDGE(*g) += 1;
    CONNECTED(*g, i, j) = true;
    CONNECTED(*g, j, i) = true;
}

void addVerticesToAll(Graph *g, int k)
{
    NUMVERTICES(*g) += 1;
    for(int i = 0; i < k; i++){
        addEdge(g, NUMVERTICES(*g) - 1, i);
    }
}
