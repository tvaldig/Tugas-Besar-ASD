#include "linked_list.h"
#include <stdio.h>

int main(){
    /* Test Alokasi */
    addressnode p, new;
    int input1, input2, input3;
    printf("Masukkan INFO untuk node baru: ");
    scanf("%d", &input1);
    scanf("%d", &input2);
    scanf("%d", &input3);

    p = alokasi(input1,input2,input3);
    printf("INFO dari node baru: %d %d %d\n", PENYANYI(p), ALBUM(p), LAGU(p));
    printf("NEXT dari node baru: %d\n\n", Next(p));

}