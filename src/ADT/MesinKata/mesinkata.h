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

extern boolean UNDEF;

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

/*Mesin kata untuk mengakuisisi kata pada sebuah file konfigurasi
   I.S : currentChar sembarang
   F.S : currentWord menjadi kata yang telah diakuisi.
*/
void STARTFROMFILE(char *file);

/*Mesin kata untuk mengakuisisi selanjutnya kata pada sebuah file konfigurasi
   I.S : currentChar sembarang
   F.S : currentWord menjadi kata yang telah diakuisi.
*/
void ADVOnEnter(boolean OnBlank);

/*Melakukan salin kata pada file dengan BLANK
*/
void COPYFILE();

/*Melakukan salin kata pada file tanpa BLANK
 */
void COPYFILEOnBlank();

/* prosedur untuk melakukan akuisisi kata selanjutnya bila belum berhenti
*/
void ADVCONTINUE();

/* prosedur untuk melakukan copy pada semicolon
 */
void COPYFILESEMICOLON();

/* prosedur untuk melakukan akuisisi kata selanjutnya pada semicolon
 */
void ADVSEMICOLON();

/* prosedur untuk menutup input command
 */
void ENDCOMMAND();

/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
void IgnoreBlankFile();


/* PRIMITIF CONVERTER WORD ATAU STRING*/
void ConvertWordToString(Word *word, char *output); //Convert word menjadi string

boolean IsStringEqual(char str1[], char str2[]); //check string equal

void displayWord(Word w); //print word

int ConvertWordToInt(Word word); // Convert word menjadi integer

Word ConcatString(Word input1, Word input2); //Concat dua buah word

boolean IsCommandWithSemicolon(Word command); // fungsi untuk cek apakah command dengan semicolon

void handleSemicolon(Word command);// prosedur untuk menghapus semicolon

#endif