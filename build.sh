gcc -I ./include -c ./src/errorhandler.c -o eh.o
gcc -I ./include -c ./src/io_asm.c -o io.o
gcc -I ./include -c ./src/bor.c -o bor.o
gcc -I ./include -c ./src/instruction.c -o inst.o
gcc -I ./include -c ./src/clear_str.c -o cl.o
gcc -I ./include -c main.c -o main.o
gcc -o main main.o cl.o inst.o bor.o io.o eh.o