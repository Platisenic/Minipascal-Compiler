#include "Nodes/compound_statement.hpp"
#include "Nodes/assignment.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

CompoundStatementNode::CompoundStatementNode(
    int _line_number, 
    int _col_number,  
    NodeList* _statement_node_list) : ASTNodeBase{_line_number, _col_number},
    statement_node_list(_statement_node_list)
    {}

void CompoundStatementNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}

void CompoundStatementNode::visitChildNodes(AstNodeVisitor &p_visitor) {
    for (auto p = statement_node_list->rbegin(); p!=statement_node_list->rend(); p++) {
        (*p)->accept(p_visitor);
    }
}
