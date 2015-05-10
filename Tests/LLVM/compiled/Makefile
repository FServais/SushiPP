ASSEMBLY = support.s array_runtime.s list_runtime.s main.s 
DELETABLE_LL = support.ll array_runtime.ll list_runtime.ll
EXECUTABLE = main
CC = clang
CFLAGS = -c -S -emit-llvm
LD = gcc
LDFLAGS =
LLVM_ASSEMBLER = llvm-as
LLVM_COMPILER  = llc

all: $(ASSEMBLY)
	gcc -o $(EXECUTABLE) $(ASSEMBLY)

main.s: main.ll
	$(LLVM_ASSEMBLER) main.ll -o main.bc
	$(LLVM_COMPILER) main.bc -o $@

support.s: support.c support.h
	$(CC) $< -o support.ll $(CFLAGS)
	$(LLVM_ASSEMBLER) support.ll -o support.bc
	$(LLVM_COMPILER) support.bc -o $@

array_runtime.s: array_runtime.c array_runtime.h
	$(CC) $< -o array_runtime.ll $(CFLAGS)
	$(LLVM_ASSEMBLER) array_runtime.ll -o array_runtime.bc
	$(LLVM_COMPILER) array_runtime.bc -o $@

list_runtime.s: list_runtime.c list_runtime.h
	$(CC) $< -o list_runtime.ll $(CFLAGS)
	$(LLVM_ASSEMBLER) list_runtime.ll -o list_runtime.bc
	$(LLVM_COMPILER) list_runtime.bc -o $@

clean:
	rm -f *.s
	rm -f $(DELETABLE_LL)
	rm -f *.o
	rm -f *.bc
