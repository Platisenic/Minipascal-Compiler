#pragma once
#include "ast.hpp"

class ProgramNode : public ASTNodeBase
{
    public:
        
        std::string program_name;
        enumType type;
        vector<id_info *>* identifier_list;
        NodeList* declarations_node_list;
        NodeList* subprogram_declarations_node_list;
        Node compound_statement_node;

    public:
        ProgramNode(
            int _line_number, 
            int _col_number, 
            std::string _program_name,
            enumType _type,
            vector<id_info *>* _identifier_list,
            NodeList* _declarations_node_list,
            NodeList* _subprogram_declarations_node_list,
            Node _compound_statement_node);
        
        ~ProgramNode()
        {
            //SAFE_DELETE(identifier_list)
            //NODELIST_PTR_DELETE(declarations_node_list)
            //NODELIST_PTR_DELETE(subprogram_declarations_node_list)
            //SAFE_DELETE(compound_statement_node)
        }
        const std::string getTypeCString() ;
        const std::string getNameCString() ;
        std::string getType();
        void accept(AstNodeVisitor &p_visitor) override;
        void visitChildNodes(AstNodeVisitor &p_visitor) override;


        
};