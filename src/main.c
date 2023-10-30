#include <stdio.h>
#include "boolean.h"
#include "COMMANDS/console.h"
#include <string.h>
#include "./ADT/Linked-List/linked_list.h"
#include "./ADT/List/array.h"
#include "./ADT/List/arraydin.h"
#include "./ADT/MesinKarakter/mesinkarakter.h"
#include "./ADT/MesinKata/mesinkata.h"
#include "./ADT/Queue/circular_queue.h"
#include "./ADT/Stack/stack.h"

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