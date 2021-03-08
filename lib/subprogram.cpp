#include "Nodes/subprogram.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include "Nodes/declartion.hpp"
SubProgramNode::SubProgramNode(
    int _line_number,
    int _col_number,
    std::string _name,
    NodeList* _arguments_list,
    enumType _type,
    NodeList* _declarations_node_list,
    Node _compound_statement) : ASTNodeBase{_line_number, _col_number},
    name(_name),
    arguments_list(_arguments_list),
    type(_type),
    declarations_node_list(_declarations_node_list),
    compound_statement(_compound_statement)
    {
        for(auto p : *arguments_list)
            ((DeclarationNode *)p)->setisparam();
    }

void SubProgramNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}

void SubProgramNode::visitChildNodes(AstNodeVisitor &p_visitor) {
    for (auto p = arguments_list->begin(); p!=arguments_list->end(); p++) {
        (*p)->accept(p_visitor);
    }
    for (auto p = declarations_node_list->rbegin(); p!=declarations_node_list->rend(); p++) {
        (*p)->accept(p_visitor);
    }
    
    compound_statement->accept(p_visitor);
}

const std::string SubProgramNode::getNameCString() const { return name; }