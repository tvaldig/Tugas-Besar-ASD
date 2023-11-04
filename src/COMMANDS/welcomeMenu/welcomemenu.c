#include <stdio.h>
#include "welcomemenu.h"

void delay(){
    int delay;
    for (int i = 0; i < 100099999; i++)
    {
        delay = i;
    }
}

void welcomeMenu()
{
    STARTFROMFILE("../save/wayangwave.txt");

    while (!finish)
    {
        delay();
        printf("%s\n", currentWord.TabWord);
        ADVOnEnter(false);
    }
    printf("Masukan Command :\n");
}
