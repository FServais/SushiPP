###########################################################
# various path #
PATH_PARSER		 = parser/
PATH_SCANNER	 = scanner/
PATH_AST		 = ast/
PATH_NODES	  	 = $(PATH_AST)nodes/
PATH_NONTERMINAL = $(PATH_NODES)nonterminal/
PATH_TOKENS 	 = $(PATH_NODES)tokens/
PATH_VISITOR	 = $(PATH_AST)visitor/
PATH_EXCEP		 = exceptions/
PATH_SYMB		 = symbol_table/
PATH_SETTINGS    = settings/

PATH_OBJS		 = obj/

# objects #
OBJS_NODES    = $(PATH_OBJS)NodeLocation.o $(PATH_OBJS)AstNode.o $(PATH_OBJS)ErrorNode.o
OBJS_TOKENS   = $(PATH_OBJS)Operator.o $(PATH_OBJS)Token.o $(PATH_OBJS)ConstantToken.o $(PATH_OBJS)Delimiter.o $(PATH_OBJS)Keyword.o
OBJS_NONTERMS = $(PATH_OBJS)NonTerminal.o $(PATH_OBJS)NT_Datastructure.o $(PATH_OBJS)NT_Statement.o $(PATH_OBJS)NT_Program.o $(PATH_OBJS)NT_Expression.o $(PATH_OBJS)NT_Declaration.o $(PATH_OBJS)NT_Constant.o $(PATH_OBJS)NT_Functioncall.o
OBJS_NODE_ALL = $(OBJS_NODES) $(OBJS_NONTERMS) $(OBJS_TOKENS)
OBJS_AST 	  = $(PATH_OBJS)AbstractSyntaxTree.o
OBJS_VST	  = $(PATH_OBJS)PrintASTVisitor.o
OBJS_EXCEP    = $(PATH_OBJS)Exceptions.o
OBJS_MAIN 	  = $(PATH_OBJS)main.o
OBJS_PARSER   = $(PATH_OBJS)sushipp.tab.o
OBJS_COMP	  = SPPCompiler.o
OBJS_SCANNER  = $(PATH_OBJS)sushipp.yy.o
OBJS_SETTINGS = $(PATH_OBJS)CompilerSettings.o

OBJS = $(OBJS_NODE_ALL) $(OBJS_AST) $(OBJS_MAIN) $(OBJS_VST) $(OBJS_PARSER) $(OBJS_SCANNER) $(OBJS_EXCEP) $(OBJS_COMP) $(OBJS_SETTINGS)

# dependecies #
# DEP_ASTNODE_DEEP : every header containing AST nodes derived or base class
# DEP_ASTNODE_DEEP_VISITOR : DEP_ASTNODE_DEEP + visitor base class header
# DEP_ASTNODE_SHALLOW : only ASTNode and NodeLocation header
# DEP_VISITORS : every visitor header (base or derived class)
# DEP_AST : every header needed by the AbstractSyntaxTree class
# DEP_AST_ALL : every header related to the AST (AST itself, nodes, NodeLocation)
# DEP_AST_ALL_VISITOR : DEP_AST_ALL + DEP_VISITORS
DEP_ASTNODE_DEEP 		 = $(PATH_NODES)*.hpp $(PATH_TOKENS)*.hpp $(PATH_NONTERMINAL)*.hpp
DEP_ASTNODE_DEEP_VISITOR = $(DEP_ASTNODE_DEEP) $(PATH_VISITOR)ASTVisitor.hpp
DEP_ASTNODE_SHALLOW 	 = $(PATH_NODES)ASTNode.hpp $(PATH_NODES)NodeLocation.hpp
DEP_VISITORS			 = $(PATH_VISITOR)ASTVisitor.hpp $(PATH_VISITOR)PrintASTVisitor.hpp
DEP_AST 				 = $(PATH_AST)AbstractSyntaxTree.hpp $(DEP_ASTNODE_SHALLOW)
DEP_AST_ALL  			 = $(DEP_ASTNODE_DEEP) $(PATH_AST)AbstractSyntaxTree.hpp
DEP_AST_ALL_VISITOR      = $(DEP_AST_ALL) $(DEP_VISITORS)

DEP_SYMB				 = $(PATH_SYMB)ScopeNode.hpp $(PATH_SYMB)SymbolTable.hpp
DEP_COMP				 = SPPCompiler.hpp
 
# compilation and linking flags #
CC = g++
DEBUG = -g
CCFLAGS = -c --std=c++11 $(DEBUG) 
LDFLAGS = 
EXE = sushipp
BISON_FLAGS = -d -b $(PATH_PARSER)$(EXE)
TARGETS = sushipp

###########################################################

all: $(TARGETS)

sushipp: $(OBJS)
	$(CC) $(OBJS) -o $(EXE) $(LDFLAGS)

