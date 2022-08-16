#include <stdio.h>
#include "bor.h"
#include "instruction.h"
//#include "clear_str.h"
#include "translator.h"

int main(int argc, char* argv[]) {
    node root1 = create_asm_inst();
    node root2 = createRegisters();
    FILE* prog;
    FILE* mach;
    if ((prog = fopen(argv[1], "r")) == NULL) return -1;
    if ((mach = fopen(argv[2], "w")) == NULL) return -1;
    char data[64];
    while(fgets(data, 64, prog) != NULL) {
        fprintf(mach, "%s\n", commandread(data, &root1, &root2));
        root1 = create_asm_inst();
        root2 = createRegisters();
    }
    fclose(prog);
    fclose(mach);
    borfree(&root1);
    borfree(&root2);
    return 0;
}

