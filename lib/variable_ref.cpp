#include "Nodes/variable_ref.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

VariableRefNode::VariableRefNode(
    int _line_number, 
    int _col_number, 
    std::string _variable_name,
    NodeList* _indices):ASTNodeBase{_line_number, _col_number},
    variable_name(_variable_name),
    indices(_indices)
    {}

void VariableRefNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}

void VariableRefNode::visitChildNodes(AstNodeVisitor &p_visitor) {
    for (auto p = indices->rbegin(); p!=indices->rend(); p++) {
        (*p)->accept(p_visitor);
    }
}

const std::string VariableRefNode::getNameCString() const {
    return variable_name;
}
