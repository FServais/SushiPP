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
PATH_SYMB		 = symb/
PATH_SETTINGS    = settings/
PATH_ERRORS		 = errors/
PATH_INFERENCE   = inference/
PATH_CODEGEN	 = codegen/
PATH_UTIL 		 =

PATH_OBJS		 = obj/

# objects #
OBJS_NODES    		= $(PATH_OBJS)NodeLocation.o $(PATH_OBJS)AstNode.o $(PATH_OBJS)ErrorNode.o
OBJS_TOKENS   		= $(PATH_OBJS)Operator.o $(PATH_OBJS)Token.o $(PATH_OBJS)ConstantToken.o  $(PATH_OBJS)Keyword.o
OBJS_NONTERMS 		= $(PATH_OBJS)NonTerminal.o $(PATH_OBJS)NT_Datastructure.o $(PATH_OBJS)NT_Statement.o $(PATH_OBJS)NT_Program.o $(PATH_OBJS)NT_Expression.o $(PATH_OBJS)NT_Declaration.o $(PATH_OBJS)Constant.o $(PATH_OBJS)NT_Functioncall.o
OBJS_NODE_ALL 		= $(OBJS_NODES) $(OBJS_NONTERMS) $(OBJS_TOKENS)
OBJS_AST 	  		= $(PATH_OBJS)AbstractSyntaxTree.o
OBJS_VST	  		= $(PATH_OBJS)PrintASTVisitor.o $(PATH_OBJS)TypeInferenceVisitor.o $(PATH_OBJS)SymbolTableVisitor.o  $(PATH_OBJS)FunctionTableVisitor.o $(PATH_OBJS)CodeGenVisitor.o
OBJS_EXCEP    		= $(PATH_OBJS)Exceptions.o
OBJS_MAIN 	  		= $(PATH_OBJS)main.o
OBJS_PARSER   		= $(PATH_OBJS)sushipp.tab.o
OBJS_COMP	  		= $(PATH_OBJS)SppCompiler.o
OBJS_SCANNER  		= $(PATH_OBJS)sushipp.yy.o
OBJS_SETTINGS 		= $(PATH_OBJS)CompilerSettings.o $(PATH_OBJS)BuiltInFunctions.o
OBJS_UTIL	  		= $(PATH_OBJS)util.o
OBJS_INFERENCE      = $(PATH_OBJS)TypeSymbol.o $(PATH_OBJS)TypeSymbolTable.o $(PATH_OBJS)Types.o $(PATH_OBJS)InferenceExceptions.o $(PATH_OBJS)TypeGen.o
OBJS_SYMB	  		= $(PATH_OBJS)SymbolInfo.o
OBJS_ERRORS			= $(PATH_OBJS)ErrorItem.o $(PATH_OBJS)IOError.o $(PATH_OBJS)LexicalError.o $(PATH_OBJS)MemoryError.o $(PATH_OBJS)SemanticError.o $(PATH_OBJS)SyntaxError.o
OBJS_ERR_HANDLER	= $(PATH_OBJS)ErrorHandler.o
OBJS_CODEGEN		= $(PATH_OBJS)BasicBlock.o $(PATH_OBJS)Builder.o $(PATH_OBJS)FunctionBlock.o $(PATH_OBJS)Module.o $(PATH_OBJS)Value.o $(PATH_OBJS)Variable.o $(PATH_OBJS)Function.o $(PATH_OBJS)VariableManager.o $(PATH_OBJS)LabelManager.o $(PATH_OBJS)RemoveReferenceFlags.o

