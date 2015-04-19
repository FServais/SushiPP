EXECUTABLE=quicksort

all: quicksort.ll
	llvm-as quicksort.ll
	llc quicksort.bc
	gcc -o $(EXECUTABLE) quicksort.s

clean:
	rm $(EXECUTABLE)
	rm quicksort.s
	rm quicksort.bc
