#include "errorhandler.h"

void errorhandler(int error, char[] funс) {
    if (error == 0x1) {
        printf("Critical error: file load fail. Function ", funс);
        return -1;
    }
}