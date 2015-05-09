#include <iostream>
#include <sstream>

#include "BasicBlock.hpp"
#include "Variable.hpp"
#include "Function.hpp"

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
    string function(lhs.get_type()->is_float() ? "fadd " : "add ");
    lines.push_back(make_binop(function + lhs.str_type(), lhs.str_value(), rhs.str_value(), ret->str_value()));

    return ret;
}

Value* BasicBlock::create_op_minus(Value& lhs, Value& rhs)
{
    // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_sub", lhs.get_type());

    // generate code
    string function(lhs.get_type()->is_float() ? "fsub " : "sub ");
    lines.push_back(make_binop(function + lhs.str_type(), lhs.str_value(), rhs.str_value(), ret->str_value()));

    return ret;
}

Value* BasicBlock::create_op_mult(Value& lhs, Value& rhs)
{
    // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_mul", lhs.get_type());

    // generate code
    string function(lhs.get_type()->is_float() ? "fmul " : "mul ");
    lines.push_back(make_binop(function + lhs.str_type(), lhs.str_value(), rhs.str_value(), ret->str_value()));

    return ret;
}

Value* BasicBlock::create_op_div(Value& lhs, Value& rhs)
{

    // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_div", lhs.get_type());

    // generate code
    string function(lhs.get_type()->is_float() ? "fdiv " : "div ");
    lines.push_back(make_binop(function + lhs.str_type(), lhs.str_value(), rhs.str_value(), ret->str_value()));

    return ret;
}

