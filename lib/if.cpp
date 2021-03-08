#include "Nodes/if.hpp"
#include <iostream>
#include <cstdlib>
#include <string>


IfNode::IfNode(
    int _line_number, 
    int _col_number, 
    Node _condition, 
    Node _body_then,
    Node _body_else) : ASTNodeBase{_line_number, _col_number},
    condition(_condition),
    body_then(_body_then),
    body_else(_body_else)
    {}

void IfNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}

void IfNode::visitChildNodes(AstNodeVisitor &p_visitor) {
    condition->accept(p_visitor);
    if(body_then)
        body_then->accept(p_visitor);
    if(body_else)
        body_else->accept(p_visitor);
}
