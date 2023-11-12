#include "save.h"

void SAVE(){
    STARTCOMMAND(false);

    printf("%s\n", currentCommand.TabWord);

    if(!IsCommandWithSemicolon(currentCommand)){
        unknownCommand();
        return;
    }

    handleSemicolon(currentCommand);

    NEWFILE(currentCommand.TabWord);

}