Value* BasicBlock::create_op_mod(Value& lhs, Value& rhs)
{
    // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_mod", lhs.get_type());

    // generate code
    stringstream ss;
    ss << ret->str_value() << " = srem" << " " << lhs.str_type() << " " << lhs.str_value() << ", " << rhs.str_value();

    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_expon(Value& lhs, Value& rhs)
{
    // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_expo", lhs.get_type());

    // generate code
    stringstream ss;
    if(lhs.get_type()->is_float())
        ss << ret->str_value() << " = call float (float, i64)* @pow_float (";
    else
        ss << ret->str_value() << " = call i64 (i64, i64)* @pow_int (";

    ss  << " " << lhs.str_type() << " " << lhs.str_value() << ", " << rhs.str_type() << " " << rhs.str_value() << ")";

    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_unminus(Value& value)
{
    // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_unmin", value.get_type());

    // generate code
    stringstream ss;
    if(value.get_type()->is_float())
        ss << ret->str_value() << " = fsub" << " " << value.str_type() << " " << value.str_value() << ", 1";
    else
        ss << ret->str_value() << " = sub" << " " << value.str_type() << " " << value.str_value() << ", 1";
    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_bit_or(Value& lhs, Value& rhs)
{
    // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_orb", lhs.get_type());

    // generate code
    lines.push_back(make_binop("or i64", lhs.str_value(), rhs.str_value(), ret->str_value()));

    return ret;
}

Value* BasicBlock::create_op_bit_and(Value& lhs, Value& rhs)
{
    // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_andb", lhs.get_type());

    // generate code
       lines.push_back(make_binop("and i64", lhs.str_value(), rhs.str_value(), ret->str_value()));

    return ret;
}

Value* BasicBlock::create_op_bit_xor(Value& lhs, Value& rhs)
{
     // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_xorb", lhs.get_type());

    // generate code
       lines.push_back(make_binop("xor i64", lhs.str_value(), rhs.str_value(), ret->str_value()));

    return ret;
}

Value* BasicBlock::create_op_bit_not(Value& value)
{
     // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_not", value.get_type());

    // generate code
    stringstream ss;
    ss << ret->str_value() << " = xor" << " " << value.str_type() << " " << value.str_value() << ", -1";

    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_log_or(Value& lhs, Value& rhs)
{
    // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_orl", lhs.get_type());

    // generate code
    lines.push_back(make_binop("or i1", lhs.str_value(), rhs.str_value(), ret->str_value()));

    return ret;
}

Value* BasicBlock::create_op_log_and(Value& lhs, Value& rhs)
{
    // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_andl", lhs.get_type());

    // generate code
    stringstream ss;
    ss << ret->str_value() << " = and" << " " << lhs.str_type() << " " << lhs.str_value() << ", " << rhs.str_value();

    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_log_not(Value& value)
{
    // create variable to contain the return value
    Variable* ret = new Variable(var_manager, "tmp_orb", value.get_type());

    // generate code
    stringstream ss;
    ss << ret->str_value() << " = xor" << " " << value.str_type() << " " << value.str_value() << ", 1";

    lines.push_back(ss.str());

    return ret;
}

Value* BasicBlock::create_op_cmp_lt(Value& lhs, Value& rhs)
{
    Variable* ret = new Variable(var_manager, "tmp_lt", shared_ptr<typegen::Bool>(new typegen::Bool()));

    string function = lhs.get_type()->is_float() ? "fcmp olt " : "icmp slt ";
    lines.push_back(make_binop(function + lhs.str_type(), lhs.str_value(), rhs.str_value(), ret->str_value()));

    return ret;
}

Value* BasicBlock::create_op_cmp_gt(Value& lhs, Value& rhs)
{
    return create_op_cmp_lt(rhs, lhs);
}

Value* BasicBlock::create_op_cmp_le(Value& lhs, Value& rhs)
{
    Variable* ret = new Variable(var_manager, "tmp_lt", shared_ptr<typegen::Bool>(new typegen::Bool()));

    string function = lhs.get_type()->is_float() ? "fcmp ole " : "icmp sle ";
    lines.push_back(make_binop(function + lhs.str_type(), lhs.str_value(), rhs.str_value(), ret->str_value()));

    return ret;
}

Value* BasicBlock::create_op_cmp_ge(Value& lhs, Value& rhs)
{
    return create_op_cmp_le(rhs, lhs);
}

Value* BasicBlock::create_op_cmp_eq(Value& lhs, Value& rhs)
{
    Variable* ret = new Variable(var_manager, "tmp_eq", shared_ptr<typegen::Bool>(new typegen::Bool()));

    string function = lhs.get_type()->is_float() ? "fcmp oeq " : "icmp eq ";
    lines.push_back(make_binop(function + lhs.str_type(), lhs.str_value(), rhs.str_value(), ret->str_value()));

    return ret;
}

Value* BasicBlock::create_op_cmp_neq(Value& lhs, Value& rhs)
{
    Variable* ret = new Variable(var_manager, "tmp_ne", shared_ptr<typegen::Bool>(new typegen::Bool()));
  
    string function = lhs.get_type()->is_float() ? "fcmp une " : "icmp ne ";
    lines.push_back(make_binop(function + lhs.str_type(), lhs.str_value(), rhs.str_value(), ret->str_value()));

    return ret;
}

Value* BasicBlock::create_op_left_shift(Value& lhs, Value& rhs)
{
    Variable* ret = new Variable(var_manager, "tmp_sl", lhs.get_type());

    lines.push_back(make_binop("shl i64", lhs.str_value(), rhs.str_value(), ret->str_value()));

    return ret;
}

Value* BasicBlock::create_op_right_shift(Value& lhs, Value& rhs)
{
    Variable* ret = new Variable(var_manager, "tmp_sr", lhs.get_type());

    lines.push_back(make_binop("shr i64", lhs.str_value(), rhs.str_value(), ret->str_value()));

    return ret;
}

Value* BasicBlock::create_op_str_conc(Value& lhs, Value& rhs)
{

}

Value* BasicBlock::create_op_pref_incr(Value& value)
{
    Variable* ret = new Variable(var_manager, "tmp_pref_incr", value.get_type());

    string function = value.get_type()->is_float() ? "fadd " : "add ",
           op2 = value.get_type()->is_float() ? "1.0" : "1";
    lines.push_back(make_binop(function + value.str_type(), value.str_value(), op2, ret->str_value()));

    return ret;
}

Value* BasicBlock::create_op_pref_decr(Value& value)
{
    Variable* ret = new Variable(var_manager, "tmp_pref_decr", value.get_type());

    string function = value.get_type()->is_float() ? "fsub " : "sub ",
           op2 = value.get_type()->is_float() ? "1.0" : "1";
    lines.push_back(make_binop(function + value.str_type(), value.str_value(), op2, ret->str_value()));

    return ret;
}

Value* BasicBlock::create_op_post_incr(Value& value)
{
    Variable* ret = new Variable(var_manager, "tmp_post_incr", value.get_type());

    string function = value.get_type()->is_float() ? "fadd " : "add ",
           op2 = value.get_type()->is_float() ? "1.0" : "1";
    lines.push_back(make_binop(function + value.str_type(), value.str_value(), op2, ret->str_value()));

    return ret;
}

Value* BasicBlock::create_op_post_decr(Value& value)
{
    Variable* ret = new Variable(var_manager, "tmp_post_decr", value.get_type());

    string function = value.get_type()->is_float() ? "fsub " : "sub ",
           op2 = value.get_type()->is_float() ? "1.0" : "1";
    lines.push_back(make_binop(function + value.str_type(), value.str_value(), op2, ret->str_value()));

    return ret;
}

Value* BasicBlock::create_op_assign(Value& lhs, Value& rhs)
{
    Variable* ret = new Variable(var_manager, "assign_tmp", rhs.get_type());

    string function = rhs.get_type()->is_float() ? "fadd " : "add ",
           op2 = rhs.get_type()->is_float() ? "0.0" : "0";
    lines.push_back(make_binop(function + rhs.str_type(), rhs.str_value(), op2, ret->str_value()));

    return ret;
}

Value* BasicBlock::create_decl_var(Value& value)
{
    Variable& var = dynamic_cast<Variable&>(value);
    stringstream ss;
    ss << var.str_value() << " = alloca " << var.str_type();

    add_line(ss.str());

    Variable* var_ptr = new Variable(var);

    return var_ptr;
}

Value* BasicBlock::create_assign_value(Value& lhs, Value& rhs)
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

    Variable* variable_ptr = new Variable(var_manager, tempname.str(), ptr_var.get_type());

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

Value* BasicBlock::create_func_call(Value& value)
{
    Function& function = dynamic_cast<Function&>(value);

    Variable* ret;

    stringstream ss;
    if(!function.get_return_type()->is_void())
    {
        ret = new Variable(var_manager, "ret", function.get_return_type());
        ss << ret->str_value() << " = ";
    }
    else
        ret = nullptr;

    ss << "call " << function.get_function_call();

    add_line(ss.str());

    return ret;
}


void BasicBlock::add_line(std::string line)
{
    lines.push_back(line);
}

std::string BasicBlock::make_binop(const std::string& func, const std::string& op1, const std::string& op2)
{
    stringstream ss;
    ss << func << " " << op1 << ", " << op2;
    return ss.str();
}

std::string BasicBlock::make_binop(const std::string& func, const std::string& op1, const std::string& op2, const std::string& ret)
{
    stringstream ss;
    ss << ret << " = " << make_binop(func, op1, op2);
    return ss.str();
}

std::string BasicBlock::add_expression(const std::string& expr, const std::string& ret)
{   
    string variable(var_manager.insert_variable(ret));
    lines.push_back("%" + variable + " = " + expr);
    return variable;
}

std::string BasicBlock::add_expression(const std::string& expr)
{
    lines.push_back(expr);
    return "";
}


