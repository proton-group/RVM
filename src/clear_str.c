//
// Created by anatoly on 29.09.2021.
//
#include "clear_str.h"

void strclear(char* string) {
    int i = 0;
    int d = 0;
    while (string[i] != '\0') {
        if (isspace(string[i]) != 0) {
            while (isspace(string[i]) != 0) {
                d = 0;
                while (string[i + d] != '\0') {
                    string[i + d] = string[i + d + 1];
                    d++;
                }
            }
        }
            i++;
    }
}