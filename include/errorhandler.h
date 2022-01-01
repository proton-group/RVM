#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H
#include <stdio.h>

#define _OPENFAIL 0x1;
#define _READERROR 0x2;
#define _SEARCHERROR 0x3;

void errorhandler(int error, char[] funс);

#endif