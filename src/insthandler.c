#include "insthandler.h"

int readinst(unsigned __int64 inst) {
    int opcode = inst & 0x7F;
    int func3 = inst & 0x7000;
    int code_1[] = {0x37, 0x17, 0x6a};
    int code_2[] = {0x67, 0x63, 0x3, 0x23, 0xF}
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

void inst(unsigned __int64 inst, unsigned __int64* rs1, unsigned __int64* rs2, unsigned __int64* rd) {
    unsigned int instname = readinst(inst);
    if(instname == LUI) *rd = 
}