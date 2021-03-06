#include <sstream>
#include <regex>
#include <numeric>

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

FunctionBlock::FunctionBlock(VariableManager& vm, string _name, shared_ptr<typegen::Function> _func_type)
  : var_manager(vm), name(_name), function_type(_func_type), parameters_name(_func_type->nb_param())
{
    BasicBlock entry(vm, "entry");
    blocks.push_back(entry);
    generate_argument_type_conv();
}

FunctionBlock::FunctionBlock(VariableManager& vm,
                             string _name,
                             shared_ptr<typegen::Function> _func_type,
                             const vector<string>& _param_names)
  : var_manager(vm), name(_name), function_type(_func_type), parameters_name(_param_names)
{
    BasicBlock entry(vm, "entry");
    blocks.push_back(entry);
    generate_argument_type_conv();
}

void FunctionBlock::dump(ostream& out) const
{
    out << "define" << " " << function_type->get_ret_type()->to_str() << " @" << name << "(" << str_arguments() << ")" << "{" << endl;
    for(auto block = blocks.begin() ; block != blocks.end() ; ++block){
        block->dump(out);
        out << endl;
    }

    if(function_type->get_ret_type()->is_void())
        out << "\tret void" << endl;
    else
        out << "\tret " << function_type->get_ret_type()->to_str() << " 0" << endl;
    //out << "\tret " << function_type->get_ret_type()->to_str() << " " << return_value << endl;
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

string FunctionBlock::get_name() const
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
                return type->to_str() + " %" + param;
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

vector<string> FunctionBlock::arguments_signature()
{
  vector<string> sigs;

  for(size_t i = 0; i < function_type->nb_param(); ++i)
    sigs.push_back(function_type->get_arg(i)->to_str());

  return sigs;
}

string FunctionBlock::str_return_signature()
{
  return function_type->get_ret_type()->to_str();
}

void FunctionBlock::generate_argument_type_conv()
{
  BasicBlock& entry = get_last_block();

  for(size_t i = 0; i < parameters_name.size(); ++i)
  {
    // Change the name of the argument -> goal is to get pointer to its value
    stringstream newname;
    newname << parameters_name[i] << "_arg";

    // Allocate in memory to get a pointer
    Variable pointer(var_manager, parameters_name[i], function_type->get_arg(i), true);
    unique_ptr<Value> alloc(entry.create_decl_var(pointer));

    // Add to the list of arguments
    parameters_name[i] = newname.str();

    // Store the value given in argument where is the pointer
    Variable value(var_manager, newname.str(), function_type->get_arg(i), true);

    unique_ptr<Value> store(entry.create_store(value, pointer));
  }
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


string FunctionBlock::get_signature() const
{
    stringstream ss;
    ss << function_type->get_ret_type()->to_str() << " @" << name << "(" << str_arguments_signature() << ")";

    return ss.str();
}
