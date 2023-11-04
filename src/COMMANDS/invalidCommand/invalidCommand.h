#ifndef INVALID_H
#define INVALID_H

#include "../../ADT/ADT.h"

boolean checkOtherCommand();
/* Cek commands lain tapi tidak sesuai sesi */

boolean checkCommand(char *command, boolean inSession);
/* Cek command sesuai sesi belum/sudah load */

void unknownCommand();
/* Jika command tidak diketahui */

void wrongCommand();
/* Jika command tidak sesuai sesi belum/sudah load */

#endif