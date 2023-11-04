#include "../../ADT/ADT.h"
#include "./invalidCommand.h"

boolean checkInSessionCommand(char *command){
    /* Cek apakah sesuai command dalam sesi */
    if (IsStringEqual(command, "LIST")) {
        return true;
    } else if (IsStringEqual(command, "PLAY")) {
        return true;
    } else if (IsStringEqual(command, "QUEUE")) {
        return true;
    } else if (IsStringEqual(command, "SONG")) {
        return true;
    } else if (IsStringEqual(command, "PLAYLIST")) {
        return true;
    } else if (IsStringEqual(command, "STATUS")) {
        return true;
    } else if (IsStringEqual(command, "SAVE")) {
        return true;
    } else if (IsStringEqual(command, "QUIT")) {
        return true;
    } else {
        return false;
    }
}

boolean checkCommand(char *command, boolean inSession) {
    /* Mengembalikan false jika command tidak sesuai */
    if (!(inSession)) {
        // Jika belum dalam sesi
        if (IsStringEqual(command, "HELP") || IsStringEqual(command, "START") || IsStringEqual(command, "LOAD")) {
            return true;
        } else if (checkInSessionCommand(command)) {
            wrongCommand();
            return false;
        } else {
            unknownCommand();
            return false;
        }
    } else {
        // Jika sudah dalam sesi
        if (IsStringEqual(command, "START") || IsStringEqual(command, "LOAD")) {
            wrongCommand();
            return false;
        } else if (IsStringEqual(command, "HELP") || checkInSessionCommand(command)) {
            return true;
        } else {
            unknownCommand();
            return false;
        }
    }
}
/* Cek command sesuai sesi */

void unknownCommand() {
    printf("Command tidak diketahui!\n");
}
/* Jika command tidak diketahui */

void wrongCommand(){
    printf("Command tidak bisa dieksekusi!\n");
}
/* Jika command tidak sesuai sudah/belum masuk sesi */