#include "errorhandler.h"

void errorhandler(int error, char[] fun) {
    if (error == 0x1) {
        printf("Critical error: file load fail. Function ", fun);
        return -1;
    }
}