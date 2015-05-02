#include <sstream>

#include "FunctionBlock.hpp"

using namespace codegen;
using namespace std;

FunctionBlock::FunctionBlock(VariableManager& vm) : var_manager(vm)
{
    BasicBlock entry(vm, "entry");
    blocks.push_back(entry);
}

FunctionBlock::FunctionBlock(VariableManager& vm, string _name, string _return_type) : var_manager(vm), name(_name), return_type(_return_type)
{
    BasicBlock entry(vm, "entry");
    blocks.push_back(entry);
}

void FunctionBlock::dump(ostream& out) const
{
    out << "define" << " " << return_type << " @" << name << "(" << str_arguments() << ")" << "{" << endl;
    for(auto block = blocks.begin() ; block != blocks.end() ; ++block){
        block->dump(out);
        out << endl;
    }
    cout << "}" << endl;
}

void FunctionBlock::add_block(BasicBlock& block)
{
    blocks.push_back(block);
}

std::string FunctionBlock::get_name() const
{
    return name;
}

string FunctionBlock::str_arguments() const
{
    stringstream ss;
    for(auto arg = arguments.begin() ; arg != arguments.end() ; ++arg)
        ss << arg->first << ", %" << arg->second;
    return ss.str();
}

BasicBlock& FunctionBlock::get_block(int n)
{
    return blocks[n];
}
