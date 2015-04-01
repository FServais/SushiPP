PARSER_PATH = parser/
SCANNER_PATH = scanner/
NODES_PATH = nodes/
NONTERMINAL_PATH = $(NODES_PATH)nonterminal/
TOKENS_PATH = $(NODES_PATH)tokens/
CC = g++
CCFLAGS = --std=c++11

all: sushipp

sushipp: main.o node nonterminal tokens
	$(CC) nt_terminal.o nt_datastructure.o nt_statement.o nt_program.o \
		  nt_expression.o nt_declaration.o nt_constant.o nt_functioncall.o \
		  main.o ast_node.o ast.o node_location.o token.o constanttoken.o \
		  delimiter.o keyword.o operator.o \
		  -o test_ast $(CCFLAGS)

# main
main.o: main.cpp
	$(CC) -c main.cpp -o main.o $(CCFLAGS)

# AST #
ast.o: AbstractSyntaxTree.cpp AbstractSyntaxTree.hpp $(NODES_PATH)ASTNode.hpp
	$(CC) -c AbstractSyntaxTree.cpp -o ast.o $(CCFLAGS)

# Node #
node: ast_node.o node_location.o

ast_node.o: $(NODES_PATH)ASTNode.cpp $(NODES_PATH)ASTNode.hpp $(NODES_PATH)NodeLocation.hpp
	$(CC) -c $(NODES_PATH)ASTNode.cpp -o ast_node.o $(CCFLAGS)

node_location.o: $(NODES_PATH)NodeLocation.cpp $(NODES_PATH)NodeLocation.hpp 
	$(CC) -c $(NODES_PATH)NodeLocation.cpp -o node_location.o $(CCFLAGS)

# Non terminal #
nonterminal: nt_terminal.o nt_datastructure.o nt_statement.o nt_program.o nt_expression.o nt_declaration.o nt_constant.o nt_functioncall.o

nt_terminal.o: $(NONTERMINAL_PATH)NonTerminal.cpp $(NONTERMINAL_PATH)NonTerminal.hpp  $(NODES_PATH)NodeLocation.hpp $(NODES_PATH)ASTNode.hpp
	$(CC) -c $(NONTERMINAL_PATH)NonTerminal.cpp -o nt_terminal.o $(CCFLAGS)

nt_datastructure.o: $(NONTERMINAL_PATH)NT_Datastructure.cpp $(NONTERMINAL_PATH)NT_Datastructure.hpp $(NODES_PATH)NodeLocation.hpp $(NONTERMINAL_PATH)NonTerminal.hpp
	$(CC) -c $(NONTERMINAL_PATH)NT_Datastructure.cpp -o nt_datastructure.o $(CCFLAGS) 

nt_statement.o: $(NONTERMINAL_PATH)NT_Statement.cpp $(NONTERMINAL_PATH)NT_Statement.hpp $(NODES_PATH)NodeLocation.hpp $(NONTERMINAL_PATH)NonTerminal.hpp
	$(CC) -c $(NONTERMINAL_PATH)NT_Statement.cpp -o nt_statement.o $(CCFLAGS)

nt_program.o: $(NONTERMINAL_PATH)NT_Program.cpp $(NONTERMINAL_PATH)NT_Program.hpp $(NODES_PATH)NodeLocation.hpp $(NONTERMINAL_PATH)NonTerminal.hpp
	$(CC) -c $(NONTERMINAL_PATH)NT_Program.cpp -o nt_program.o $(CCFLAGS)

nt_expression.o: $(NONTERMINAL_PATH)NT_Expression.cpp $(NONTERMINAL_PATH)NT_Expression.hpp $(NODES_PATH)NodeLocation.hpp $(NONTERMINAL_PATH)NonTerminal.hpp
	$(CC) -c $(NONTERMINAL_PATH)NT_Expression.cpp -o nt_expression.o $(CCFLAGS)

nt_declaration.o: $(NONTERMINAL_PATH)NT_Declaration.cpp $(NONTERMINAL_PATH)NT_Declaration.hpp $(NODES_PATH)NodeLocation.hpp $(NONTERMINAL_PATH)NonTerminal.hpp
	$(CC) -c $(NONTERMINAL_PATH)NT_Declaration.cpp -o nt_declaration.o $(CCFLAGS)

nt_constant.o: $(NONTERMINAL_PATH)NT_Constant.cpp $(NONTERMINAL_PATH)NT_Constant.hpp $(NODES_PATH)NodeLocation.hpp $(NONTERMINAL_PATH)NonTerminal.hpp
	$(CC) -c $(NONTERMINAL_PATH)NT_Constant.cpp -o nt_constant.o $(CCFLAGS)

nt_functioncall.o: $(NONTERMINAL_PATH)NT_FunctionCall.cpp $(NONTERMINAL_PATH)NT_FunctionCall.hpp $(NODES_PATH)NodeLocation.hpp $(NONTERMINAL_PATH)NonTerminal.hpp
	$(CC) -c $(NONTERMINAL_PATH)NT_FunctionCall.cpp -o nt_functioncall.o $(CCFLAGS)


# Tokens #
tokens: token.o constanttoken.o delimiter.o keyword.o operator.o

token.o: $(TOKENS_PATH)Token.cpp $(TOKENS_PATH)Token.hpp $(NODES_PATH)NodeLocation.hpp $(NODES_PATH)ASTNode.hpp
	$(CC) -c $(TOKENS_PATH)Token.cpp -o token.o $(CCFLAGS)

constanttoken.o: $(TOKENS_PATH)ConstantToken.cpp $(TOKENS_PATH)ConstantToken.hpp $(NODES_PATH)NodeLocation.hpp $(TOKENS_PATH)Token.hpp 
	$(CC) -c $(TOKENS_PATH)ConstantToken.cpp -o constanttoken.o $(CCFLAGS)

delimiter.o: $(TOKENS_PATH)Delimiter.cpp $(TOKENS_PATH)Delimiter.hpp $(NODES_PATH)NodeLocation.hpp $(TOKENS_PATH)Token.hpp 
	$(CC) -c $(TOKENS_PATH)Delimiter.cpp -o delimiter.o $(CCFLAGS)

keyword.o: $(TOKENS_PATH)Keyword.cpp $(TOKENS_PATH)Keyword.hpp $(NODES_PATH)NodeLocation.hpp $(TOKENS_PATH)Token.hpp 
	$(CC) -c $(TOKENS_PATH)Keyword.cpp -o keyword.o $(CCFLAGS)

operator.o: $(TOKENS_PATH)Operator.cpp $(TOKENS_PATH)Operator.hpp $(NODES_PATH)NodeLocation.hpp $(TOKENS_PATH)Token.hpp 
	$(CC) -c $(TOKENS_PATH)Operator.cpp -o operator.o $(CCFLAGS)


clean:
	rm -rf *.o *.~  $(NODES_PATH)*.o $(TOKENS_PATH)*.o $(NONTERMINAL_PATH)*.o $(NODES_PATH)*.o