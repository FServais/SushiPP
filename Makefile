PARSER_PATH = parser/
SCANNER_PATH = scanner/
CC = g++
CCFLAGS = --std=c++11

all: sushipp

sushipp.tab.o: $(PARSER_PATH)spp_parser.y
	bison -d $(PARSER_PATH)spp_parser.y -b $(PARSER_PATH)sushipp
	$(CC) -c $(PARSER_PATH)sushipp.tab.c -o $(PARSER_PATH)sushipp.tab.o $(CCFLAGS)

sushipp.yy.o: $(SCANNER_PATH)spp_scanner.lex sushipp.tab.o
	flex -o $(SCANNER_PATH)sushipp.yy.c $(SCANNER_PATH)spp_scanner.lex 
	$(CC) -c $(SCANNER_PATH)sushipp.yy.c -o $(SCANNER_PATH)sushipp.yy.o $(CCFLAGS)

main.o: sushipp.tab.o
	$(CC) -c main.cpp -o main.o $(CCFLAGS)

sushipp: sushipp.tab.o sushipp.yy.o main.o 
	$(CC) $(PARSER_PATH)sushipp.tab.o $(SCANNER_PATH)sushipp.yy.o main.o -o sushipp $(CCFLAGS)

clean: 
	rm -rf *.o
	rm -rf *~

clean-hard: clean
	rm -f $(SCANNER_PATH)sushipp.yy.c 
	rm -f $(SCANNER_PATH)sushipp.yy.o
	rm -f $(PARSER_PATH)sushipp.tab.c $(PARSER_PATH)sushipp.tab.h 
	rm -f $(PARSER_PATH)sushipp.tab.o
