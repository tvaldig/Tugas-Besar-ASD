/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../../boolean.h"
#include "../MesinKarakter/mesinkarakter.h"
#define NMax 100
#define BLANK ' '

typedef struct
{
    char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
    int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;
extern boolean EndCommand;
extern Word currentCommand;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */


void STARTCOMMAND(boolean OnBlank);

/* Mesin kata untuk mengakuisisi kata selanjutnya dengan MARK sebagai new line
   I.S : currentChar sembarang
   F.S : currentWord menjadi kata yang telah diakuisi.
*/
void ADVCOMMAND();

/* Mesin kata untuk mengakuisisi kata selanjutnya dengan MARK sebagai blank
   I.S : currentChar sembarang
   F.S : currentWord menjadi kata yang telah diakuisi.
*/
void ADVCOMMANDONBLANK();

 /* Melakukan salin pada mesin kata dengan BLANK untuk dijadikan CurrentWord
 */
void CopyCommand();

/* Melakukan salin pada mesin kata tanpa BLANK untuk dijadikan CurrentWord
 */
void CopyCommandNotBlank();

/*
*/
void STARTFROMFILE(char *file);

void ADVOnEnter(boolean OnBlank);

void COPYFILE();

void COPYFILEOnBlank();

void ADVCONTINUE();

void COPYFILESEMICOLON();

void ADVSEMICOLON();

void ENDCOMMAND();

void IgnoreBlankFile();


    /* PRIMITIF CONVERTER WORD ATAU STRING*/
void ConvertWordToString(Word *word, char *output);

boolean IsStringEqual(char str1[], char str2[]);

void displayWord(Word w);

int ConvertWordToInt(Word word);

Word ConcatString(Word input1, Word input2);

boolean IsCommandWithSemicolon(Word command);

void handleSemicolon(Word command);

#endif