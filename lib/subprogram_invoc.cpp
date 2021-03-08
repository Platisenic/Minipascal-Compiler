#include "Nodes/subprogram_invoc.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

SubProgramInvocationNode::SubProgramInvocationNode(
    int _line_number,
    int _col_number,
    std::string _name,
    NodeList* _args) :ASTNodeBase{_line_number, _col_number},
    name(_name),
    args(_args)
    {}

SubProgramInvocationNode::SubProgramInvocationNode(
    int _line_number,
    int _col_number,
    std::string _name) :ASTNodeBase{_line_number, _col_number},
    name(_name),
    args(nullptr)
    {}

void SubProgramInvocationNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}

void SubProgramInvocationNode::visitChildNodes(AstNodeVisitor &p_visitor) {
    if(args)
    {for (auto p = args->rbegin(); p!=args->rend(); p++) {
        (*p)->accept(p_visitor);
    }}
}

const std::string SubProgramInvocationNode::getNameCString() const {
    return name;
}


