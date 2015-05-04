#include <sstream>
#include <regex>

#include "FunctionBlock.hpp"
#include "Variable.hpp"

using namespace codegen;
using namespace std;

FunctionBlock::FunctionBlock(VariableManager& vm) : var_manager(vm), name(""), return_type("void")
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
    cout << "\tret " << return_type << " " << return_value << endl;
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
    {
        ss << arg->first << " %" << arg->second;
        if(arg != arguments.end()-1)
            ss << ", ";
    }
    return ss.str();
}

void FunctionBlock::add_argument(string type, string name)
{
    pair<string,string> argument(type,name);

    stringstream newname;
    newname << name << "_arg";

    BasicBlock& entry = get_last_block();

    Variable arg(newname.str(), type);
    unique_ptr<Value> up = unique_ptr<Value>(entry.create_get_pointer(arg));

    Variable lhs(name, type);
    unique_ptr<Value> assign = unique_ptr<Value>(entry.create_assign(lhs, *up));

    arguments.push_back(make_pair(type,newname.str()));}
}

void FunctionBlock::set_return(string _return_value)
{
    return_value = _return_value;
}




BasicBlock& FunctionBlock::get_block(int n)
{
    return blocks[n];
}

BasicBlock& FunctionBlock::get_last_block()
{
    return get_block(blocks.size()-1);
}
