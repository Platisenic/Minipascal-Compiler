#include "Nodes/binary_operator.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

BinaryOperatorNode::BinaryOperatorNode(
    int _line_number,
    int _col_number,
    enumOperator _op,
    Node _left_operand,
    Node _right_operand) : ASTNodeBase{_line_number, _col_number},
    op(_op),
    left_operand(_left_operand),
    right_operand(_right_operand)
    {}

void BinaryOperatorNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}

void BinaryOperatorNode::visitChildNodes(AstNodeVisitor &p_visitor){
    left_operand->accept(p_visitor);
    right_operand->accept(p_visitor);
    
    
}

const std::string BinaryOperatorNode::getOpCString() const {
    std::string ret_str;
    switch(op)
    {
        case OP_ASSIGN: ret_str =  ":=";  break;
        case OP_ADD:    ret_str =  "+";     break;
        case OP_SUB:    ret_str =  "-";     break;
        case OP_MUL:    ret_str =  "*";     break;
        case OP_DIV:    ret_str =  "/";     break;
        case OP_LT:     ret_str =  "<";      break;
        case OP_GT:     ret_str =  ">";      break;
        case OP_EQ:     ret_str =  "=";      break;
        case OP_GET:    ret_str =  ">=";     break;
        case OP_LET:    ret_str =  "<=";     break;
        case OP_NEQ:    ret_str =  "!=";     break;
        case OP_AND:    ret_str =  "and";     break;
        case OP_OR:     ret_str =  "or";      break;
        case OP_NOT:    ret_str =  "not";     break;
    }
    return ret_str;
}
