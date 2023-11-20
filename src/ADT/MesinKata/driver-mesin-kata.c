#include "mesinkata.h"
#include <stdio.h>

int main(){
    char command[100];
    printf("TEST UNTUK MELAKUKAN INPUT COMMAND DENGAN BLANK \n");
    STARTCOMMAND(false);
    ConvertWordToString(&currentCommand, command);
    printf("Hasil : %s\n", command);
    ENDCOMMAND();

    printf("\nTEST UNTUK MELAKUKAN INPUT COMMAND INTEGER TANPA BLANK\n");
    STARTCOMMAND(true);
    int n = ConvertWordToInt(currentCommand);
    printf("Hasil : %d\n", n);
    ENDCOMMAND();

    printf("\nTEST UNTUK CEK COMMAND DENGAN SEMICOLON\n");
    STARTCOMMAND(false);
    if(IsCommandWithSemicolon(currentCommand)){
        printf("COMMAND DIAKHIRI SEMICOLON\n");
        handleSemicolon(currentCommand);
    }
    printf("\nHASIL COMMAND DIHANDLE SEMICOLON : ");
    printf("%s\n", currentCommand.TabWord);
    ENDCOMMAND();

    printf("\nTEST UNTUK CHECK KONKAT WORD\n");
    printf("MASUKAN WORD 1 :");
    STARTCOMMAND(false);
    Word w1 = currentCommand;
    printf("\n");
    ENDCOMMAND();
    printf("MASUKAN WORD 2 :");
    STARTCOMMAND(false);
    Word w2 = currentCommand;
    ENDCOMMAND();
    printf("\n");
    displayWord(ConcatString(w1, w2));
}