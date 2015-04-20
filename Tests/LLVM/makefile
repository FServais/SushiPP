EXECUTABLE=fibonacci

all: fibonacci.ll
	llvm-as fibonacci.ll
	llc fibonacci.bc
	gcc -o $(EXECUTABLE) fibonacci.s

clean:
	rm $(EXECUTABLE)
	rm fibonacci.s
	rm fibonacci.bc
