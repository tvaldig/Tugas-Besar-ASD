#include "load.h"
#include <stdio.h>
#include <stdlib.h>

Stack riwayat;
Queue antrian;
ArrayDin playlists;

void ConcatString(char *input1, char *input2){
  int i = 0;
  while (input1[i]!='\0'){
    i++;
  }
  int j = 0;
  while (input2[j]!='\0'){
    input1[i]=input2[j];
    i++; j++;
  }
}

void LOADFILE(char* fname){
    char direktori[] = "../../../save/";
    ConcatString(direktori, fname);
    printf("%s", direktori);
    
}