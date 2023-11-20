#ifndef INVALID_H
#define INVALID_H

#include "../../ADT/ADT.h"

/* Cek commands lain tapi tidak sesuai sesi */
boolean checkOtherCommand();

/* Cek command sesuai sesi belum/sudah load */
boolean checkCommand(char *command, boolean inSession);

/* Jika command tidak diketahui */
void unknownCommand();

/* Jika command tidak sesuai sesi belum/sudah load */
void wrongCommand();

/* Program utama invalidCommand untuk melakukan*/
#endif