OBJS = $(OBJS_NODE_ALL) $(OBJS_AST) $(OBJS_MAIN) $(OBJS_VST) $(OBJS_PARSER) $(OBJS_SCANNER) $(OBJS_EXCEP) $(OBJS_COMP) $(OBJS_SETTINGS) $(OBJS_SYMB) $(OBJS_UTIL) $(OBJS_ERRORS) $(OBJS_ERR_HANDLER) $(OBJS_INFERENCE) $(OBJS_CODEGEN)

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
DEP_VISITORS			 = $(PATH_VISITOR)ASTVisitor.hpp $(PATH_VISITOR)PrintASTVisitor.hpp $(PATH_VISITOR)FunctionTableVisitor.hpp $(PATH_VISITOR)SymbolTableVisitor.hpp $(PATH_VISITOR)CodeGenVisitor.hpp $(PATH_VISITOR)TypeInferenceVisitor.hpp
DEP_AST 				 = $(PATH_AST)AbstractSyntaxTree.hpp $(DEP_ASTNODE_SHALLOW)
DEP_AST_ALL  			 = $(DEP_ASTNODE_DEEP) $(PATH_AST)AbstractSyntaxTree.hpp
DEP_AST_ALL_VISITOR      = $(DEP_AST_ALL) $(DEP_VISITORS)
DEP_ERRORS				 = $(PATH_ERRORS)ErrorItem.hpp $(PATH_ERRORS)IOError.hpp $(PATH_ERRORS)LexicalError.hpp $(PATH_ERRORS)MemoryError.hpp $(PATH_ERRORS)SemanticError.hpp $(PATH_ERRORS)SyntaxError.hpp

DEP_SYMB				 = $(PATH_SYMB)ScopeNode.hpp $(PATH_SYMB)SymbolTable.hpp $(PATH_SYMB)SymbolInfo.hpp
DEP_COMP				 = SppCompiler.hpp
DEP_EXCEP				 = $(PATH_EXCEP)Exceptions.hpp
DEP_SETTINGS			 = $(PATH_SETTINGS)CompilerSettings.hpp $(PATH_SETTINGS)BuiltInFunctions.hpp
DEP_INFERENCE			 = $(PATH_INFERENCE)TypeSymbolTable.hpp $(PATH_INFERENCE)TypeSymbol.hpp $(PATH_INFERENCE)Types.hpp $(PATH_INFERENCE)InferenceExceptions.hpp $(PATH_INFERENCE)TypeGen.hpp

# compilation and linking flags #
CC = clang++
DEBUG = -g
CCFLAGS = -c --std=c++11 $(DEBUG)
LDFLAGS =
EXE = sushipp
BISON_FLAGS = -d -b $(PATH_PARSER)$(EXE) -v
LLVM_FLAGS = `llvm-config --cxxflags --ldflags --system-libs --libs core`
TARGETS = sushipp

###########################################################

all: $(TARGETS)

sushipp: $(OBJS)
	$(CC) $(OBJS) -o $(EXE) $(LDFLAGS)

# Main #
$(PATH_OBJS)main.o: main.cpp $(PATH_PARSER)sushipp.tab.h $(DEP_AST) $(DEP_EXCEP) $(DEP_COMP) $(DEP_SETTINGS) $(DEP_SYMB)
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

$(PATH_OBJS)NT_Declaration.o: $(PATH_NONTERMINAL)NT_Declaration.cpp $(DEP_ASTNODE_DEEP_VISITOR) $(PATH_INFERENCE)Types.hpp
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)Constant.o: $(PATH_NONTERMINAL)Constant.cpp $(DEP_ASTNODE_DEEP_VISITOR)
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)NT_Functioncall.o: $(PATH_NONTERMINAL)NT_FunctionCall.cpp $(DEP_ASTNODE_DEEP_VISITOR)
	$(CC) $< -o $@ $(CCFLAGS)

# Tokens #
$(PATH_OBJS)Token.o: $(PATH_TOKENS)Token.cpp $(DEP_ASTNODE_DEEP_VISITOR)
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)ConstantToken.o: $(PATH_TOKENS)ConstantToken.cpp $(DEP_ASTNODE_DEEP_VISITOR)
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)Keyword.o: $(PATH_TOKENS)Keyword.cpp $(DEP_ASTNODE_DEEP_VISITOR) $(PATH_INFERENCE)Types.hpp
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)Operator.o: $(PATH_TOKENS)Operator.cpp $(DEP_ASTNODE_DEEP_VISITOR)
	$(CC) $< -o $@ $(CCFLAGS)


# Exceptions #
$(PATH_OBJS)Exceptions.o: $(PATH_EXCEP)Exceptions.cpp $(PATH_EXCEP)Exceptions.hpp
	$(CC) $< -o $@ $(CCFLAGS)

