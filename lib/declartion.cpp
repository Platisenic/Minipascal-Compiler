#include "Nodes/declartion.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

DeclarationNode::DeclarationNode(
    int _line_number,
    int _col_number,
    NodeList* _VariableNodes) : ASTNodeBase{_line_number, _col_number},
    VariableNodes(_VariableNodes)
    {}

void DeclarationNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}

void DeclarationNode::visitChildNodes(AstNodeVisitor &p_visitor) {
    for (auto p = VariableNodes->rbegin(); p!=VariableNodes->rend(); p++) {
        (*p)->accept(p_visitor);
    }
}
