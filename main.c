#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

int main(int argc, char* argv[]){
 char* outFile[3];
 char fn1[240];
 char fn2[240];
 char fn3[240];
 char ext1[] = ".inorder";
 char ext2[] = ".preorder";
 char ext3[] = ".postorder";
 char data[240];
 FILE *f;
 Length* tree = NULL;

 if (argc > 2){
  perror("To many args. exiting main.");
  exit(1);
 }

 //getting rid of white spaces and output files
 if( argc == 2){
  int i, j, len;
  char name[240];
  char ext[] = ".sp19";
  char* base = argv[1];
  len = strlen(base);
  for (i=0, j=0;i<len; i++, j++){
   if(base[i] != ' '){
    name[j] += base[i];
   }
   else{
    j--;
   }
  }
  strcpy(fn1, name);
  strcpy(fn2, name);
  strcpy(fn3, name);
  strcat(fn1, ext1);
  strcat(fn2, ext2);
  strcat(fn3, ext3);
  outFile[0] = (char*) malloc(240);
  outFile[1] = (char*) malloc(240);
  outFile[2] = (char*) malloc(240);
  strcpy(outFile[0], fn1);
  strcpy(outFile[1], fn2);
  strcpy(outFile[2], fn3);
  strcat(name, ext);
  f = fopen(name, "r");
  if(!f){
   error();
  }
 }
 else if (argc == 1){
  strcpy(fn1, "out");
  strcpy(fn2, "out");
  strcpy(fn3, "out");
  strcat(fn1, ext1);
  strcat(fn2, ext2);
  strcat(fn3, ext3);
  outFile[0] = (char*) malloc(240);
  outFile[1] = (char*) malloc(240);
  outFile[2] = (char*) malloc(240);
  strcpy(outFile[0], fn1);
  strcpy(outFile[1], fn2);
  strcpy(outFile[2], fn3);
  f = stdin;
 }

 // inserting data into tree
 int num;
 while(fscanf(f,"%s", data) == 1){
  num = strlen(data);
  insert(&tree, data, num);
 }

fclose(f);

//Traveling the tree in these orders.
FILE *file = fopen(outFile[0],"w");
inOrder(file, &(*tree), 0);
fclose(file);

file = fopen(outFile[1],"w");
preOrder(file, &(*tree), 0);
fclose(file);

file = fopen(outFile[2],"w");
postOrder(file, &(*tree), 0);
fclose(file);

return 0;
}
