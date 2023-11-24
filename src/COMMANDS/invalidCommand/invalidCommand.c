#include "../../ADT/ADT.h"
#include "./invalidCommand.h"
#include <stdio.h>


boolean checkInSessionCommand(char *command, boolean isLog){
    /* Cek apakah sesuai command dalam sesi */
    if (IsStringEqual(command, "LIST") && isLog) {
        return true;
    }
    else if (IsStringEqual(command, "PLAY") &&isLog) {
        return true;
    }
    else if (IsStringEqual(command, "QUEUE") && isLog)
    {
        return true;
    }
    else if (IsStringEqual(command, "SONG") && isLog)
    {
        return true;
    }
    else if (IsStringEqual(command, "PLAYLIST") && isLog)
    {
        return true;
    }
    else if (IsStringEqual(command, "STATUS;") && isLog)
    {
        return true;
    }
    else if (IsStringEqual(command, "SAVE"))
    {
        if(isLog){
            return true;
        } else {
            return false;
        }
       
    }
    else if (IsStringEqual(command, "QUIT;"))
    {
        return true;
    }
    else if (IsStringEqual(command, "ENHANCE;") && isLog)
    {
        return true;
    } else if(IsStringEqual(command, "RADIO;") && isLog){
        return true;
    }
    else if (IsStringEqual(command, "LOGIN;"))
    {
        return true;
    }
    else if (IsStringEqual(command, "LOGOUT;"))
    {
        return true;
    }
    else
    {
        ENDCOMMAND();
        return false;
    }
}


boolean checkCommand(char *command, boolean inSession, boolean isLog) {
    /* Mengembalikan false jika command tidak sesuai */
    if (!(inSession)) {
        // Jika belum dalam sesi
        if (IsStringEqual(command, "HELP;")) {
            if(currentChar == ' '){
                unknownCommand();
                return false;
            }else{
                return true;
            }
        
        }else if (IsStringEqual(command, "START;")){
            if (currentChar == ' '){
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
        
        else if (checkInSessionCommand(command, isLog)) {
            wrongCommand();
            return false;
        } else{
            unknownCommand();
            return false;
        }
    } else {
        // Jika sudah dalam sesi

                if (IsStringEqual(command, "START;") || IsStringEqual(command, "LOAD"))
                {
                    wrongCommand();
                    return false;
                }
                else if (IsStringEqual(command, "HELP;") || checkInSessionCommand(command, isLog))
                {
                    return true;
                }
                else
                {
                    if(!isLog){
                        printf("Silakan login terlebih dahulu.\n\n");
                        return false;
                    } else{
                        unknownCommand();
                        return false;
                    }
                   
                }
            }

        }
        


/* Cek command sesuai sesi */

void unknownCommand() {
    printf("Command tidak diketahui!\n\n");
    ENDCOMMAND();
}
/* Jika command tidak diketahui */

void wrongCommand(){
    printf("Command tidak bisa dieksekusi!\n\n");
    ENDCOMMAND();
}
/* Jika command tidak sesuai sudah/belum masuk sesi */