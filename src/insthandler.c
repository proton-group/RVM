#include "insthandler.h"

int readinst(unsigned long long inst) {
    int opcode = inst & 0x7F;
    int func3 = (inst & 0x7000)>>7;
    int code_1[] = {0x37, 0x17, 0x6a};
    int code_2[] = {0x67, 0x63, 0x3, 0x23, 0xF};
    for(int i = 0; i<3; i++) {
        if(code_1[i] == opcode) return opcode;
    }
    for(int i = 0; i<5; i++) {
        if(code_2[i] == opcode) return opcode + func3 << 7;
    }
    if(opcode == 0x13) {
        if(func3 == 0x5) return opcode + (func3 << 7) + (0x20 << 10);
        else return opcode + (func3 << 7);
    }
    if(opcode == 0x33) {
        if (func3 == 0 || func3 == 0x5) return opcode + (func3 << 7) + (0x20 << 10);
        return opcode + (func << 7);
    }
    return opcode;
}

void curset(unsigned long long inst, int* cur, int rs1, int rs2, int*(comp)(int a, int b)) {
        if(comp(rs1, rs2)) {
            *cur = ((inst>>25) << 5)|((inst >> 7) & 0x1F);
        }
        else {
            *cur++;
        }
}

int cbeq(int rs1, int rs2) {
    return rs1 == rs2;
}
int cbne(int rs1, int rs2) {
    return rs1 != rs2;
}
int cblt(int rs1, int rs2) {
    return rs1 < rs2;
}
int cbge(int rs1, int rs2) {
    return rs1 <= rs2;
}
int cbltu(unsigned int rs1, unsigned int rs2) {
    return rs1 < rs2;
}
int cbgeu(unsigned int rs1, unsigned int rs2) {
    return rs1 <= rs2;
}

void inst(unsigned long long inst, int* cur, reg* r) {
    unsigned int instname = readinst(inst);
    int ri = (inst >> 7) & 0x1F;
    int rs1 = (inst >> 15) & 0x1F;
    int rs2 = (inst >> 20) & 0x1F;
    //rd указан в инструкции
    if(instname == LUI) {
        r -> x[ri] = inst >> 12;
        *cur++;
    }
    if(instname == AUIPC) {
        r -> x[ri] = *cur;
        *cur++;
    }
    if(instname == JAL) {
        if(ri != 0) r -> x[ri] = *cur;
        *cur = inst >> 12;
    }
    if(instname == JALR) {
        if(ri != 0) r -> x[ri] = *cur;
        *cur = (inst >> 15) & 0x1F;
    }
    if(instname == BEQ) curset(inst, *cur, rs1, rs2, cbeq);
    if(instname == BNE) curset(inst, *cur, rs1, rs2, cbne);
    if(instname == BLT) curset(inst, *cur, rs1, rs2, cblt);
    if(instname == BGE) curset(inst, *cur, rs1, rs2, cbge);
    if(instname == BLTU) curset(inst, *cur, rs1, rs2, cbltu);
    if(instname == BGEU) curset(inst, *cur, rs1, rs2, cbgeu);
    if(instname == LB) 

}