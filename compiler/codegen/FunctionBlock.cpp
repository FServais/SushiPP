#include <sstream>
#include <regex>

#include "FunctionBlock.hpp"
#include "Variable.hpp"

using namespace codegen;
using namespace std;
using namespace typegen;

// FunctionBlock::FunctionBlock(VariableManager& vm) : var_manager(vm), name(""), return_type(nullptr)
// {
//     BasicBlock entry(vm, "entry");
//     blocks.push_back(entry);
// }

FunctionBlock::FunctionBlock(VariableManager& vm, std::string _name, std::shared_ptr<typegen::Function> _func_type)
  : var_manager(vm), name(_name), function_type(_func_type), parameters_name(_func_type->nb_param())
{
    BasicBlock entry(vm, "entry");
    blocks.push_back(entry); 
}

FunctionBlock::FunctionBlock(VariableManager& vm, 
                             std::string _name, 
                             std::shared_ptr<typegen::Function> _func_type, 
                             const std::vector<std::string>& _param_names)
  : var_manager(vm), name(_name), function_type(_func_type), parameters_name(_param_names)  
{
    BasicBlock entry(vm, "entry");
    blocks.push_back(entry); 
}

void FunctionBlock::dump(ostream& out) const
{
    out << "define" << " " << function_type->get_ret_type()->to_str() << " @" << name << "(" << str_arguments() << ")" << "{" << endl;
    for(auto block = blocks.begin() ; block != blocks.end() ; ++block){
        block->dump(out);
        out << endl;
    }
    out << "\tret " << function_type->get_ret_type()->to_str() << " " << return_value << endl;
    out << "}" << endl;
}

void FunctionBlock::dump_declaration(ostream& out) const
{
    out << "declare" << " " << function_type->get_ret_type()->to_str() << " @" << name << "(" << str_arguments_signature() << ")" << endl;
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
    if(parameters_name.empty())
        return "";

    vector<string> str_args;
    transform(parameters_name.begin(), 
              parameters_name.end(), 
              function_type->get_params().begin(),
              back_inserter(str_args),
              [](const string& param, shared_ptr<typegen::Type> type)
              { 
                return type->to_str() + " " + param;
              });

    return accumulate(next(str_args.begin()), str_args.end(), str_args[0],
                      [](const string& acc, const string& param)
                      {
                        return acc + ", " + param;
                      });
}

string FunctionBlock::str_arguments_signature() const
{
    stringstream ss;

    for(size_t i = 0; i < function_type->nb_param(); ++i)
    {
        if(i > 0)
            ss << ", ";
        ss << function_type->get_arg(i)->to_str();
    }
    
    return ss.str();
}

// void FunctionBlock::add_argument(shared_ptr<Type> type, string name)
// {
//     pair<shared_ptr<Type>,string> argument(type,name);
//     /*
//     stringstream newname;
//     newname << name << "_arg";

//     BasicBlock& entry = get_last_block();

//     Variable arg(newname.str(), type);
//     unique_ptr<Value> up = unique_ptr<Value>(entry.create_get_pointer(arg));

//     Variable lhs(name, type);
//     unique_ptr<Value> assign = unique_ptr<Value>(entry.create_assign_value(lhs, *up));

//     arguments.push_back(make_pair(type,newname.str()));
//     */

//     // Change the name of the argument -> goal is to get pointer to its value
//     stringstream newname;
//     newname << name << "_arg";

//     BasicBlock& entry = get_last_block();

//     // Allocate in memory to get a pointer
//     Variable pointer(var_manager, name, type, true);
//     unique_ptr<Value> alloc = unique_ptr<Value>(entry.create_decl_var(pointer));

//     // Add to the list of arguments
//     arguments.push_back(make_pair(type,newname.str()));

//     // Store the value given in argument where is the pointer
//     Variable value(var_manager, newname.str(), type);

//     unique_ptr<Value> store = unique_ptr<Value>(entry.create_store(value, pointer));

// }

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
    ss << function_type->get_ret_type()->to_str() << " @" << name << "(" << str_arguments_signature() << ")";

    return ss.str();
}
