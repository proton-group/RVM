#include "memory.h"
#include "io.h"
#include "errorhandler.h"

reg reginit() {
    reg new;
    new.x[0] = 0;
    return reg;
}

int memload(int adress, queue memd, queue mema, int* data) {
    int dnum = 0;
    errorhandler(search(mema, adress, &dnum), __FUNCTION__);
    if (dnum != -1) {
        *data = memd.data[dnum];
        return 0;
    }
    else {
        return _READERROR;
    }
}
int memsave(int adress, queue memd, queue mema, int* data) {
    
}