# Visitor #
$(PATH_OBJS)PrintASTVisitor.o: $(PATH_VISITOR)PrintASTVisitor.cpp $(DEP_VISITORS) $(DEP_ASTNODE_DEEP)
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)SymbolTableVisitor.o: $(PATH_VISITOR)SymbolTableVisitor.cpp $(DEP_VISITORS) $(DEP_ASTNODE_DEEP) $(DEP_SYMB) $(DEP_EXCEP) $(DEP_ERRORS) $(PATH_SETTINGS)BuiltInFunctions.hpp
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)FunctionTableVisitor.o: $(PATH_VISITOR)FunctionTableVisitor.cpp $(DEP_VISITORS) $(DEP_ASTNODE_DEEP) $(DEP_SYMB) $(PATH_SETTINGS)BuiltInFunctions.hpp
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)TypeInferenceVisitor.o: $(PATH_VISITOR)TypeInferenceVisitor.cpp $(DEP_VISITORS) $(DEP_INFERENCE) $(DEP_SYMB) $(DEP_ERRORS) $(PATH_SETTINGS)BuiltInFunctions.hpp
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)CodeGenVisitor.o: $(PATH_VISITOR)CodeGenVisitor.cpp $(DEP_VISITORS) $(DEP_ASTNODE_DEEP) $(PATH_CODEGEN)LabelManager.hpp $(PATH_SETTINGS)BuiltInFunctions.hpp
	$(CC) $< -o $@ $(CCFLAGS)


# Compiler #
$(PATH_OBJS)SppCompiler.o: SppCompiler.cpp SppCompiler.hpp $(DEP_AST_ALL_VISITOR) $(DEP_EXCEP) $(DEP_SETTINGS) $(PATH_PARSER)sushipp.tab.h $(DEP_SYMB) $(PATH_ERRORS)ErrorHandler.hpp
	$(CC) $< -o $@ $(CCFLAGS)

# Settings #
$(PATH_OBJS)CompilerSettings.o: $(PATH_SETTINGS)CompilerSettings.cpp $(PATH_SETTINGS)CompilerSettings.hpp $(PATH_EXCEP)Exceptions.hpp
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)BuiltInFunctions.o: $(PATH_SETTINGS)BuiltInFunctions.cpp $(PATH_SETTINGS)BuiltInFunctions.hpp $(PATH_INFERENCE)Types.hpp
	$(CC) $< -o $@ $(CCFLAGS)

# Symbols #
$(PATH_OBJS)SymbolInfo.o: $(PATH_SYMB)SymbolInfo.cpp $(PATH_SYMB)SymbolInfo.hpp $(PATH_UTIL)util.hpp
	$(CC) $< -o $@ $(CCFLAGS)

# Util #
$(PATH_OBJS)util.o: $(PATH_UTIL)util.cpp $(PATH_UTIL)util.hpp
	$(CC) $< -o $@ $(CCFLAGS)

# ErrorHandler #
$(PATH_OBJS)ErrorHandler.o: $(PATH_ERRORS)ErrorHandler.cpp $(PATH_ERRORS)ErrorHandler.hpp $(DEP_ERRORS) $(PATH_SETTINGS)CompilerSettings.hpp $(DEP_EXCEP)
	$(CC) $< -o $@ $(CCFLAGS)

# ErrorItem(s) #
$(PATH_OBJS)ErrorItem.o: $(PATH_ERRORS)ErrorItem.cpp $(PATH_ERRORS)ErrorItem.hpp
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)IOError.o: $(PATH_ERRORS)IOError.cpp $(PATH_ERRORS)IOError.hpp $(PATH_ERRORS)ErrorItem.hpp
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)LexicalError.o: $(PATH_ERRORS)LexicalError.cpp $(PATH_ERRORS)LexicalError.hpp $(PATH_ERRORS)ErrorItem.hpp
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)MemoryError.o: $(PATH_ERRORS)MemoryError.cpp $(PATH_ERRORS)MemoryError.hpp $(PATH_ERRORS)ErrorItem.hpp
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)SemanticError.o: $(PATH_ERRORS)SemanticError.cpp $(PATH_ERRORS)SemanticError.hpp $(PATH_ERRORS)ErrorItem.hpp
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)SyntaxError.o: $(PATH_ERRORS)SyntaxError.cpp $(PATH_ERRORS)SyntaxError.hpp $(PATH_ERRORS)ErrorItem.hpp
	$(CC) $< -o $@ $(CCFLAGS)

