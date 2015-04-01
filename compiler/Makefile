PARSER_PATH = parser/
SCANNER_PATH = scanner/
AST_PATH = ast/
NODES_PATH = $(AST_PATH)nodes/
NONTERMINAL_PATH = $(NODES_PATH)nonterminal/
TOKENS_PATH = $(NODES_PATH)tokens/
CC = g++
CCFLAGS = --std=c++11

all: sushipp

sushipp: ast.o node nonterminal tokens sushipp.tab.o sushipp.yy.o main.o 
	$(CC) $(PARSER_PATH)sushipp.tab.o $(SCANNER_PATH)sushipp.yy.o main.o \
		  $(AST_PATH)ast.o $(NODES_PATH)node_location.o $(NODES_PATH)ast_node.o \
		  $(NONTERMINAL_PATH)nt_terminal.o $(NONTERMINAL_PATH)nt_datastructure.o \
		  $(NONTERMINAL_PATH)nt_statement.o $(NONTERMINAL_PATH)nt_program.o \
		  $(NONTERMINAL_PATH)nt_expression.o $(NONTERMINAL_PATH)nt_declaration.o \
		  $(NONTERMINAL_PATH)nt_constant.o $(NONTERMINAL_PATH)nt_functioncall.o  \
		  $(TOKENS_PATH)token.o $(TOKENS_PATH)constanttoken.o $(TOKENS_PATH)delimiter.o \
		   $(TOKENS_PATH)keyword.o $(TOKENS_PATH)operator.o	\
		  -o sushipp $(CCFLAGS)

# main
main.o: sushipp.tab.o
	$(CC) -c main.cpp -o main.o $(CCFLAGS)

# scanner and parser
sushipp.tab.o: $(PARSER_PATH)spp_parser.y 
	bison -d $(PARSER_PATH)spp_parser.y -b $(PARSER_PATH)sushipp
	$(CC) -c $(PARSER_PATH)sushipp.tab.c -o $(PARSER_PATH)sushipp.tab.o $(CCFLAGS)

sushipp.yy.o: $(SCANNER_PATH)spp_scanner.lex sushipp.tab.o
	flex -o $(SCANNER_PATH)sushipp.yy.c $(SCANNER_PATH)spp_scanner.lex 
	$(CC) -c $(SCANNER_PATH)sushipp.yy.c -o $(SCANNER_PATH)sushipp.yy.o $(CCFLAGS)

# AST #
ast.o: $(AST_PATH)AbstractSyntaxTree.cpp $(AST_PATH)AbstractSyntaxTree.hpp $(NODES_PATH)ASTNode.hpp
	$(CC) -c $(AST_PATH)AbstractSyntaxTree.cpp -o $(AST_PATH)ast.o $(CCFLAGS)

# Node #
node: ast_node.o node_location.o

ast_node.o: $(NODES_PATH)ASTNode.cpp $(NODES_PATH)ASTNode.hpp $(NODES_PATH)NodeLocation.hpp
	$(CC) -c $(NODES_PATH)ASTNode.cpp -o $(NODES_PATH)ast_node.o $(CCFLAGS)

node_location.o: $(NODES_PATH)NodeLocation.cpp $(NODES_PATH)NodeLocation.hpp 
	$(CC) -c $(NODES_PATH)NodeLocation.cpp -o $(NODES_PATH)node_location.o $(CCFLAGS)

# Non terminal #
nonterminal: nt_terminal.o nt_datastructure.o nt_statement.o nt_program.o nt_expression.o nt_declaration.o nt_constant.o nt_functioncall.o

nt_terminal.o: $(NONTERMINAL_PATH)NonTerminal.cpp $(NONTERMINAL_PATH)NonTerminal.hpp  $(NODES_PATH)NodeLocation.hpp $(NODES_PATH)ASTNode.hpp
	$(CC) -c $(NONTERMINAL_PATH)NonTerminal.cpp -o $(NONTERMINAL_PATH)nt_terminal.o $(CCFLAGS)

nt_datastructure.o: $(NONTERMINAL_PATH)NT_Datastructure.cpp $(NONTERMINAL_PATH)NT_Datastructure.hpp $(NODES_PATH)NodeLocation.hpp $(NONTERMINAL_PATH)NonTerminal.hpp
	$(CC) -c $(NONTERMINAL_PATH)NT_Datastructure.cpp -o $(NONTERMINAL_PATH)nt_datastructure.o $(CCFLAGS) 

nt_statement.o: $(NONTERMINAL_PATH)NT_Statement.cpp $(NONTERMINAL_PATH)NT_Statement.hpp $(NODES_PATH)NodeLocation.hpp $(NONTERMINAL_PATH)NonTerminal.hpp
	$(CC) -c $(NONTERMINAL_PATH)NT_Statement.cpp -o $(NONTERMINAL_PATH)nt_statement.o $(CCFLAGS)

