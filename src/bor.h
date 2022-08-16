#ifndef BOR_H
#define BOR_H
#include <stdlib.h>
typedef struct node {
    struct node* child;
    struct node* parent;
    int csize;
    char key;
    char* data;
} node;

node createTree();
void _set(node* root, char key[], char data[], int msize, int keysize, int counter);
void set(node* root, char key[], char data[], int msize, int keysize);
char* _get(node* root, char key[], int keysize, int counter);
char* get(node* root, char key[], int keysize);
#endif
