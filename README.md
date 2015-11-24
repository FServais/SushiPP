# Sushi++ 

The Sushi++ language is a strongly and statically typed language. Nevertheless, to alleviate the
programmer's work, the type system is made as unobtrusive as possible and types are inferred during compilation. 

## Variables

To declare a variable, one can use the keyword `maki` followed by the variable name and the assigned value.

```
maki a = 2
maki a = 3, b = 5, c = 18

```

## Authors
- Floriane Magera (flomage2612)
- Romain Mormont (Waliens)
- Fabrice Servais (FServais)

## Types 

As said, the type system is made as unobtrusive as possible. The only presence of types in the language is the function parameters hinting mechanism : see 'Functions' section.

The available types are the following : 

* `bool` : _true_ or _false_
* `char` : a character
* `int` : an signed integer on 32 bits
* `float` : a single-precision floating point value on 32 bits
* `array` : an array of elements
* `list` : a list of elements
* `string` : a string 
* `function` : a function
* `void` : return type for fonction that doesn't return anything

## Datastructures

### Array

#### Principles

The array type represents a sequence of elements having a given type T and that are stored sequentially in the memory. This structure has the same behaviour as a vector data structure in terms of complexity. The Sushi++ arrays cannot store any type of data, T can only be one among : `int`, `float`, `char`, `string`, `bool`. The index of an array starts at 0. Arrays are passed to functions and returned by reference (they are never copied).

#### Syntax

The array syntax is the following : 

```
maki arr = #[ 1, 2, 3, 4 ]#
maki str_arr = #[ "str1", "str2", "str3", "str4" ]#
maki a = #[ true, false ]#
```

The array can be accessed and modified as follows :

```
maki first_element = arr[0]
arr[0] = 5
```

#### Memory

Arrays are heap-allocated and their memory is managed at runtime with a garbage collector. 

### Lists

#### Principles

List are very similar to arrays in terms of supported types, parameter passing, memory handling,... 

#### Syntax

```
maki arr = { 1, 2, 3, 4 }
maki str_arr = { "str1", "str2", "str3", "str4" }
maki a = { true, false }
```

## Operations

The Sushi++ language supports a large set of operations that can be performed either on variables or literals. 

![Operators](https://github.com/FServais/SushiPP/raw/master/ops.png "Operators")

## Conditionals

The language provides conditions statements similarly to other languages like C. A conditional begins with an if control statement, optionally followed by elseif or else statements.

```
if "expression"
	"scope"
elseif "expression"
	"scope"
else "expression"
	"scope"
;;
```

The Sushi++ also support a switch-like control flow structure indicated by the keyword `menu`. A certain expression is evaluated : each case denotes an expression and some instructions to perform if the expression of the case matches the value which is evaluated. The default case is denoted by an underscore.

```
menu "expression"
	"expression" -> "scope" ;;
	"expression" -> "scope" ;;
	_ -> "scope" ;;
;;
```

## Loops 

### Condition-controlled loop 

This loop is called roll and behaves like a C while loop. The scope containing this code fragment is delimited by the end of line following the condition and the scope delimiter `;;`. The condition must be an expression of type bool, otherwise the compiler will return a type
error. The syntax is the following :

```
roll "condition"
	"roll scope"
;;
```

### Counter-controlled loop 

This loop is called for and behaves like a C for loop. Again, the condition must be an expression of type bool. Moreover, the initializer and update part must contain a modifying expressions (assignment or increment). The syntax is the following :

```
for "init expression", "condition", "update expression"
	"for scope"
;;
```

### Collection-controlled loop 

This loop is called foreach and is made for iterating over lists. At the first iteration, the element at the front of the list is stored in the iteration variable. Then, at each iteration, the same goes for next value till the list was completely covered. The syntax is the following :

```
foreach "list expression" as "variable"
	"foreach scope"
;;
```

## Functions

# Compiler

This repository contains the implementation of a compiler for the Sushi++ language. It is implemented in C++.