nt_program.o: $(NONTERMINAL_PATH)NT_Program.cpp $(NONTERMINAL_PATH)NT_Program.hpp $(NODES_PATH)NodeLocation.hpp $(NONTERMINAL_PATH)NonTerminal.hpp
	$(CC) -c $(NONTERMINAL_PATH)NT_Program.cpp -o $(NONTERMINAL_PATH)nt_program.o $(CCFLAGS)

nt_expression.o: $(NONTERMINAL_PATH)NT_Expression.cpp $(NONTERMINAL_PATH)NT_Expression.hpp $(NODES_PATH)NodeLocation.hpp $(NONTERMINAL_PATH)NonTerminal.hpp
	$(CC) -c $(NONTERMINAL_PATH)NT_Expression.cpp -o $(NONTERMINAL_PATH)nt_expression.o $(CCFLAGS)

nt_declaration.o: $(NONTERMINAL_PATH)NT_Declaration.cpp $(NONTERMINAL_PATH)NT_Declaration.hpp $(NODES_PATH)NodeLocation.hpp $(NONTERMINAL_PATH)NonTerminal.hpp
	$(CC) -c $(NONTERMINAL_PATH)NT_Declaration.cpp -o $(NONTERMINAL_PATH)nt_declaration.o $(CCFLAGS)

nt_constant.o: $(NONTERMINAL_PATH)NT_Constant.cpp $(NONTERMINAL_PATH)NT_Constant.hpp $(NODES_PATH)NodeLocation.hpp $(NONTERMINAL_PATH)NonTerminal.hpp
	$(CC) -c $(NONTERMINAL_PATH)NT_Constant.cpp -o $(NONTERMINAL_PATH)nt_constant.o $(CCFLAGS)

nt_functioncall.o: $(NONTERMINAL_PATH)NT_FunctionCall.cpp $(NONTERMINAL_PATH)NT_FunctionCall.hpp $(NODES_PATH)NodeLocation.hpp $(NONTERMINAL_PATH)NonTerminal.hpp
	$(CC) -c $(NONTERMINAL_PATH)NT_FunctionCall.cpp -o $(NONTERMINAL_PATH)nt_functioncall.o $(CCFLAGS)


# Tokens #
tokens: token.o constanttoken.o delimiter.o keyword.o operator.o

token.o: $(TOKENS_PATH)Token.cpp $(TOKENS_PATH)Token.hpp $(NODES_PATH)NodeLocation.hpp $(NODES_PATH)ASTNode.hpp
	$(CC) -c $(TOKENS_PATH)Token.cpp -o $(TOKENS_PATH)token.o $(CCFLAGS)

constanttoken.o: $(TOKENS_PATH)ConstantToken.cpp $(TOKENS_PATH)ConstantToken.hpp $(NODES_PATH)NodeLocation.hpp $(TOKENS_PATH)Token.hpp 
	$(CC) -c $(TOKENS_PATH)ConstantToken.cpp -o $(TOKENS_PATH)constanttoken.o $(CCFLAGS)

delimiter.o: $(TOKENS_PATH)Delimiter.cpp $(TOKENS_PATH)Delimiter.hpp $(NODES_PATH)NodeLocation.hpp $(TOKENS_PATH)Token.hpp 
	$(CC) -c $(TOKENS_PATH)Delimiter.cpp -o $(TOKENS_PATH)delimiter.o $(CCFLAGS)

keyword.o: $(TOKENS_PATH)Keyword.cpp $(TOKENS_PATH)Keyword.hpp $(NODES_PATH)NodeLocation.hpp $(TOKENS_PATH)Token.hpp 
	$(CC) -c $(TOKENS_PATH)Keyword.cpp -o $(TOKENS_PATH)keyword.o $(CCFLAGS)

operator.o: $(TOKENS_PATH)Operator.cpp $(TOKENS_PATH)Operator.hpp $(NODES_PATH)NodeLocation.hpp $(TOKENS_PATH)Token.hpp 
	$(CC) -c $(TOKENS_PATH)Operator.cpp -o $(TOKENS_PATH)operator.o $(CCFLAGS)


# clean 
clean: 
	rm -rf *.o
	rm -rf $(PARSER_PATH)*.o $(SCANNER_PATH)*.o $(NODES_PATH)*.o $(NONTERMINAL_PATH)*.o $(TOKENS_PATH)*.o
	rm -rf *~

clean-hard: clean
	rm -f $(SCANNER_PATH)sushipp.yy.c 
	rm -f $(PARSER_PATH)sushipp.tab.c $(PARSER_PATH)sushipp.tab.h 


	