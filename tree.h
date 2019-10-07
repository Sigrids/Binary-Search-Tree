#ifndef TREE_H_
#define TREE_H_

//Tree 
typedef struct Node{
 int length;
 struct Words *word;
 struct Node *left, *right;
}Length;

//Words is within Node(Length) 
typedef struct Words{
        char *word;
        struct Word *next;
}Word;

//function that returns a new empty node
Length* newLen();
//function that returns a new empty node
Word* newWord();

static void printWords(FILE*, Word*);
void insert(Length **, char[], int);
void addWord(Word **, char*);
void inOrder(FILE*, Length*, int);
void preOrder(FILE*, Length*, int);
void postOrder(FILE*,Length*,int);

#endif
