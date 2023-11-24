#ifndef _RADIO_H
#define _RADIO_H

#define RMAX 1000
#include "../../ADT/ADT.h"
#include "../commands.h"

typedef struct {
    int RNeff;
    int El[RMAX];
} Radio;

void radioFunction();

#endif