#ifndef Graph_H
#define Graph_H

#include "../../boolean.h"
#include "../List/array.h"
#include <stdio.h>

#define CAP 100
#define barismax 100
#define kolommax 100
/**
 *  Definisi Graph :
 * 1. numEdge menyatakan jumlah elemen
 * 2. numVertex menyatakan jumlah koneksi.
 * 3. adjMatrix menyatakan adjecency matrix.
 */
typedef int ElType;
typedef struct BMatrix
{
    boolean Mem[barismax][kolommax];
    int NBrsEff;
    int NKolEff;
} BMatrix;

/* *** Selektor *** */


typedef struct Graph {
    int numEdges;
    int numVertices;
    BMatrix adjacencyMatrix;
} Graph;

#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define ELMT_BMatriks(M, i, j) (M).Mem[(i)][(j)]
#define NUMEDGE(g) (g).numEdges
#define NUMVERTICES(g) (g).numVertices
#define ADJMaxtrix(g) (g).adjacencyMatrix
#define CONNECTED(g, i, j) ELMT_BMatriks((g).adjacencyMatrix,i,j)

void MakeMatrix(int NB, int NK, BMatrix *M);

void CreateGraph(Graph *g) ;

boolean isEmpty_Graph(Graph g);

void printGraph(Graph g);

boolean isDirectlyConnected(Graph g, int i, int j);

void addEdge(Graph *g, int i, int j);

void addVerticesToAll(Graph *g, int i);

#endif