#include <stdio.h>
#include "start.h"

void startFunction(TabInt *T){
    int n, m, l;
    Penyanyi p[100];
    Album a;
    STARTFROMFILE("../save/new.txt");
    n = ConvertWordToInt(currentWord);
    for(int i = 0; i < n; i++){
        ADVOnEnter(true);
        m = ConvertWordToInt(currentWord);
        ADVFILE();
        COPYFILE();
        //Input penyanyi ke List disini
        for(int j = 0; j < m; j++){
            ADVOnEnter(true);
            l = ConvertWordToInt(currentWord);
            ADVFILE();
            COPYFILE();
            //Input Album ke map disini
            for(int k = 0; k < l; k++){
                ADVOnEnter(false);
                // Input Lagu ke set disini
            }
        }
    }
}