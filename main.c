#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

//connects files
#include "dir_ops.h"
#include "file_ops.h"

int main() {
  char command[50];
  char arg[100];

 while(1){
    printf(">> ");
    scanf("%s", command);

if(strcmp(command, "mkdir") == 0) {

 scanf("%s", arg);
 make_dir(arg);

}
else if(strcmp(command, "ls") == 0){
     list_dir();
}
else if(strcmp(command, "cd") == 0){
  scanf("%s", arg);
  change_dir(arg);
}
else if(strcmp(command, "pwd") == 0){
  print_dir();
}

else if(strcmp(command,"rm") == 0){
  scanf("%s",arg);
  remove_file(arg);
}
//cat command
else if(strcmp(command, "cat") == 0) {
 FILE *f;
 char ch;

 scanf("%s", arg);
 f = fopen(arg, "r");

if(f == NULL) {
 printf("File not found\n");
} else {
 while((ch = fgetc(f)) != EOF) {
 printf("%c", ch);
}
 fclose(f);
  }
}
//nano command
else if(strcmp(command,"nano") == 0) {
 FILE *f;
 char text[200];

 scanf("%s", arg);
 f = fopen(arg, "w");

 printf("Enter text: ");
 scanf(" %[^\n]", text);

 fprintf(f, "%s", text);
 fclose(f);
}

// CHMOD
else if(strcmp(command, "chmod") == 0) {
 int mode;

 scanf("%o %s", &mode, arg);

 if(chmod(arg, mode) == 0) {
    printf("Permissions changed\n");
}
 else {
      printf("Erorr changing  permissions\n");
  }
}
// shell scripting 
else if(strcmp(command, "run") == 0) {
 FILE *f;
 char line[100];

scanf("%s", arg);
f = fopen(arg, "r");

if(f == NULL) {
  printf("Script file not found\n");
}
 else {
  while(fget(line, sizeof(line), f)) {
  printf("Executing: %s", line);
   system(line);
}
  fclose(f);
 }
}
// EXIT
else if(strcmp(command, "exit") == 0){
 break;

}

// invalid command 
else {
  printf("Invalid command\n");
  }
}
  return 0;

}
