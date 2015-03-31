
/*
 * AST.hpp
 *
 * Author: Floriane Magera, Fabrice Servais, Romain Mormont
 */

#ifndef AST_HPP_DEFINED
#define AST_HPP_DEFINED

#include <vector>

namespace ast{
	
	class NodeLocation;
	
	namespace nodes{
	
		class ASTNode;
		namespace nonterminals{
			
			class NonTerminal;
			
			namespace nt_declaration{
				
				class NT_Declaration;
				class Declaration;
				class DeclFunc;
				class DeclVars;
				class DeclVar;
				class ParamList;
				class Param;
			
			}
		
			namespace nt_expression{
				
				class NT_Expression;
				class Expression;
				class IncrExpression;
				class Assignment;
				class ModifyingExpression;
				class AssignableExpression;
				class DatastructureAccess;
				
							
			}
			
			namespace nt_functioncall{
				
				class NT_FunctionCall;
				class FuncCall;
				class ArgList;
				class Argument;
				class BracedFuncCall;
				class FuncCallEol;
				class ArgListEol;
				class SoyExpression;
				class SoyFunc;
				
						
			}
			
			namespace nt_programs{
			
				class NT_Program;
				class Program;
				class ScopeBody;
				class ProgramElement;
				class Scope;
								
			}
			
			namespace nt_statement{
			
				class NT_Statement;
				class Statement;
				class Return;
				class Menu;
				class MenuDef;
				class Loop;
				class Roll;
				class Foreach;
				class For;
				class ForInitializer;
				class ForUpdate;
				class Conditional;
				class Elseif;				
						
			}
			
			namespace nt_datastructure{
				
				class NT_Datastructure;
				class Datastructure;
				class Array;
				class List;
				class Tuple;
				class MakeSequence;
				class MakeSequenceList;
				class MakeSequenceArray;
				class SeqExpression;			
			}
			
			namespace nt_constant{
				
				class NT_Constant;
				class Constant;
			}
						
		
		}
		
		namespace tokens{
			
			class Token; 
			namespace constants{
				class ConstantToken;
				class String;
				class Character;
				class Integer;
				class Float;
				class Bool;			
			}
			
			namespace keywords{
				
				class Keyword;
				class Maki;
				class Nori;
				class Soy;
				class For;
				class Foreach;
				class To;
				class Menu;
				class If;
				class Elseif;
				class Else;
				class Roll;
				class Continue;
				class Break;
				class As;
				class Type_Int;
				class Type_Float;
				class Type_Bool;
				class Type_Char;
				class Type_String;
				class Type_Array;
				class Type_List;
				class Type_Tuple;
			}
			
			namespace operators{
				class Operator;
				class Op_Plus;
				class Op_Minus;
				class Op_Mult;
				class Op_Div;
				class Op_Modulo;
				class Op_Exponentiation;
				class Op_UnaryMinus;
				class Op_BitwiseOr;
				class Op_BitwiseAnd;
				class Op_BitwiseXor;
				class Op_BitwiseNot;
				class Op_LogicalOr;
				class Op_LogicalAnd;
				class Op_LogicalNot;
				class Op_CompLessThan;
				class Op_CompGreaterThan;
				class Op_CompLessEqual;
				class Op_CompGreaterEqual;
				class Op_CompEqual;
				class Op_CompNotEqual;
				class Op_LeftShift;
				class Op_RightShift;
				class Op_StringConcat;
				class Op_PrefixIncrement;
				class Op_PrefixDecrement;
				class Op_PostfixIncrement;
				class Op_PostfixDecrement;
				class Op_Assignment;
				class Op_AssignPlus;
				class Op_AssignLess;
				class Op_AssignMult;
				class Op_AssignDiv;
				class Op_AssignExpo;
				class Op_AssignMod;
				class Op_AssignAnd;
				class Op_AssignOr;
				class Op_AssignXor;
				class Op_AssignConcat;
				
				
				
				
				
			
			}
			namespace delimiters {
				
				class Delimiter;
				class Delimeol;
				class Delimeos;
				class TupleBeg;
				class TupleEnd;
				class ArrayBeg;
				class ArrayEnd;
				class Virg;
				class Arrow;
				class OpenPar;
				class ClosingPar;
				class OpenAcc;
				class ClosingAcc;
				class Underscore;
				class OpenBrace;
				class ClosingBrace;
							
			}
		}	
	}
	



}


#endif /* AST_HPP_DEFINED */