# Main #
$(PATH_OBJS)main.o: main.cpp $(PATH_PARSER)sushipp.tab.h $(DEP_AST_ALL)
	$(CC) -c main.cpp -o $@ $(CCFLAGS)

# Parser #
$(PATH_OBJS)sushipp.tab.o: $(PATH_PARSER)sushipp.tab.c $(PATH_PARSER)sushipp.tab.h $(DEP_AST_ALL)
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_PARSER)sushipp.tab.h: $(PATH_PARSER)spp_parser.y 
	bison $< $(BISON_FLAGS)

$(PATH_PARSER)sushipp.tab.c: $(PATH_PARSER)spp_parser.y 
	bison $< $(BISON_FLAGS)

# Scanner #
$(PATH_OBJS)sushipp.yy.o: $(PATH_SCANNER)sushipp.yy.c
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_SCANNER)sushipp.yy.c: $(PATH_SCANNER)spp_scanner.lex
	flex -o $(PATH_SCANNER)sushipp.yy.c $<

# AST #
$(PATH_OBJS)AbstractSyntaxTree.o: $(PATH_AST)AbstractSyntaxTree.cpp $(DEP_AST)
	$(CC) $< -o $@ $(CCFLAGS)

# Nodes #
$(PATH_OBJS)AstNode.o: $(PATH_NODES)ASTNode.cpp $(DEP_ASTNODE_DEEP_VISITOR)
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)NodeLocation.o: $(PATH_NODES)NodeLocation.cpp $(PATH_NODES)/NodeLocation.hpp
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)ErrorNode.o: $(PATH_NODES)ErrorNode.cpp $(DEP_ASTNODE_SHALLOW)
	$(CC) $< -o $@ $(CCFLAGS)

# Non terminal nodes #
$(PATH_OBJS)NonTerminal.o: $(PATH_NONTERMINAL)NonTerminal.cpp $(DEP_ASTNODE_DEEP_VISITOR)
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)NT_Datastructure.o: $(PATH_NONTERMINAL)NT_Datastructure.cpp $(DEP_ASTNODE_DEEP_VISITOR)
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)NT_Statement.o: $(PATH_NONTERMINAL)NT_Statement.cpp $(DEP_ASTNODE_DEEP_VISITOR)
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)NT_Program.o: $(PATH_NONTERMINAL)NT_Program.cpp $(DEP_ASTNODE_DEEP_VISITOR)
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)NT_Expression.o: $(PATH_NONTERMINAL)NT_Expression.cpp $(DEP_ASTNODE_DEEP_VISITOR)
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)NT_Declaration.o: $(PATH_NONTERMINAL)NT_Declaration.cpp $(DEP_ASTNODE_DEEP_VISITOR)
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)NT_Constant.o: $(PATH_NONTERMINAL)NT_Constant.cpp $(DEP_ASTNODE_DEEP_VISITOR)
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)NT_Functioncall.o: $(PATH_NONTERMINAL)NT_FunctionCall.cpp $(DEP_ASTNODE_DEEP_VISITOR)
	$(CC) $< -o $@ $(CCFLAGS)

# Tokens #
$(PATH_OBJS)Token.o: $(PATH_TOKENS)Token.cpp $(DEP_ASTNODE_DEEP_VISITOR)
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)ConstantToken.o: $(PATH_TOKENS)ConstantToken.cpp $(DEP_ASTNODE_DEEP_VISITOR)
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)Delimiter.o: $(PATH_TOKENS)Delimiter.cpp $(DEP_ASTNODE_DEEP_VISITOR)
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)Keyword.o: $(PATH_TOKENS)Keyword.cpp $(DEP_ASTNODE_DEEP_VISITOR)
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)Operator.o: $(PATH_TOKENS)Operator.cpp $(DEP_ASTNODE_DEEP_VISITOR)
	$(CC) $< -o $@ $(CCFLAGS)

# Visitor #
$(PATH_OBJS)PrintASTVisitor.o: $(PATH_VISITOR)PrintASTVisitor.cpp $(DEP_VISITORS) $(DEP_ASTNODE_DEEP)
	$(CC) $< -o $@ $(CCFLAGS)

# Exceptions #
$(PATH_OBJS)Exceptions.o: $(PATH_EXCEP)Exceptions.cpp $(PATH_EXCEP)Exceptions.hpp
	$(CC) $< -o $@ $(CCFLAGS)

# Compiler #
$(PATH_OBJS)SPPCompiler.o: SPPCompiler.cpp SPPCompiler.hpp
	$(CC) $< -o $@ $(CCFLAGS)

###########################################################

# clean 
clean: 
	rm obj/*.o
	rm sushipp
	rm $(PATH_PARSER)*.output

clean-hard: clean
	rm -f $(PATH_SCANNER)sushipp.yy.c 
	rm -f $(PATH_PARSER)sushipp.tab.c $(PATH_PARSER)sushipp.tab.h 
