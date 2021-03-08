#pragma once
#include "ast.hpp"

class IfNode: public ASTNodeBase
{
    public:
        
        Node condition;
        Node body_then;
        Node body_else; //Maybe nullptr

    public:
        IfNode(int _line_number,
               int _col_number,
               Node _condition, 
               Node _body_then,
               Node _body_else);
        ~IfNode()
        {
            //SAFE_DELETE(this->condition)
            //NODELIST_PTR_DELETE(this->body_then)
            //NODELIST_PTR_DELETE(this->body_else)
        }
        void accept(AstNodeVisitor &p_visitor) override;
        void visitChildNodes(AstNodeVisitor &p_visitor) override;
};
