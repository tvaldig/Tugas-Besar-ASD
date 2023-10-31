#include <stdio.h>
#include "start.h"

void startFunction(TabInt *T){
    STARTFROMFILE("../save/new.txt");
    displayWord(currentWord);
}