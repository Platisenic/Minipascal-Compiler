#include "Nodes/assignment.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include "Nodes/variable_ref.hpp"

AssignmentNode::AssignmentNode(
    int _line_number, 
    int _col_number, 
    Node _variable_node, 
    Node _expression_node) : ASTNodeBase{_line_number, _col_number},
    variable_node(_variable_node),
    expression_node(_expression_node)
    {
        ((VariableRefNode *)(variable_node))->isLeft = true;
    }

void AssignmentNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}

void AssignmentNode::visitChildNodes(AstNodeVisitor &p_visitor){
    variable_node->accept(p_visitor);
    expression_node->accept(p_visitor);
}

void AssignmentNode::visitExpressionNodes(AstNodeVisitor &p_visitor){
    expression_node->accept(p_visitor);
}

void AssignmentNode::visitVariableNodes(AstNodeVisitor &p_visitor)
{
    variable_node->accept(p_visitor);
}

