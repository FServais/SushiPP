#EXECUTABLE=hello

#all: hello.ll
#	llvm-as hello.ll
#	llc hello.bc
#	gcc -o $(EXECUTABLE) hello.s

#clean:
#	rm $(EXECUTABLE)
#	rm hello.s
#	rm hello.bc

EXECUTABLE=quicksort
FILE=$(EXECUTABLE).ll

all: $(FILE)
	llvm-as $(FILE)
	llc $(EXECUTABLE).bc
	gcc -o $(EXECUTABLE) $(EXECUTABLE).s

clean:
	rm $(EXECUTABLE)
	rm $(EXECUTABLE).s
	rm $(EXECUTABLE).bc