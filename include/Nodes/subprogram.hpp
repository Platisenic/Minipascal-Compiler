#pragma once
#include "ast.hpp"

class SubProgramNode: public ASTNodeBase
{
    public:
        
        std::string name;
        NodeList* arguments_list;//declarationnode
        enumType type;
        NodeList* declarations_node_list;
        Node compound_statement;
        

    public:
        SubProgramNode(int _line_number,
                        int _col_number,
                        std::string _name,
                        NodeList* _arguments_list,
                        enumType _type,
                        NodeList* _declarations_node_list,
                        Node _compound_statement);
        ~SubProgramNode()
        {
            //NODELIST_PTR_DELETE(declarations_node_list)
            //SAFE_DELETE(compound_statement)
        }
        void accept(AstNodeVisitor &p_visitor) override;
        void visitChildNodes(AstNodeVisitor &p_visitor) override;
        const std::string getNameCString() const;
};
