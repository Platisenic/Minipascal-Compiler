#include "Nodes/while.hpp"
#include <iostream>
#include <cstdlib>
#include <string>


WhileNode::WhileNode(
    int _line_number,
    int _col_number,
    Node _condition, 
    Node _body):ASTNodeBase{_line_number, _col_number},
    condition(_condition),
    body(_body)
    {}

void WhileNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}

void WhileNode::visitChildNodes(AstNodeVisitor &p_visitor) {
    condition->accept(p_visitor);
    body->accept(p_visitor);
}
