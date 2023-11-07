#include "queue.h"
#include "../startload/startload.h"
void queueFunction(){
    printf("ini untuk handle queue function\n");
}

void ClearQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
    printf("Queue berhasil dikosongkan.");
}