#pragma once
#include "ast.hpp"

class WhileNode: public ASTNodeBase
{
    public:
        
        Node condition;
        Node body;

    public:
        WhileNode(int _line_number,
                  int _col_number,
                  Node _condition, 
                  Node _body);
        ~WhileNode()
        {
            //SAFE_DELETE(this->condition)
            //NODELIST_PTR_DELETE(this->body)
        }
        void accept(AstNodeVisitor &p_visitor) override;
        void visitChildNodes(AstNodeVisitor &p_visitor) override;
};
