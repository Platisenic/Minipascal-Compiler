#include "Nodes/constant.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

ConstantNode::ConstantNode(
    int _line_number, 
    int _col_number, 
    enumType _type,
    const_union _value) : ASTNodeBase{_line_number, _col_number},
    value(_value),
    type(_type)
    {}

void ConstantNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}

void ConstantNode::visitChildNodes(AstNodeVisitor &p_visitor){
    //do nothing
}

const std::string ConstantNode::getConstantValueCString() const {
    std::string ret_str;
    switch(type)
    {
        case Type_int:     ret_str =  "int";    break;
        case Type_void:    ret_str =  "void";   break;
        case Type_real:    ret_str =  "real";   break;
        case Type_string:  ret_str =  "string"; break;
        default: ret_str = "Unknown";
    }
    return ret_str;
}

const std::string ConstantNode::getValueCString() const {
    std::string ret_str;
    switch(type)
    {
        case Type_int:     ret_str =  std::to_string(value.val);    break;
        case Type_void:    ret_str =  "void";   break;
        case Type_real:    ret_str =  std::to_string(value.dval);   break;
        case Type_string:  ret_str =  std::string(value.text); break;
        default: ret_str = "Unknown";
    }
    return ret_str;
}

