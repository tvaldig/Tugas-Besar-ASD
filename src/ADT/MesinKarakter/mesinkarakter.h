/* File: mesinkarakter.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "../../boolean.h"
#include "../MesinKata/mesinkata.h"

#define MARK ';'
#define ENTER '\n'
/* State Mesin */
extern char currentChar;
extern boolean EOP;
extern boolean finish;

void START();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

/* Mengirimkan currentChar */
char GetCC();


/* Mengirimkan true jika currentChar = MARK */
boolean IsEOP();

/* Mesin siap dioperasikan. Pita disiapkan untuk membaca FILE
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */
void STARTFILE(char *str);

/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */
void ADVFILE();

/*prosedur membuat file baru untuk save
   I.S sembarang
   F.S terbentuk file baru di directory save
*/
void NEWFILE(char* filename);

/*prosedur membuat pita mengakuisisi untuk menulis string
   I.S sembarang
   F.S tertulis string pada file
*/
void WRITESTRING(char* c);

/*prosedur membuat pita mengakuisisi untuk menulis integer
   I.S sembarang
   F.S tertulis integer pada file
*/
void WRITEINT(int i);

/*prosedur membuat pita mengakuisisi untuk menulis blank
   I.S sembarang
   F.S tertulis blank pada file
*/
void WRITEBLANK();

/*prosedur membuat pita mengakuisisi untuk menulis enter
   I.S sembarang
   F.S tertulis enter pada file
*/
void WRITEENTER();

/*prosedur membuat pita mengakuisisi untuk menulis semicolon
   I.S sembarang
   F.S tertulis semicolon pada file
*/
void WRITESEMICOLON();

/*prosedur menutup pita, file sudah selesai
   I.S sembarang
   F.S file ditutup dan disimpan di direktori
*/
void WRITEFINISH();

#endif