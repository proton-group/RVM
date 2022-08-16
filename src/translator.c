//
// Created by anatoly on 1.01.2022.
//
#include "translator.h"
int datacheck(char* command, int* i, char* data, char* imm, int* keysize, int* immsize) {
    int d = 0;
    while(command[*i] != ',' && command[*i] != ' ' && command[*i] != '\0' && command[*i] != '\n') {
        data[d] = command[*i];
        imm[d] = data[d];
        (*i)++;
        d++;
    }
    *keysize = d;
    *immsize = d;
    (*i)+=2;
    if(data[0]!='x') {
        while (d<21) {
            imm[d] = '0';
            d++;
        }
        return 1;
    }
    else {
        return 0;
    }
}

char* commandread(char* command, node* root1, node* root2) {
    //strclear(command);
    int i = 0;
    char inst[6];
    while(command[i] != ' ') {
        inst[i] = command[i];
        i++;
    }
    int keysize = i;
    char* newinst = get(root1, inst, keysize);
    i++;
    char r[3][3];
    int d = 0;
    char imm[64];
    int rkeysize[5];
    int immsize = 0;
    while(!datacheck(command, &i, r[d], imm, &(rkeysize[d]), &immsize)) d++;
    int statcheck;
    char newimm[12];
    int_to_char(newimm, parse_number(imm, immsize));
    int cur1 = 0;
    int cur2 = 0;
    int cur3 = 0;
    int cur4 = 0;
    char* r0data = get(root2, r[0], 2);
    char* r1data = get(root2, r[1], 2);
    char* r2data = get(root2, r[2], 2);
    i = 31;
    while(i >= 0) {
        if(newinst[i] == '2') {
            newinst[i] = get(root2, r[0], rkeysize[0])[cur1];
            cur1++;
        }
        if(newinst[i] == '3') {
            newinst[i] = get(root2, r[1], rkeysize[1])[cur2];
            cur2++;
        }
        if(newinst[i] == '4') {
            newinst[i] = get(root2, r[2], rkeysize[2])[cur3];
            cur3++;
        }
        if(newinst[i] == '5') {
            newinst[i] = newimm[cur4];
            cur4++;
        }
        i--;
    }
    return newinst;
}


