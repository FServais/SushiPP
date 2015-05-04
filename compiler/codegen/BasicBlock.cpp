#ifndef BASIC_BLOCK_TREE_HPP_DEFINED
#define BASIC_BLOCK_TREE_HPP_DEFINED

#include <iostream>
#include <sstream>

#include "BasicBlock.hpp"
#include "Variable.hpp"

using namespace std;
using namespace codegen;

BasicBlock::BasicBlock(VariableManager& vm, string _label) : var_manager(vm), label(_label)
{

}

void BasicBlock::dump(std::ostream& out) const
{
    out << label << ':' << endl;
    for(auto line = lines.begin() ; line != lines.end() ; ++line )
        out << "\t" << *line << endl;
}




Value* BasicBlock::create_op_plus(Value& lhs, Value& rhs)
{
    // Create temp variables
    string temp_name = var_manager.insert_variable("tmp_add");

    string type = lhs.str_type();

    if(type != rhs.str_type()){
        cout << "[ERROR] " << endl;
        throw 0;
    }

    Variable* ret = new Variable(temp_name, type);

    stringstream ss;

    ss << ret->str_value() << " = " << "add" << " " << type << " " << lhs.str_value() << ", " << rhs.str_value();

    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_minus(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_mult(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_div(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_mod(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_expon(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_unminus(Value& value)
{

}

Value* BasicBlock::create_op_bit_or(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_bit_and(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_bit_xor(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_bit_not(Value& value)
{

}

Value* BasicBlock::create_op_log_or(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_log_and(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_log_not(Value& value)
{

}

Value* BasicBlock::create_op_cmp_lt(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_cmp_gt(Value& lhs, Value& rhs)
{
    // Create temp variables
    string temp_name = var_manager.insert_variable("tmp_gt");

    string type = lhs.str_type();

    if(type != rhs.str_type()){
        cout << "[ERROR] " << endl;
        throw 0;
    }

    Variable* ret = new Variable(temp_name, "i1");

    stringstream ss;

    ss << ret->str_value() << " = " << "icmp sgt" << " " << type << " " << lhs.str_value() << ", " << rhs.str_value();

    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_cmp_le(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_cmp_ge(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_cmp_eq(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_cmp_neq(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_left_shift(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_right_shift(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_str_conc(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_pref_incr(Value& value)
{

}

Value* BasicBlock::create_op_pref_decr(Value& value)
{

}

Value* BasicBlock::create_op_post_incr(Value& value)
{

}

Value* BasicBlock::create_op_post_decr(Value& value)
{

}

Value* BasicBlock::create_op_assign(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_assign_plus(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_assign_minus(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_assign_mult(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_assign_div(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_assign_expo(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_assign_mod(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_assign_and(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_assign_or(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_assign_xor(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_assign_concat(Value& lhs, Value& rhs)
{

}


Value* BasicBlock::create_decl_var(Value& value)
{
    Variable& var = dynamic_cast<Variable&>(value);
    stringstream ss;
    ss << var.str_value() << " = " << "alloca " << var.str_type();

    add_line(ss.str());

    Variable* var_ptr = new Variable(var);

    return var_ptr;
}

Value* BasicBlock::create_assign(Value& lhs, Value& rhs)
{
    stringstream ss;
    ss << lhs.str_value() << " = " << rhs.str_value();

    add_line(ss.str());

    Value* val_ptr = new Value(lhs);

    return val_ptr;
}

Value* BasicBlock::create_store(Value& value, Value& variable)
{
    stringstream ss;
    ss << "store " << value.str_type() << " " << value.str_value() << ", " << variable.str_type() << "* " << variable.str_value();

    add_line(ss.str());

    Value* variable_ptr = new Value(variable);

    return variable_ptr;
}

Value* BasicBlock::create_load(Value& ptr)
{
    Variable& ptr_var = dynamic_cast<Variable&>(ptr);

    stringstream tempname;
    tempname << "tmp_load_" << ptr_var.get_name();

    Variable* variable_ptr = new Variable(tempname.str(), ptr_var.str_type());

    stringstream ss;
    ss << variable_ptr->str_value() << " = load " << variable_ptr->str_type() << "* " <<  ptr_var.str_value();

    add_line(ss.str());

    return variable_ptr;
}


Value* BasicBlock::create_get_pointer(Value& variable)
{
    Variable& var = dynamic_cast<Variable&>(variable);

    stringstream ptrname;
    ptrname << var.get_name() << "_ptr";

    Variable* var_ptr = new Variable(ptrname.str(), var.get_type());

    stringstream ss;
    ss << var_ptr->str_value() << " = getelementptr " << var_ptr->str_type() << "* " << var.str_value() << ", i32 0";

    add_line(ss.str());

    return var_ptr;
}


void BasicBlock::create_branch(string label)
{
    stringstream ss;
    ss << "br label %" << label;

    add_line(ss.str());
}

void BasicBlock::create_cond_branch(Value& cond, std::string label_true, std::string label_false)
{
    Variable& cond_var = dynamic_cast<Variable&>(cond);

    stringstream ss;
    ss << "br " << cond_var.str_type() << " " << cond_var.str_value() << ", label %" << label_true << ", label %" << label_false;

    add_line(ss.str());
}


void BasicBlock::add_line(std::string line)
{
    lines.push_back(line);
}


#endif
