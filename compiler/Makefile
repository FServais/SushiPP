PARSER_PATH = parser/
SCANNER_PATH = scanner/

all: sushipp

sushipp.tab.c sushipp.tab.h: $(PARSER_PATH)spp_parser.y
	bison -d $(PARSER_PATH)spp_parser.y -b $(PARSER_PATH)sushipp

sushipp.yy.c: $(SCANNER_PATH)spp_scanner.lex sushipp.tab.h
	flex -o $(SCANNER_PATH)sushipp.yy.c $(SCANNER_PATH)spp_scanner.lex 

sushipp: sushipp.yy.c sushipp.tab.c sushipp.tab.h
	g++ $(PARSER_PATH)sushipp.tab.c $(SCANNER_PATH)sushipp.yy.c -lfl -o sushipp --std=c++11

clean: 
	rm -rf *.o
	rm -rf *~

clean-hard: clean
	rm -f $(SCANNER_PATH)sushipp.yy.c 
	rm -f $(PARSER_PATH)sushipp.tab.c $(PARSER_PATH)sushipp.tab.h 
