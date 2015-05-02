EXEC_MAP_ARRAY     = map_array
EXEC_QUICKSORT     = quicksort
FILE_MAP_ARRAY     = $(EXEC_MAP_ARRAY).ll
FILE_QUICKSORT     = $(EXEC_QUICKSORT).ll
DEP_LIST_MAP_ARRAY = $(FILE_MAP_ARRAY)
DEP_LIST_QUICKSORT = $(FILE_QUICKSORT)

all: quicksort map_array

quicksort: $(DEP_LIST_QUICKSORT)
	llvm-as $(FILE_QUICKSORT)
	llc $(EXEC_QUICKSORT).bc
	gcc -o $(EXEC_QUICKSORT) $(EXEC_QUICKSORT).s

map_array: $(DEP_LIST_MAP_ARRAY)
	llvm-as $(FILE_MAP_ARRAY)
	llc $(EXEC_MAP_ARRAY).bc
	gcc -o $(EXEC_MAP_ARRAY) $(EXEC_MAP_ARRAY).s

clean:
	rm $(EXEC_MAP_ARRAY)
	rm $(EXEC_QUICKSORT)
	rm *.s
	rm *.bc
