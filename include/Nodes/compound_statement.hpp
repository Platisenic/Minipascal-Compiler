#pragma once
#include "ast.hpp"


class CompoundStatementNode : public ASTNodeBase
{
    private:  
        NodeList* statement_node_list; 

    public:
        CompoundStatementNode(
            int _line_number, 
            int _col_number, 
            NodeList* _statement_node_list);
            
        ~CompoundStatementNode()
        {
            
        }
        void accept(AstNodeVisitor &p_visitor) override;
        void visitChildNodes(AstNodeVisitor &p_visitor) override;
        bool ismain=false;
        NodeList* get_statement_node_list(){return statement_node_list;} 
};