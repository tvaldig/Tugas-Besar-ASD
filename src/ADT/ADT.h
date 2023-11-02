#ifndef _ADT_H
#define _ADT_H

#include "./Linked-List/linked_list.h"
#include "./List/array.h"
#include "./List/arraydin.h"
#include "./MesinKarakter/mesinkarakter.h"
#include "./MesinKata/mesinkata.h"
#include "./Queue/circular_queue.h"
#include "./Stack/stack.h"


typedef struct{
    Word nama;
    TabInt Lagu;
} Album;

typedef Album MAP_ALBUM[100];

typedef struct {
    Word nama;
    MAP_ALBUM album;
} Penyanyi;



#endif