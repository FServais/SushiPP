#include "BuiltInFunctions.hpp"

using namespace settings;
using namespace std;
using namespace inference;

BuiltInFunctions::BuiltInFunctions()
{
	/** Array functions */ 
	insert_function("array-size-bool", 		{ "array" }, { ARRAY }, INT, BOOL, ARRAY_RUNTIME);
	insert_function("array-size-int", 		{ "array" }, { ARRAY }, INT, INT, ARRAY_RUNTIME);
	insert_function("array-size-float", 	{ "array" }, { ARRAY }, INT, FLOAT, ARRAY_RUNTIME);
	insert_function("array-size-char", 		{ "array" }, { ARRAY }, INT, CHAR, ARRAY_RUNTIME);
	insert_function("array-size-string", 	{ "array" }, { ARRAY }, INT, STRING, ARRAY_RUNTIME);
	insert_function("array-empty-bool", 	{ "array" }, { ARRAY }, BOOL, BOOL, ARRAY_RUNTIME);
	insert_function("array-empty-int", 		{ "array" }, { ARRAY }, BOOL, INT, ARRAY_RUNTIME);
	insert_function("array-empty-float", 	{ "array" }, { ARRAY }, BOOL, FLOAT, ARRAY_RUNTIME);
	insert_function("array-empty-char", 	{ "array" }, { ARRAY }, BOOL, CHAR, ARRAY_RUNTIME);
	insert_function("array-empty-string", 	{ "array" }, { ARRAY }, BOOL, STRING, ARRAY_RUNTIME);
	insert_function("array-clear-bool", 	{ "array" }, { ARRAY }, VOID, BOOL, ARRAY_RUNTIME);
	insert_function("array-clear-int", 		{ "array" }, { ARRAY }, VOID, INT, ARRAY_RUNTIME);
	insert_function("array-clear-float", 	{ "array" }, { ARRAY }, VOID, FLOAT, ARRAY_RUNTIME);
	insert_function("array-clear-char", 	{ "array" }, { ARRAY }, VOID, CHAR, ARRAY_RUNTIME);
	insert_function("array-clear-string", 	{ "array" }, { ARRAY }, VOID, STRING, ARRAY_RUNTIME);
	insert_function("array-push-bool", 		{ "array", "elem" }, { ARRAY, BOOL }, VOID, BOOL, ARRAY_RUNTIME);
	insert_function("array-push-int", 		{ "array", "elem" }, { ARRAY, INT }, VOID, INT, ARRAY_RUNTIME);
	insert_function("array-push-float", 	{ "array", "elem" }, { ARRAY, FLOAT }, VOID, FLOAT, ARRAY_RUNTIME);
	insert_function("array-push-char", 		{ "array", "elem" }, { ARRAY, CHAR }, VOID, CHAR, ARRAY_RUNTIME);
	insert_function("array-push-string", 	{ "array", "elem" }, { ARRAY, STRING }, VOID, STRING, ARRAY_RUNTIME);
	insert_function("array-pop-bool", 		{ "array" }, { ARRAY }, BOOL, BOOL, ARRAY_RUNTIME);
	insert_function("array-pop-int", 		{ "array" }, { ARRAY }, INT, INT, ARRAY_RUNTIME);
	insert_function("array-pop-float", 		{ "array" }, { ARRAY }, FLOAT, FLOAT, ARRAY_RUNTIME);
	insert_function("array-pop-char", 		{ "array" }, { ARRAY }, CHAR, CHAR, ARRAY_RUNTIME);
	insert_function("array-pop-string", 	{ "array" }, { ARRAY }, STRING, STRING, ARRAY_RUNTIME);
	insert_function("array-get-bool", 		{ "array", "pos" }, { ARRAY, INT }, BOOL, BOOL, ARRAY_RUNTIME);
	insert_function("array-get-int", 		{ "array", "pos" }, { ARRAY, INT }, INT, INT, ARRAY_RUNTIME);
	insert_function("array-get-float", 		{ "array", "pos" }, { ARRAY, INT }, FLOAT, FLOAT, ARRAY_RUNTIME);
	insert_function("array-get-char", 		{ "array", "pos" }, { ARRAY, INT }, CHAR, CHAR, ARRAY_RUNTIME);
	insert_function("array-get-string", 	{ "array", "pos" }, { ARRAY, INT }, STRING, STRING, ARRAY_RUNTIME);
	insert_function("array-set-bool", 		{ "array", "pos", "elem" }, { ARRAY, INT, BOOL }, VOID, BOOL, ARRAY_RUNTIME);
	insert_function("array-set-int", 		{ "array", "pos", "elem" }, { ARRAY, INT, INT }, VOID, INT, ARRAY_RUNTIME);
	insert_function("array-set-float", 		{ "array", "pos", "elem" }, { ARRAY, INT, FLOAT }, VOID, FLOAT, ARRAY_RUNTIME);
	insert_function("array-set-char", 		{ "array", "pos", "elem" }, { ARRAY, INT, CHAR }, VOID, CHAR, ARRAY_RUNTIME);
	insert_function("array-set-string", 	{ "array", "pos", "elem" }, { ARRAY, INT, STRING }, VOID, STRING, ARRAY_RUNTIME);
	insert_function("array-insert-bool", 	{ "array", "pos", "elem" }, { ARRAY, INT, BOOL }, VOID, BOOL, ARRAY_RUNTIME);
	insert_function("array-insert-int", 	{ "array", "pos", "elem" }, { ARRAY, INT, INT }, VOID, INT, ARRAY_RUNTIME);
	insert_function("array-insert-float", 	{ "array", "pos", "elem" }, { ARRAY, INT, FLOAT }, VOID, FLOAT, ARRAY_RUNTIME);
	insert_function("array-insert-char", 	{ "array", "pos", "elem" }, { ARRAY, INT, CHAR }, VOID, CHAR, ARRAY_RUNTIME);
	insert_function("array-insert-string", 	{ "array", "pos", "elem" }, { ARRAY, INT, STRING }, VOID, STRING, ARRAY_RUNTIME);
	insert_function("array-remove-bool", 	{ "array", "pos" }, { ARRAY, INT }, BOOL, BOOL, ARRAY_RUNTIME);
	insert_function("array-remove-int", 	{ "array", "pos" }, { ARRAY, INT }, INT, INT, ARRAY_RUNTIME);
	insert_function("array-remove-float", 	{ "array", "pos" }, { ARRAY, INT }, FLOAT, FLOAT, ARRAY_RUNTIME);
	insert_function("array-remove-char", 	{ "array", "pos" }, { ARRAY, INT }, CHAR, CHAR, ARRAY_RUNTIME);
	insert_function("array-remove-string", 	{ "array", "pos" }, { ARRAY, INT }, STRING, STRING, ARRAY_RUNTIME);

	/** List functions */
	insert_function("list-size-bool", 			{ "list" }, { LIST }, INT, BOOL, LIST_RUNTIME);
	insert_function("list-size-int", 			{ "list" }, { LIST }, INT, INT, LIST_RUNTIME);
	insert_function("list-size-float", 			{ "list" }, { LIST }, INT, FLOAT, LIST_RUNTIME);
	insert_function("list-size-char", 			{ "list" }, { LIST }, INT, CHAR, LIST_RUNTIME);
	insert_function("list-size-string", 		{ "list" }, { LIST }, INT, STRING, LIST_RUNTIME);
	insert_function("list-empty-bool", 			{ "list" }, { LIST }, BOOL, BOOL, LIST_RUNTIME);
	insert_function("list-empty-int", 			{ "list" }, { LIST }, BOOL, INT, LIST_RUNTIME);
	insert_function("list-empty-float", 		{ "list" }, { LIST }, BOOL, FLOAT, LIST_RUNTIME);
	insert_function("list-empty-char", 			{ "list" }, { LIST }, BOOL, CHAR, LIST_RUNTIME);
	insert_function("list-empty-string", 		{ "list" }, { LIST }, BOOL, STRING, LIST_RUNTIME);
	insert_function("list-clear-bool", 			{ "list" }, { LIST }, VOID, BOOL, LIST_RUNTIME);
	insert_function("list-clear-int", 			{ "list" }, { LIST }, VOID, INT, LIST_RUNTIME);
	insert_function("list-clear-float", 		{ "list" }, { LIST }, VOID, FLOAT, LIST_RUNTIME);
	insert_function("list-clear-char", 			{ "list" }, { LIST }, VOID, CHAR, LIST_RUNTIME);
	insert_function("list-clear-string", 		{ "list" }, { LIST }, VOID, STRING, LIST_RUNTIME);
	insert_function("list-front-bool", 			{ "list" }, { LIST }, BOOL, BOOL, LIST_RUNTIME);
	insert_function("list-front-int", 			{ "list" }, { LIST }, INT, INT, LIST_RUNTIME);
	insert_function("list-front-float", 		{ "list" }, { LIST }, FLOAT, FLOAT, LIST_RUNTIME);
	insert_function("list-front-char", 			{ "list" }, { LIST }, CHAR, CHAR, LIST_RUNTIME);
	insert_function("list-front-string", 		{ "list" }, { LIST }, STRING, STRING, LIST_RUNTIME);
	insert_function("list-back-bool", 			{ "list" }, { LIST }, BOOL, BOOL, LIST_RUNTIME);
	insert_function("list-back-int", 			{ "list" }, { LIST }, INT, INT, LIST_RUNTIME);
	insert_function("list-back-float", 			{ "list" }, { LIST }, FLOAT, FLOAT, LIST_RUNTIME);
	insert_function("list-back-char", 			{ "list" }, { LIST }, CHAR, CHAR, LIST_RUNTIME);
	insert_function("list-back-string", 		{ "list" }, { LIST }, STRING, STRING, LIST_RUNTIME);
	insert_function("list-pop-front-bool", 		{ "list" }, { LIST }, BOOL, BOOL, LIST_RUNTIME);
	insert_function("list-pop-front-int", 		{ "list" }, { LIST }, INT, INT, LIST_RUNTIME);
	insert_function("list-pop-front-float", 	{ "list" }, { LIST }, FLOAT, FLOAT, LIST_RUNTIME);
	insert_function("list-pop-front-char", 		{ "list" }, { LIST }, CHAR, CHAR, LIST_RUNTIME);
	insert_function("list-pop-front-string", 	{ "list" }, { LIST }, STRING, STRING, LIST_RUNTIME);
	insert_function("list-pop-back-bool", 		{ "list" }, { LIST }, BOOL, BOOL, LIST_RUNTIME);
	insert_function("list-pop-back-int", 		{ "list" }, { LIST }, INT, INT, LIST_RUNTIME);
	insert_function("list-pop-back-float", 		{ "list" }, { LIST }, FLOAT, FLOAT, LIST_RUNTIME);
	insert_function("list-pop-back-char", 		{ "list" }, { LIST }, CHAR, CHAR, LIST_RUNTIME);
	insert_function("list-pop-back-string", 	{ "list" }, { LIST }, STRING, STRING, LIST_RUNTIME);
	insert_function("list-push-front-bool", 	{ "list", "elem" }, { LIST, BOOL }, VOID, BOOL, LIST_RUNTIME);
	insert_function("list-push-front-int", 		{ "list", "elem" }, { LIST, INT }, VOID, INT, LIST_RUNTIME);
	insert_function("list-push-front-float", 	{ "list", "elem" }, { LIST, FLOAT }, VOID, FLOAT, LIST_RUNTIME);
	insert_function("list-push-front-char", 	{ "list", "elem" }, { LIST, CHAR }, VOID, CHAR, LIST_RUNTIME);
	insert_function("list-push-front-string", 	{ "list", "elem" }, { LIST, STRING }, VOID, STRING, LIST_RUNTIME);
	insert_function("list-push-back-bool", 		{ "list", "elem" }, { LIST, BOOL }, VOID, BOOL, LIST_RUNTIME);
	insert_function("list-push-back-int", 		{ "list", "elem" }, { LIST, INT }, VOID, INT, LIST_RUNTIME);
	insert_function("list-push-back-float", 	{ "list", "elem" }, { LIST, FLOAT }, VOID, FLOAT, LIST_RUNTIME);
	insert_function("list-push-back-char", 		{ "list", "elem" }, { LIST, CHAR }, VOID, CHAR, LIST_RUNTIME);
	insert_function("list-push-back-string", 	{ "list", "elem" }, { LIST, STRING }, VOID, STRING, LIST_RUNTIME);
	insert_function("list-get-bool", 			{ "list", "pos" }, { LIST, INT }, BOOL, BOOL, LIST_RUNTIME);
	insert_function("list-get-int", 			{ "list", "pos" }, { LIST, INT }, INT, INT, LIST_RUNTIME);
	insert_function("list-get-float", 			{ "list", "pos" }, { LIST, INT }, FLOAT, FLOAT, LIST_RUNTIME);
	insert_function("list-get-char", 			{ "list", "pos" }, { LIST, INT }, CHAR, CHAR, LIST_RUNTIME);
	insert_function("list-get-string", 			{ "list", "pos" }, { LIST, INT }, STRING, STRING, LIST_RUNTIME);
	insert_function("list-insert-bool", 		{ "list", "pos", "elem" }, { LIST, INT, BOOL }, VOID, BOOL, LIST_RUNTIME);
	insert_function("list-insert-int", 			{ "list", "pos", "elem" }, { LIST, INT, INT }, VOID, INT, LIST_RUNTIME);
	insert_function("list-insert-float", 		{ "list", "pos", "elem" }, { LIST, INT, FLOAT }, VOID, FLOAT, LIST_RUNTIME);
	insert_function("list-insert-char", 		{ "list", "pos", "elem" }, { LIST, INT, CHAR }, VOID, CHAR, LIST_RUNTIME);
	insert_function("list-insert-string", 		{ "list", "pos", "elem" }, { LIST, INT, STRING }, VOID, STRING, LIST_RUNTIME);
	insert_function("list-remove-bool", 		{ "list", "pos" }, { LIST, INT }, BOOL, BOOL, LIST_RUNTIME);
	insert_function("list-remove-int", 			{ "list", "pos" }, { LIST, INT }, INT, INT, LIST_RUNTIME);
	insert_function("list-remove-float", 		{ "list", "pos" }, { LIST, INT }, FLOAT, FLOAT, LIST_RUNTIME);
	insert_function("list-remove-char", 		{ "list", "pos" }, { LIST, INT }, CHAR, CHAR, LIST_RUNTIME);
	insert_function("list-remove-string", 		{ "list", "pos" }, { LIST, INT }, STRING, STRING, LIST_RUNTIME);

	/** Print functions */
	insert_function("print-bool", 	{ "to_print" }, { BOOL }, VOID, NO_TYPE, SUPPORT);
	insert_function("print-int", 	{ "to_print" }, { INT }, VOID, NO_TYPE, SUPPORT);
	insert_function("print-float", 	{ "to_print" }, { FLOAT }, VOID, NO_TYPE, SUPPORT);
	insert_function("print-char", 	{ "to_print" }, { CHAR }, VOID, NO_TYPE, SUPPORT);
	insert_function("print-string", { "to_print" }, { STRING }, VOID, NO_TYPE, SUPPORT);

	/** String functions */
	insert_function("string-len", 		{ "str" }, { STRING }, INT, NO_TYPE, STRING_RUNTIME);
	insert_function("string-reverse", 	{ "str" }, { STRING }, STRING, NO_TYPE, STRING_RUNTIME);
	insert_function("string-tolower", 	{ "str" }, { STRING }, STRING, NO_TYPE, STRING_RUNTIME);
	insert_function("string-toupper", 	{ "str" }, { STRING }, STRING, NO_TYPE, STRING_RUNTIME);

	/** Math functions */
	insert_function("pow-int", { "base", "exp" }, { INT, INT }, INT, NO_TYPE, SUPPORT);
	insert_function("pow-float", { "base", "exp" }, { FLOAT, INT }, FLOAT, NO_TYPE, SUPPORT);
}

void BuiltInFunctions::insert_function(const string& name, 
									   const vector<string>& param_names,
									   const vector<ShallowType>& param_types, 
									   ShallowType ret_type,
									   ShallowType ds_type = NO_TYPE,
									   Runtime runtime = SUPPORT)
{
	(*this)[name] = make_tuple(name, param_names, param_types, ret_type, ds_type, runtime);
}