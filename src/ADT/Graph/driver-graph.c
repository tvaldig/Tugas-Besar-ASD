#include "graph.h"

int main(){
    Graph g;

    printf("DRIVER UNTUK MEMBUAT GRAPH KOSONG : \n");
    CreateGraph(&g);
    printf("EMPTY : %d\n",isEmpty_Graph(g));

    printf("ADD VERTICES UNTUK SEMUA NODE\n");
    MakeMatrix(10, 10, &g.adjacencyMatrix);
    for(int i = 0; i < 10; i++){
        addVerticesToAll(&g, 10);
    }
    printGraph(g);

}