# Inference #
$(PATH_OBJS)TypeSymbolTable.o: $(PATH_INFERENCE)TypeSymbolTable.cpp $(DEP_INFERENCE)
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)TypeSymbol.o: $(PATH_INFERENCE)TypeSymbol.cpp $(PATH_INFERENCE)TypeSymbol.hpp $(PATH_INFERENCE)Types.hpp  $(PATH_UTIL)util.hpp $(PATH_INFERENCE)TypeGen.hpp
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)Types.o: $(PATH_INFERENCE)Types.cpp $(PATH_INFERENCE)Types.hpp $(PATH_UTIL)util.hpp
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)InferenceExceptions.o: $(PATH_INFERENCE)InferenceExceptions.cpp $(DEP_INFERENCE)
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)TypeGen.o: $(PATH_INFERENCE)TypeGen.cpp $(DEP_INFERENCE)
	$(CC) $< -o $@ $(CCFLAGS)

# Code Generation #
$(PATH_OBJS)BasicBlock.o: $(PATH_CODEGEN)BasicBlock.cpp $(PATH_CODEGEN)BasicBlock.hpp $(PATH_CODEGEN)Variable.hpp $(PATH_CODEGEN)VariableManager.hpp $(PATH_CODEGEN)Value.hpp
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)Builder.o: $(PATH_CODEGEN)Builder.cpp $(PATH_CODEGEN)Builder.hpp $(PATH_CODEGEN)Module.hpp $(PATH_CODEGEN)VariableManager.hpp
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)FunctionBlock.o: $(PATH_CODEGEN)FunctionBlock.cpp $(PATH_CODEGEN)FunctionBlock.hpp $(PATH_CODEGEN)VariableManager.hpp $(PATH_CODEGEN)BasicBlock.hpp
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)Module.o: $(PATH_CODEGEN)Module.cpp $(PATH_CODEGEN)Module.hpp $(PATH_CODEGEN)FunctionBlock.hpp $(PATH_CODEGEN)VariableManager.hpp $(PATH_SETTINGS)BuiltInFunctions.hpp $(PATH_UTIL)util.hpp
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)Value.o: $(PATH_CODEGEN)Value.cpp $(PATH_CODEGEN)Value.hpp
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)Variable.o: $(PATH_CODEGEN)Variable.cpp $(PATH_CODEGEN)Variable.hpp $(PATH_CODEGEN)Value.hpp
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)Function.o: $(PATH_CODEGEN)Function.cpp $(PATH_CODEGEN)Function.hpp $(PATH_CODEGEN)Value.hpp $(PATH_CODEGEN)Variable.hpp
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)VariableManager.o: $(PATH_CODEGEN)VariableManager.cpp $(PATH_CODEGEN)VariableManager.hpp
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)LabelManager.o: $(PATH_CODEGEN)LabelManager.cpp $(PATH_CODEGEN)LabelManager.hpp
	$(CC) $< -o $@ $(CCFLAGS)

$(PATH_OBJS)RemoveReferenceFlags.o: $(PATH_CODEGEN)RemoveReferenceFlags.cpp $(PATH_CODEGEN)RemoveReferenceFlags.hpp
	$(CC) $< -o $@ $(CCFLAGS)

###########################################################

# clean
clean:
	rm -f obj/*.o
	rm -f sushipp
	rm -f $(PATH_PARSER)*.output

clean-hard: clean
	rm -f $(PATH_SCANNER)sushipp.yy.c
	rm -f $(PATH_PARSER)sushipp.tab.c $(PATH_PARSER)sushipp.tab.h
	touch $(PATH_PARSER)spp_parser.y $(PATH_SCANNER)spp_scanner.lex
# DO NOT DELETE
