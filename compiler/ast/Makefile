NODES_PATH = nodes/
NONTERMINAL_PATH = nonterminal/
TOKENS_PATH = tokens/
CC = clang
CCFLAGS = --std=c++11

all: ast

ast: nodes.o nonterminal.o tokens.o
	$(CC) -c nodes.o nonterminal.o tokens.o -o ast $(CCFLAGS)

nodes.o: $(NODES_PATH)ASTNode.cpp $(NODES_PATH)NodeLocation.cpp
	$(CC) -c $? $(CCFLAGS)

nonterminal.o: $(NONTERMINAL_PATH)NonTerminal.cpp $(NONTERMINAL_PATH)NT_Constant.cpp $(NONTERMINAL_PATH)NT_Datastructure.cpp $(NONTERMINAL_PATH)NT_Declaration.cpp $(NONTERMINAL_PATH)NT_Expression.cpp $(NONTERMINAL_PATH)NT_FunctionCall.cpp $(NONTERMINAL_PATH)NT_Program.cpp $(NONTERMINAL_PATH)NT_Statement.cpp
	$(CC) -c $? $(CCFLAGS)

tokens.o: $(TOKENS_PATH)Token.cpp $(TOKENS_PATH)ConstantToken.cpp $(TOKENS_PATH)Delimiter.cpp $(TOKENS_PATH)Keyword.cpp $(TOKENS_PATH)Operator.cpp
	$(CC) -c $? $(CCFLAGS)

clean: 
	rm -rf *.o
	rm -rf *~

