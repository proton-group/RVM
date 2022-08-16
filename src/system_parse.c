//
// Created by anatoly on 29.09.2021.
//

//
// Created by anatoly on 29.09.2021.
//
#include "system_parse.h"
// рассмотреть входит ли в диапазон ASCI
int parse_number(char string[], int immsize)
{
    long number = 0;
    int znak = 1;
    int i = 0;
    char buf;
    while(i<immsize) {
        if (string[i] >= '0' && string[i] <= '9') {
            string[i] = (char) ((int) string[i] - 48);
        } else {
            break;
        }
        number = number * pow(10, i) + string[i];
        i++;
    }
    int newnum = 0;
    i =0;
    while(number != 0) {
        newnum = newnum + (number % 2)*pow(10, i);
        number = number / 2;
        i++;
    }
    return newnum;
}

void int_to_char(char* buf, int a) {
    for(int i = 0; i < 20; i++) {
        buf[i] = a%10 + '0';
        a = a / 10;
    }
}
