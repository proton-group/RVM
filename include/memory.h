#ifndef MEMORY_H
#define MEMORY_H

struct reg {
    unsigned __int64 x[32];
    unsigned __int64 f[32];
}

reg reginit() {
    reg new;
    new.x[0] = 0;
    return reg;
}



#endif