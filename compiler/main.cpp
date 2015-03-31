#include "parser/sushipp.tab.h"

int main(int argc, char** argv)
{
	if(yyparse() == 0)
		cout << "Sucessful parsing" << endl;
	return 0;
}