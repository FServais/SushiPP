#include "PrintASTVisitor.hpp"

using namespace std;

// Constructor
PrintASTVisitor::PrintASTVisitor() : length_line(5) { }


PrintASTVisitor::visit( ast::Token& token )
{
	int depth = token.depth();
	string tab_line = string(depth * length_line, "-") + "˧";
	cout << tab_line << " <" << token.node_name() << " ; " << token.id() << ">" << endl;
}


PrintASTVisitor::visit( ast::NonTerminal& nonterminal)
{
	int depth = nonterminal.depth();
	string tab_line = string(depth * length_line, "-") + "˧";
	cout << tab_line << " (" << nonterminal.node_name() << ")" << endl;
}
