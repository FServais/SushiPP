#include <sstream>
#include <regex>

#include "FunctionBlock.hpp"
#include "Variable.hpp"

using namespace codegen;
using namespace std;
using namespace typegen;

FunctionBlock::FunctionBlock(VariableManager& vm) : var_manager(vm), name(""), return_type(nullptr)
{
    BasicBlock entry(vm, "entry");
    blocks.push_back(entry);
}

FunctionBlock::FunctionBlock(VariableManager& vm, string _name, shared_ptr<Type> _return_type) : var_manager(vm), name(_name), return_type(_return_type)
{
    BasicBlock entry(vm, "entry");
    blocks.push_back(entry);
}

void FunctionBlock::dump(ostream& out) const
{
    out << "define" << " " << return_type->to_str() << " @" << name << "(" << str_arguments() << ")" << "{" << endl;
    for(auto block = blocks.begin() ; block != blocks.end() ; ++block){
        block->dump(out);
        out << endl;
    }
    cout << "\tret " << return_type->to_str() << " " << return_value << endl;
    cout << "}" << endl;
}

void FunctionBlock::dump_declaration(ostream& out) const
{
    out << "declare" << " " << return_type->to_str() << " @" << name << "(" << str_arguments_signature() << ")" << endl;
}

void FunctionBlock::add_block(BasicBlock& block)
{
    blocks.push_back(block);
}

void FunctionBlock::add_block(string block_label)
{
    BasicBlock block(var_manager, block_label);
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
        ss << arg->first->to_str() << " %" << arg->second;
        if(arg != arguments.end()-1)
            ss << ", ";
    }
    return ss.str();
}


string FunctionBlock::str_arguments_signature() const
{
    stringstream ss;
    for(auto arg = arguments.begin() ; arg != arguments.end() ; ++arg)
    {
        ss << arg->first->to_str();
        if(arg != arguments.end()-1)
            ss << ", ";
    }
    return ss.str();
}


void FunctionBlock::add_argument(shared_ptr<Type> type, string name)
{
    pair<shared_ptr<Type>,string> argument(type,name);
    /*
    stringstream newname;
    newname << name << "_arg";

    BasicBlock& entry = get_last_block();

    Variable arg(newname.str(), type);
    unique_ptr<Value> up = unique_ptr<Value>(entry.create_get_pointer(arg));

    Variable lhs(name, type);
    unique_ptr<Value> assign = unique_ptr<Value>(entry.create_assign_value(lhs, *up));

    arguments.push_back(make_pair(type,newname.str()));
    */

    // Change the name of the argument -> goal is to get pointer to its value
    stringstream newname;
    newname << name << "_arg";

    BasicBlock& entry = get_last_block();

    // Allocate in memory to get a pointer
    Variable pointer(var_manager, name, type, true);
    unique_ptr<Value> alloc = unique_ptr<Value>(entry.create_decl_var(pointer));

    // Add to the list of arguments
    arguments.push_back(make_pair(type,newname.str()));

    // Store the value given in argument where is the pointer
    Variable value(var_manager, newname.str(), type);

    unique_ptr<Value> store = unique_ptr<Value>(entry.create_store(value, pointer));

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


std::string FunctionBlock::get_signature() const
{
    stringstream ss;
    ss << return_type->to_str() << " @" << name << "(" << str_arguments_signature() << ")";

    return ss.str();
}
