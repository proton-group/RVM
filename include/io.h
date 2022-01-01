#ifndef IO_H
#define IO_H
#include <stdio.h>
#include "errorhandler.h"
#include <stdlib.h>
typedef struct queue {
    int* data;
    size_t msize;
    size_t dsize;
    int cur;
} queue;

queue qinit();
int get(queue* code);
void push(queue* code, int data);
int search(queue mem, int data, int* num);
int progload(FILE* prog, char* name, queue* code);

#endif