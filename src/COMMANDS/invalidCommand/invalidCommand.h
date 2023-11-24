#ifndef INVALID_H
#define INVALID_H

#include "../../ADT/ADT.h"

/* Cek commands lain tapi tidak sesuai sesi */
boolean checkOtherCommand();

boolean checkCommand(char *command, boolean inSession, boolean isLog);
/* Cek command sesuai sesi belum/sudah load */


/* Jika command tidak diketahui */
void unknownCommand();

/* Jika command tidak sesuai sesi belum/sudah load */
void wrongCommand();


/* Program utama invalidCommand untuk melakukan*/
#endif