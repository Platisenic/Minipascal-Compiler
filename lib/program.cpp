#include "Nodes/program.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include "Nodes/compound_statement.hpp"
ProgramNode::ProgramNode(
    int _line_number, 
    int _col_number, 
    std::string _program_name,
    enumType _type,
    vector<id_info *>* _identifier_list,
    NodeList* _declarations_node_list,
    NodeList* _subprogram_declarations_node_list,
    Node _compound_statement_node) : ASTNodeBase{_line_number, _col_number},
    program_name(_program_name),
    type(_type),
    identifier_list(_identifier_list),
    declarations_node_list(_declarations_node_list),
    subprogram_declarations_node_list(_subprogram_declarations_node_list),
    compound_statement_node(_compound_statement_node)
    {
        ((CompoundStatementNode *)(compound_statement_node))->ismain = true;
    }

std::string ProgramNode::getType()
{
    std::string ret_type;
    switch(this->type)
    {
        case Type_int    : ret_type = "int"; break;
        case Type_real   : ret_type = "real"; break;
        case Type_string : ret_type = "string"; break;
        case Type_void   : ret_type = "void"; break;
        default: ret_type = "Unknown";
    }
    return ret_type;
}

void ProgramNode::accept(AstNodeVisitor &p_visitor) {
    p_visitor.visit(*this);
}

void ProgramNode::visitChildNodes(AstNodeVisitor &p_visitor) {
    for (auto p = declarations_node_list->rbegin(); p!=declarations_node_list->rend(); p++) {
        (*p)->accept(p_visitor);
    }
    for (auto p = subprogram_declarations_node_list->rbegin(); p!=subprogram_declarations_node_list->rend(); p++) {
        (*p)->accept(p_visitor);
    }
    compound_statement_node->accept(p_visitor);
}


const std::string ProgramNode::getTypeCString() 
{
    return program_name; 
}

const std::string ProgramNode::getNameCString() 
{
    return this->getType();
}

