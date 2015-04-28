#include <cstddef> // nullptr
#include <iostream> // cerr, endl
#include <stdexcept> // exception

#include "llvm/IR/Verifier.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

using namespace visitor;

int main(int argc, char** argv)
{
	CodeGenVisitor visitor;

	return EXIT_SUCCESS;
}
