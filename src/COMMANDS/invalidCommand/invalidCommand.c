#include "../../ADT/ADT.h"
#include "./invalidCommand.h"
#include <stdio.h>

boolean checkInSessionCommand(char *command){
    /* Cek apakah sesuai command dalam sesi */
    if (IsStringEqual(command, "LIST")) {
        return true;
    }
    else if (IsStringEqual(command, "PLAY")) {
        return true;
    } else if (IsStringEqual(command, "QUEUE")) {
        return true;
    } else if (IsStringEqual(command, "SONG")) {
        return true;
    } else if (IsStringEqual(command, "PLAYLIST")) {
        return true;
    } else if (IsStringEqual(command, "STATUS;")) {
        return true;
    } else if (IsStringEqual(command, "SAVE;")) {
        return true;
    } else if (IsStringEqual(command, "QUIT;")) {
        return true;
    } else {
        ENDCOMMAND();
        return false;
    }
}

boolean checkCommand(char *command, boolean inSession) {
    /* Mengembalikan false jika command tidak sesuai */
    if (!(inSession)) {
        // Jika belum dalam sesi
        if (IsStringEqual(command, "HELP;")) {
            if(currentChar == ' '){
                unknownCommand();
                ENDCOMMAND();
                return false;
            }else{
                return true;
            }
        
        }else if (IsStringEqual(command, "START;")){
            if (currentChar == ' '){
                ENDCOMMAND();
                unknownCommand();
                return false;
            }else{
                return true;
            }
        
        }else if (IsStringEqual(command, "LOAD")){
            if(currentChar == '\n'){
                printf("Masukkan nama file!\n");
                return false;
            }else{
                return true;
            }
        }
        
        else if (checkInSessionCommand(command)) {
            wrongCommand();
            ENDCOMMAND();
            return false;
        } else{
            ENDCOMMAND();
            unknownCommand();
            return false;
        }
    } else {
        // Jika sudah dalam sesi
        if (IsStringEqual(command, "START;") || IsStringEqual(command, "LOAD")) {
            ENDCOMMAND();
            wrongCommand();
            return false;
        }else if (IsStringEqual(command, "HELP;") || checkInSessionCommand(command)) {
            return true;
        } else {
            ENDCOMMAND();
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