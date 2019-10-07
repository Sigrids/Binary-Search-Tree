#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Length* newLen(){
 Length* tree = malloc(sizeof(Length));
 tree->right = NULL;
 tree->left = NULL;
 tree->word = NULL;
 return tree;
}
Word* newWord(){
 Word* word = malloc(sizeof(Word));
 word->next = NULL;
 return word;
}

static void printWord(FILE* file, Word* word){
    if (word){
        printWord(file, word->next);
        fprintf(file, "%s ", word->word);
    }
}

void inOrder(FILE* file, Length* tree, int level){
 if(tree){
  inOrder(file, tree->left, level + 1);
  fprintf(file, "%*c%d ", level*2, ' ', tree->length);
  printWord(file, tree->word);
  fprintf(file, "\n");
  inOrder(file, tree->right, level + 1);
 }
}

void preOrder(FILE* file, Length* tree, int level){
 if(tree){
  fprintf(file, "%*c%d ", level*2, ' ', tree->length);
  printWord(file, tree->word);
  fprintf(file, "\n");
  preOrder(file, tree->left, level + 1);
  preOrder(file, tree->right, level + 1);
 }
}

void postOrder(FILE* file, Length* tree, int level){
 if(tree){
  postOrder(file, tree->left, level + 1);
  postOrder(file, tree->right, level + 1);
  fprintf(file, "%*c%d ", level*2, ' ', tree->length);
  printWord(file, tree->word);
  fprintf(file, "\n");
 }
}

// adding a word to the correct group
void addWord(Word **word, char* str){
 Word* temp = NULL;
 if(!(*word)){
  temp = newWord();
  temp->word = malloc(sizeof(str));
  strcpy(temp->word, str);
  printf("%s\n", str);
  *word = temp;
  return;
 }
 addWord(&(*word)->next, str);
}

//inserting node into the length tree len=node
void insert(Length** tree, char str[], int num){
 Length* temp = NULL;
 if(!(*tree)){
  temp = newLen();
  temp->length = num;
  addWord(&temp->word, str);
  *tree = temp;
  return;
 }

 if(num < (*tree)->length){
  insert(&(*tree)->left, str, num);
  }
  else if(num > (*tree)->length){
  insert(&(*tree)->right, str, num);
 }
 else{
  addWord(&(*tree)->word, str);
 }
}

