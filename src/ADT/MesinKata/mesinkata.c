
#include <stdio.h>
#include "../../boolean.h"
#include "mesinkata.h"
Word currentWord;
Word currentCommand;
boolean EndWord;
boolean EndCommand;

void IgnoreBlanks()
{
    while (currentChar == BLANK)
    {
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD()
{
    START();
    IgnoreBlanks();
    if (EOP)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD()
{
    IgnoreBlanks();
    if (EOP)
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        IgnoreBlanks();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord()
{
    int i = 0;
    while (currentChar != MARK && currentChar != BLANK)
    {
        if (i < NMax)
        {
            currentWord.TabWord[i] = currentChar;
            i++;
        }
        ADV();
    }
    currentWord.Length = i;
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void STARTCOMMAND(){
    START();
    IgnoreBlanks();
    if(currentChar == ENTER){
        EndCommand = true;
    } else {
        EndCommand = false;
        ADVCOMMAND();
    }
}

void ADVCOMMAND()
{
    if (currentChar == ENTER && !EndCommand)
    {
        EndCommand= true;
    }
    else
    {
        CopyCommand();
    }
}

void CopyCommand()
{
    int i = 0;
    while (currentChar != MARK && currentChar != ENTER)
    {
        if (i < NMax)
        {
            currentCommand.TabWord[i] = currentChar;
            i++;
        }
        ADV();
    }
    currentCommand.Length = i;


}




void ConvertWordToString(Word *word, char *output)
{
    int i = 0;
    while(i < word->Length){
        output[i] = word->TabWord[i];
        i++;
        if(i == word->Length){
            output[i] = '\0';
        }
    }
   
}

boolean IsStringEqual(char str1[], char str2[])
{
    boolean equal = true;
    int i = 0;
    while (str1[i] != '\0' && str2 != '\0')
    {
        if (str1[i] != str2[i])
        {
            equal = false;
        }
        i++;
    }
    if (equal)
        return true;
    else
        return false;
}

void STARTFROMFILE(char *file){
    finish = false;
    STARTFILE(file);
    COPYFILE();
} 

void ADVOnEnter(){

}

void COPYFILE(){
    int i = 0;
    while (!finish)
    {
        if (i < NMax)
        {
            currentWord.TabWord[i] = currentChar;
            i++;
            ADVFILE();
        }
    }
        currentWord.Length = i;
    
}

void IgnoreBlankFile(){
    while(currentChar == BLANK){
        ADVFILE();   
    }
}

void displayWord(Word w)
{
    int i;
    for (i = 0; i < w.Length; i++)
    {
        printf("%c", w.TabWord[i]);
    }
    printf("\n");
}