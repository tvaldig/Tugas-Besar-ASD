#include "queue_linked.h"
#include <stdio.h>

int main(){
    /* Tes New Node */
    int input;
    Address p;
    scanf("%d",&input);
    p = newNode(input);
    printf("INFO dari Node yang baru: %d\n",INFO(p));
    printf("NEXT dari Node yang baru: %d\n",NEXT(p));

}