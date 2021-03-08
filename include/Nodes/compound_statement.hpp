#pragma once
#include "ast.hpp"


class CompoundStatementNode : public ASTNodeBase
{
    public:  
        NodeList* statement_node_list; 

    public:
        CompoundStatementNode(
            int _line_number, 
            int _col_number, 
            NodeList* _statement_node_list);
            
        ~CompoundStatementNode()
        {
            //NODELIST_PTR_DELETE(this->statement_node_list)
        }
        void accept(AstNodeVisitor &p_visitor) override;
        void visitChildNodes(AstNodeVisitor &p_visitor) override;
        bool ismain=false;
};