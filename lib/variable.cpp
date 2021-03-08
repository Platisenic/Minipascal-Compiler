#include "Nodes/variable.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

VariableNode::VariableNode(
    int _line_number, 
    int _col_number, 
    std::string _variable_name,
    type_inf* _type) : ASTNodeBase{_line_number, _col_number},
    variable_name(_variable_name),
    type(_type){}

std::string VariableNode::getType()
{
    std::string ret_type;
    switch(type.s_type)
    {
        case Type_int   :  ret_type = "int"; break;
        case Type_real  :  ret_type = "real"; break;
        case Type_string:  ret_type = "string"; break;
        default: ret_type = "Unknown";
    }
    ret_type += " ";
    for(auto &p : type.dimensions){
        ret_type += "[";
        ret_type += std::to_string(p.first);
        ret_type += ",";
        ret_type += std::to_string(p.second);
        ret_type += "]";
    }
    return ret_type;
}

void VariableNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}

void VariableNode::visitChildNodes(AstNodeVisitor &p_visitor) {
    //do nothing
}

const std::string VariableNode::getNameCString()  {
    return variable_name;
}
const std::string VariableNode::getTypeCString()  {
    return this->getType();
}