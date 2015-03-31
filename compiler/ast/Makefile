NODES_PATH = nodes/
NONTERMINAL_PATH = nonterminal/
TOKENS_PATH = tokens/
CC = g++
CCFLAGS = --std=c++11

all: ast

ast: nodes.o nonterminal.o tokens.o
	$(CC) -c nodes.o nonterminal.o tokens.o -o ast $(CCFLAGS)

nodes.o: $(NODES_PATH)ASTNode.cpp $(NODES_PATH)NodeLocation.cpp
	$(CC) -c $(NODES_PATH)ASTNode.cpp $(NODES_PATH)NodeLocation.cpp $(CCFLAGS)

nonterminal.o: $(NONTERMINAL_PATH)*.cpp
	$(CC) -c $(NONTERMINAL_PATH)*.cpp $(CCFLAGS)

tokens.o: $(TOKENS_PATH)*.cpp
	$(CC) -c $(TOKENS_PATH)*.cpp $(CCFLAGS)

clean: 
	rm -rf *.o
	rm -rf *~

