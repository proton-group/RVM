#ifndef IO_H
#define IO_H
#include <stdio.h>
#include "errorhandler.h"
#include <stdlib.h>
struct queue {
    int* data;
    size_t msize;
    size_t dsize;
    int cur;
};
queue qinit();
int get(queue code);
void push(queue code, int data);
queue progload(FILE* prog, char* name);

#endif