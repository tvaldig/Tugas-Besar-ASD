#include <stdio.h>
#include "boolean.h"
#include "COMMANDS/console.h"
#include <string.h>

int main(){
   char command[100];
   welcomeMenu();
   STARTCOMMAND();
   ConvertWordToString(&currentCommand, command);
   if(strcmp(command,"START") == 0){
      printf("COMMAND START DIJALANKAN\n");
   }
   if (strcmp(command, "LOAD") == 0)
   {
      printf("COMMAND LOAD DIJALANKAN\n");
   }
   if (strcmp(command, "HELP") == 0)
   {
      printf("COMMAND HELP DIJALANKAN\n");
   }
}