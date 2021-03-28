#pragma once
#include "ast.hpp"

class IfNode: public ASTNodeBase
{
    private:
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
            
        }
        void accept(AstNodeVisitor &p_visitor) override;
        void visitChildNodes(AstNodeVisitor &p_visitor) override;
        Node get_condition(){return condition;}
        Node get_body_then(){return body_then;}
        Node get_body_else(){return body_else;} //Maybe nullptr
};
