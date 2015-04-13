== Sushi++ Compiler ==

At this stage, the lexer/parser part is not fully functionnal. 

What is implemented and tested : 

- AST management : many classes for representing the nodes, an abstract syntax tree class
- Visitor pattern : the base abstract class for the visitor is implemented as well as a concrete printer visitor
- Grammar : was tested before adding the construction of the abstract syntax tree and 
- Error management : using the bison errors with custom location management (still some bug with the column count)

What is not implemented or does not work yet : 

- memory management : as we deal with an union in bison, we have to use pointers to objects as fields. The memory reclaiming is not node at all resulting in huge memory leaks. 
- error management : parsing errors often cause segfaults
- grammar with construction : while the grammar was working when we didn't perform actions on the rules, adding the construction of the tree seems to have change its behavior which doesn't parse some files syntactically valid (maybe we changed some rule while adding the rule, which was not intended of course)

Nevertheless, the parser succeeds at outputting the tree form some valid programs given in this archive. Moreover, as the AST management and the visitor pattern are implemented we can start the semantic analysis while debugging the parser.

== File organization ==

The root folder contains the following packages :

* compiler : contains the code, a Makefile for compiling the project, the bison and flex files,...
	- ast : contains the abstract syntax tree classes 
	- scanner : the Flex file + the flex output code *.yy.c 
	- parser : the Bison file + the bison output code *.tab.c *.tab.h
* sample_code : Sushi+ programs that are either parsed successfully (prefix 'work_') or output a parsing error without crashing the compiler (preifx 'error_')
* sample_code/alloc_error : Sushi++ programs that cause segfault when parsed


