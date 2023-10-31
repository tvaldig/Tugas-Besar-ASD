#include <stdio.h>
#include "boolean.h"
#include "COMMANDS/welcomeMenu/welcomemenu.h"

int main(){
   char command[100];
   welcomeMenu();
   STARTCOMMAND();
   ConvertWordToString(&currentCommand, command);
   if(IsStringEqual(command,"START")){
      printf("COMMAND START DIJALANKAN\n");
   }
}