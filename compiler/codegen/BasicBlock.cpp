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


void BasicBlock::add_line(std::string line)
{
    lines.push_back(line);
}



Value BasicBlock::create_op_plus(Value& lhs, Value& rhs)
{
    // Create temp variables
    string temp_name = var_manager.get_last_occurence("tempadd");

    string type = lhs.str_type();
    if(type != rhs.str_type()){
        cout << "[ERROR] " << endl;
        throw 0;
    }


    Variable ret(temp_name, type);

    stringstream ss;
    ss << ret.str_value() << " = " << "add" << " " << type << " " << lhs.str_value() << ", " << rhs.str_value();

    lines.push_back(ss.str());

    return ret;
}

Value BasicBlock::create_op_minus(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_mult(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_div(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_mod(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_expon(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_unminus(Value& value)
{

}

Value BasicBlock::create_op_bit_or(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_bit_and(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_bit_xor(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_bit_not(Value& value)
{

}

Value BasicBlock::create_op_log_or(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_log_and(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_log_not(Value& value)
{

}

Value BasicBlock::create_op_cmp_lt(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_cmp_gt(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_cmp_le(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_cmp_ge(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_cmp_eq(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_cmp_neq(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_left_shift(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_right_shift(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_str_conc(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_pref_incr(Value& value)
{

}

Value BasicBlock::create_op_pref_decr(Value& value)
{

}

Value BasicBlock::create_op_post_incr(Value& value)
{

}

Value BasicBlock::create_op_post_decr(Value& value)
{

}

Value BasicBlock::create_op_assign(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_assign_plus(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_assign_minus(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_assign_mult(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_assign_div(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_assign_expo(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_assign_mod(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_assign_and(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_assign_or(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_assign_xor(Value& lhs, Value& rhs)
{

}

Value BasicBlock::create_op_assign_concat(Value& lhs, Value& rhs)
{

}

#endif
