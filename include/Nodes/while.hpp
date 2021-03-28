#pragma once
#include "ast.hpp"

class WhileNode: public ASTNodeBase
{
    private:
        Node condition;
        Node body;

    public:
        WhileNode(int _line_number,
                  int _col_number,
                  Node _condition, 
                  Node _body);
        ~WhileNode()
        {
            
        }
        void accept(AstNodeVisitor &p_visitor) override;
        void visitChildNodes(AstNodeVisitor &p_visitor) override;
        Node get_condition(){return condition;}
        Node get_body(){return body;} //Maybe nullptr
};
