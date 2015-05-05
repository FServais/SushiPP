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
    // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_add", lhs.get_type());

    // generate code
    stringstream ss;
    if(lhs.get_type()->equals(typegen::Float))
        ss << ret->str_value() << " = " << "fadd" << " " << lhs.str_type() << " " << lhs.str_value() << ", " << rhs.str_value();
    else
        ss << ret->str_value() << " = " << "add" << " " << lhs.str_type() << " " << lhs.str_value() << ", " << rhs.str_value();

    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_minus(Value& lhs, Value& rhs)
{
    // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_sub", lhs.get_type());

    // generate code
    stringstream ss;
    if(lhs.get_type()->equals(typegen::Float))
        ss << ret->str_value() << " = " << "fsub" << " " << lhs.str_type() << " " << lhs.str_value() << ", " << rhs.str_value();
    else
        ss << ret->str_value() << " = " << "add" << " " << lhs.str_type() << " " << lhs.str_value() << ", " << rhs.str_value();

    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_mult(Value& lhs, Value& rhs)
{
    // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_mul", lhs.get_type());

    // generate code
    stringstream ss;
    if(lhs.get_type()->equals(typegen::Float))
        ss << ret->str_value() << " = " << "fmul" << " " << lhs.str_type() << " " << lhs.str_value() << ", " << rhs.str_value();
    else
        ss << ret->str_value() << " = " << "mul" << " " << lhs.str_type() << " " << lhs.str_value() << ", " << rhs.str_value();

    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_div(Value& lhs, Value& rhs)
{

    // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_div", lhs.get_type());

    // generate code
    stringstream ss;
    if(lhs.get_type()->equals(typegen::Float))
        ss << ret->str_value() << " = " << "fdiv" << " " << lhs.str_type() << " " << lhs.str_value() << ", " << rhs.str_value();
    else
        ss << ret->str_value() << " = " << "sdiv" << " " << lhs.str_type() << " " << lhs.str_value() << ", " << rhs.str_value();

    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_mod(Value& lhs, Value& rhs)
{
    // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_mod", lhs.get_type());

    // generate code
    stringstream ss;
    ss << ret->str_value() << " = " << "srem" << " " << lhs.str_type() << " " << lhs.str_value() << ", " << rhs.str_value();

    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_expon(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_unminus(Value& value)
{
    // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_unmin", value.get_type());

    // generate code
    stringstream ss;
    if(value.get_type()->equals(typegen::Float))
        ss << ret->str_value() << " = " << "fsub" << " " << value.str_type() << " " << value.str_value() << ", 1";
    else
        ss << ret->str_value() << " = " << "sub" << " " << value.str_type() << " " << value.str_value() << ", 1";
    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_bit_or(Value& lhs, Value& rhs)
{
    // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_orb", lhs.get_type());

    // generate code
    stringstream ss;
    ss << ret->str_value() << " = " << "or" << " " << lhs.str_type() << " " << lhs.str_value() << ", " << rhs.str_value();

    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_bit_and(Value& lhs, Value& rhs)
{
    // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_andb", lhs.get_type());

    // generate code
    stringstream ss;
    ss << ret->str_value() << " = " << "and" << " " << lhs.str_type() << " " << lhs.str_value() << ", " << rhs.str_value();

    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_bit_xor(Value& lhs, Value& rhs)
{
     // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_xorb", lhs.get_type());

    // generate code
    stringstream ss;
    ss << ret->str_value() << " = " << "xor" << " " << lhs.str_type() << " " << lhs.str_value() << ", " << rhs.str_value();

    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_bit_not(Value& value)
{
     // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_not", value.get_type());

    // generate code
    stringstream ss;
    ss << ret->str_value() << " = " << "xor" << " " << value.str_type() << " " << value.str_value() << ", -1";

    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_log_or(Value& lhs, Value& rhs)
{
    // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_orl", lhs.get_type());

    // generate code
    stringstream ss;
    ss << ret->str_value() << " = " << "or" << " " << lhs.str_type() << " " << lhs.str_value() << ", " << rhs.str_value();

    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_log_and(Value& lhs, Value& rhs)
{
    // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_andl", lhs.get_type());

    // generate code
    stringstream ss;
    ss << ret->str_value() << " = " << "and" << " " << lhs.str_type() << " " << lhs.str_value() << ", " << rhs.str_value();

    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_log_not(Value& value)
{
    // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_orb", lhs.get_type());

    // generate code
    stringstream ss;
    ss << ret->str_value() << " = " << "xor" << " " << value.str_type() << " " << value.str_value() << ", -1";

    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_cmp_lt(Value& lhs, Value& rhs)
{
    return create_op_cmp_gt(rhs, lhs);
}

Value* BasicBlock::create_op_cmp_gt(Value& lhs, Value& rhs)
{

    Variable* ret = new Variable(var_manager, "tmp_gt", shared_ptr<typegen::Bool>(new typegen::Bool()));

    stringstream ss;
    ss << ret->str_value() << " = " << "icmp sgt" << " " << lhs.str_type() << " " << lhs.str_value() << ", " << rhs.str_value();

    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_cmp_le(Value& lhs, Value& rhs)
{
    Variable* ret = new Variable(var_manager, "tmp_le", shared_ptr<typegen::Bool>(new typegen::Bool()));

    stringstream ss;
    ss << ret->str_value() << " = " << "icmp sle" << " " << lhs.str_type() << " " << lhs.str_value() << ", " << rhs.str_value();

    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_cmp_ge(Value& lhs, Value& rhs)
{
    return create_op_cmp_le(rhs, lhs);
}

Value* BasicBlock::create_op_cmp_eq(Value& lhs, Value& rhs)
{
    Variable* ret = new Variable(var_manager, "tmp_eq", shared_ptr<typegen::Bool>(new typegen::Bool()));

    stringstream ss;
    if(lhs.get_type()->equals(typegen::Float))
        ss << ret->str_value() << " = " << "fcmp oeq" << " " << lhs.str_type() << " " << lhs.str_value() << ", " << rhs.str_value();
    else
        ss << ret->str_value() << " = " << "icmp eq" << " " << lhs.str_type() << " " << lhs.str_value() << ", " << rhs.str_value();

    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_cmp_neq(Value& lhs, Value& rhs)
{
    Variable* ret = new Variable(var_manager, "tmp_ne", shared_ptr<typegen::Bool>(new typegen::Bool()));

    stringstream ss;
    if(lhs.get_type()->equals(typegen::Float))
        ss << ret->str_value() << " = " << "fcmp une" << " " << lhs.str_type() << " " << lhs.str_value() << ", " << rhs.str_value();
    else
        ss << ret->str_value() << " = " << "icmp ne" << " " << lhs.str_type() << " " << lhs.str_value() << ", " << rhs.str_value();
    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_left_shift(Value& lhs, Value& rhs)
{
    Variable* ret = new Variable(var_manager, "tmp_sl", lhs.get_type());

    stringstream ss;
    ss << ret->str_value() << " = " << "shl" << " " << lhs.str_type() << " " << lhs.str_value() << ", " << rhs.str_value();
    
    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_right_shift(Value& lhs, Value& rhs)
{
    Variable* ret = new Variable(var_manager, "tmp_sr", lhs.get_type());

    stringstream ss;
    ss << ret->str_value() << " = " << "shr" << " " << lhs.str_type() << " " << lhs.str_value() << ", " << rhs.str_value();
    
    lines.push_back(ss.str());

    return ret;
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
    //Variable& value_cast = dynamic_cast<Variable&>(value);
    Variable& variable_cast = dynamic_cast<Variable&>(variable);

    stringstream ss;
    ss << "store " << value.str_type() << " " << value.str_value() << ", " << variable_cast.str_type() << "* " << variable_cast.str_value();

    add_line(ss.str());

    //Variable& variable_cast = dynamic_cast<Variable&>(variable);
    Variable* variable_ptr = new Variable(variable_cast);

    return variable_ptr;
}

Value* BasicBlock::create_load(Value& ptr)
{
    Variable& ptr_var = dynamic_cast<Variable&>(ptr);

    stringstream tempname;
    tempname << "tmp_load_" << ptr_var.get_name();

    Variable* variable_ptr = new Variable(var_manager, tempname.str(), ptr_var.str_type());

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

    Variable* var_ptr = new Variable(var_manager, ptrname.str(), var.get_type());

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
