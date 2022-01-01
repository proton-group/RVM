#ifndef MEMORY_H
#define MEMORY_H

typedef struct reg {
    unsigned long long x[32];
    unsigned long long f[32];
} reg;

reg reginit();

int memload(int adress);
int memsave(int adress, int data);


#endif