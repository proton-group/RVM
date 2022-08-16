#include "bor.h"

node createTree(){
    node root;
    root.parent = NULL;
    root.csize = 0;
    root.child = NULL;
    root.data = NULL;
    return root;
}

void _radd(node* root, char key[], int d, char data[], int msize, int keysize) {
    node* newchild = malloc(sizeof(node) * (root->csize + 1));
    if (newchild == NULL) exit(-1);
    for (int i = 0; i<root->csize; i++) {
        newchild[i] = root->child[i];
    }
    root->csize += 1;
    newchild[root->csize-1].parent = root;
    newchild[root->csize-1].csize = 0;
    newchild[root->csize-1].child = NULL;
    newchild[root->csize-1].key = key[d];
    free(root->child);
    root->child = newchild;
    if (d < keysize-1) {
        _radd((root->child+root->csize-1), key, d+1, data, msize, keysize);
    }
    else {
        root->child[root->csize-1].data = malloc(sizeof(char)*msize);
        for(int d=0; d<msize;d++) root->child[root->csize-1].data[d] = data[d];
    }
    return;
}

void _set(node* root, char key[], char data[], int msize, int keysize, int counter) {
    int flag = 0;
    for(int i = 0; i < root->csize; i++) {
        if (root->child != NULL) {
            if (root->child[i].key == key[counter]){
                flag = 1;
                if (counter == keysize-1) {
                    root->child[i].data = malloc(sizeof(char)*msize);
                    for(int d=0; d<msize;d++) root->child[i].data[d] = data[d];
                    return;
                }
                else {
                    _set(&(root->child[i]), key, data, msize, keysize, counter+1);
                    return;
                }
            }
        }
    }
    if(!flag) _radd(root, key, counter, data, msize, keysize);        
    return;
}

void set(node* root, char key[], char data[], int msize, int keysize) {
    _set(root, key, data, msize, keysize, 0);
}

char* _get(node* root, char key[], int keysize, int counter) {
    for(int i = 0; i < root->csize; i++) {
        if (root->child != NULL) {
            if (root->child[i].key == key[counter]){
                if (counter == keysize-1) {
                    return root->child[i].data;
                }
                else {
                    return _get(&(root->child[i]), key, keysize, counter+1);
                }
            }
        }
    }
    return '0';
}
char* get(node* root, char key[], int keysize) {
    return _get(root, key, keysize, 0);
}

void borfree(node* root) {
    free(root->data);
    for (int i = 0; i < root->csize; i++) {
        if (root->child != NULL) {
            borfree(&(root->child[i]));
        }
    }
    if(root->parent!=NULL) {
        free(root->child);
    }
    return;
}