#include "Nodes/unary_operator.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

UnaryOperatorNode::UnaryOperatorNode(
    int _line_number,
    int _col_number,
    enumOperator _op,
    Node _operand) :ASTNodeBase{_line_number, _col_number},
    op(_op),
    operand(_operand)
    {}

void UnaryOperatorNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}

void UnaryOperatorNode::visitChildNodes(AstNodeVisitor &p_visitor) {
    operand->accept(p_visitor);
}

const std::string UnaryOperatorNode::getOpCString() const {
    std::string ret_str;
    switch(op)
    {
        case OP_ASSIGN: ret_str =  "ASSIGN";  break;
        case OP_ADD:    ret_str =  "ADD";     break;
        case OP_SUB:    ret_str =  "SUB";     break;
        case OP_MUL:    ret_str =  "MUL";     break;
        case OP_DIV:    ret_str =  "DIV";     break;
        case OP_LT:     ret_str =  "LT";      break;
        case OP_GT:     ret_str =  "GT";      break;
        case OP_EQ:     ret_str =  "EQ";      break;
        case OP_GET:    ret_str =  "GET";     break;
        case OP_LET:    ret_str =  "LET";     break;
        case OP_NEQ:    ret_str =  "NEQ";     break;
        case OP_AND:    ret_str =  "AND";     break;
        case OP_OR:     ret_str =  "OR";      break;
        case OP_NOT:    ret_str =  "NOT";     break;
    }
    return ret_str;
}