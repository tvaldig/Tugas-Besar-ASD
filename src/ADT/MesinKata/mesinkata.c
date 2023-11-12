
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

void STARTCOMMAND(boolean OnBlank){
    START();
    IgnoreBlanks();
    if(currentChar == ENTER){
        EndCommand = true;
    }else{
        EndCommand = false;
        OnBlank ? ADVCOMMANDONBLANK() : ADVCOMMAND();
    }
}

void ADVCOMMAND()
{
    Word empty = {"", 0};
    currentCommand = empty;
    
        if (currentChar == ENTER && !EndCommand)
        {
            EndCommand = true;
        }
        else
        {
            CopyCommandNotBlank();
        }
    
    
}

void ADVCOMMANDONBLANK()
{
        Word empty = {"", 0};
        currentCommand = empty;

        if (currentChar == BLANK && !EndCommand)
        {
            EndCommand = true;
        }
        else
        {
            CopyCommand();
        }
}

void CopyCommand()
{
    int i = 0;
    while (currentChar != BLANK && currentChar != ENTER)
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

void CopyCommandNotBlank()
{
    int i = 0;
    while (currentChar != ENTER)
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
    while ((str1[i] != '\0' || str2[i] != '\0') && equal)
    {
        if (str1[i] != str2[i])
        {
            equal = false;
        }
        i++;
    }
    return equal;
}

void STARTFROMFILE(char *file){
    finish = false;
    STARTFILE(file);
    COPYFILE();
} 

void ADVOnEnter(boolean OnBlank){
    Word Empty = {"", 0};
    currentWord = Empty;
    if(currentChar == ENTER && !OnBlank){
        ADVFILE();
        COPYFILE();
    } else {
        ADVFILE();
        COPYFILEOnBlank();
    }
}

void COPYFILEOnBlank(){
    int i = 0;
    while (currentChar != BLANK && !finish)
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
void ADVCONTINUE(){
    ADVFILE();
    COPYFILE();
}
void COPYFILE(){
    int i = 0;
    while (currentChar != ENTER && !finish)
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

void ADVSEMICOLON(){
    Word Empty = {"", 0};
    currentWord = Empty;
    ADVFILE();
    COPYFILESEMICOLON();
}

void COPYFILESEMICOLON(){
    int i = 0;
    while (currentChar != ENTER && !finish && currentChar != ';')
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

int ConvertWordToInt(Word word)
{
    int num = 0;
    for (int i = 0; i < word.Length; i++)
    {
        num = num * 10 + (word.TabWord[i] - '0');
    }
    return num;
}

Word ConcatString(Word input1, Word input2){
    Word hasil = {"",0};

    for(int i = 0; i < input1.Length; i++){
        hasil.TabWord[i] = input1.TabWord[i];
        hasil.Length++;
    }

    for(int j = input1.Length; j < (input1.Length+input2.Length); j++){
        hasil.TabWord[j] = input2.TabWord[j - input1.Length];
        hasil.Length++;
    }

    return hasil;

}

boolean IsCommandWithSemicolon(Word command){
    return (currentCommand.TabWord[currentCommand.Length - 1] == ';');
}

void handleSemicolon(Word command){
    currentCommand.TabWord[currentCommand.Length - 1] = '\0';
    currentCommand.Length--;
}

void ENDCOMMAND(){
    if(currentChar != ENTER){
        START();
        while(currentChar != ENTER){
            ADV();
        }
    }
    
}

