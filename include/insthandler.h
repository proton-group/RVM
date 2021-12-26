#ifndef INSTHANDLER_H
#define INSTHANDLER_H

#define LUI 0x37;
#define AUIPC 0x17;
#define JAL 0x6a;
#define JALR 0x67;
#define BEQ 0x63;
#define BNE 0xE3;
#define BLT 0x263;
#define BGE 0x2E3;
#define BLTU 0x363;
#define BGEU 0x3E3;
#define LB 0x3;
#define LH 0x83;
#define LW 0x103;
#define LBU 0x203;
#define LHU 0x283;
#define SB 0x23;
#define SH 0xA3;
#define SW 0x123;
#define ADDI 0x13;
#define SLTI 0x113;
#define SLTIU 0x193;
#define XORI 0x213;
#define ORI 0x313;
#define ANDI 0x393;
#define SLLI 0x93;
#define SRLI 0x293;
#define SRAI 0x8293;
#define ADD 0x33;
#define SUB 0x8033;
#define SLL 0xB3;
#define SLT 0x133;
#define SLTU 0x1B3;
#define XOR 0x233;
#define SRL 0x2B3;
#define SRA 0x82B3;
#define OR 0x333;
#define AND 0x3B3;
#define FENCE 0xF;
#define ECALL 0x73;
#define EBREAK 0x100073;

void search(unsigned int opcode);
int readinstname(unsigned __int64 inst);
void inst(unsigned __int64 inst, unsigned int instname);
#endif