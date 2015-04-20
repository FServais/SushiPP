EXECUTABLE=quicksort
DEP_LIST=$(EXECUTABLE).ll
FILE=$(EXECUTABLE).ll

all: $(DEP_LIST)
	llvm-as $(FILE)
	llc $(EXECUTABLE).bc
	gcc -o $(EXECUTABLE) $(EXECUTABLE).s

clean:
	rm $(EXECUTABLE)
	rm $(EXECUTABLE).s
	rm $(EXECUTABLE).bc
