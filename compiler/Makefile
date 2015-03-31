PARSER_PATH = parser/
SCANNER_PATH = scanner/
CC = g++

all: sushipp

sushipp: sushipp.yy.c 
	$(CC) $(PARSER_PATH)sushipp.tab.c $(SCANNER_PATH)sushipp.yy.c -o sushipp --std=c++11 -lfl

# parser scannner
sushipp.tab.c sushipp.tab.h: $(PARSER_PATH)spp_parser.y
	bison -d $(PARSER_PATH)spp_parser.y -b $(PARSER_PATH)sushipp -v

sushipp.yy.c: $(SCANNER_PATH)spp_scanner.lex sushipp.tab.h
	flex -o $(SCANNER_PATH)sushipp.yy.c $(SCANNER_PATH)spp_scanner.lex 

# AST


clean: 
	rm -rf *.o
	rm -rf *~

clean-hard: clean
	rm -f $(SCANNER_PATH)sushipp.yy.c 
	rm -f $(PARSER_PATH)sushipp.tab.c $(PARSER_PATH)sushipp.tab.h 


