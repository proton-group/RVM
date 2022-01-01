#include "io.h"

queue qinit() {
    queue out = {malloc(sizeof(int)*2), 2, 0, 0};
    return out;
}

int get(queue* code) {
    code -> cur++;
    return code -> data[code -> cur - 1];
}

void push(queue* code, int data) {
    if (code -> dsize >= code -> msize/2) {
        int* new = malloc(sizeof(int)*code -> msize*2);
        for(int i = 0; i<code -> dsize, i++) {
            new[i] = code -> data[i];
        }
        free(code -> data);
        code -> data = new;
    }
    else {
        code -> data[code -> dsize] = data;
        code -> dsize++;    
    }
    return;
}

int search(queue mem, int data, int* num) {
    for(int i = 0; i<mem.dsize; i++){
        if(mem.data[i] == data) {
            *num = i;
            return 0;
        }
    }
    return _SEARCHERROR;
}

int progload(FILE* prog, char* name, queue* code) {
    if (prog = fopen(name, "r") == NULL) return _OPENFAIL;
    int data;
    while(fscanf(prog, "%d", data) != EOF) push(code, data);
    return 0;
}