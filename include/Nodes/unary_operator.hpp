#pragma once
#include "ast.hpp"

class UnaryOperatorNode: public ASTNodeBase
{
    private:
        enumOperator op;
        Node operand;

    public:
        UnaryOperatorNode(int _line_number,
                           int _col_number,
                           enumOperator _op, 
                           Node _operand);
        ~UnaryOperatorNode()
        {
            
        }
        const std::string getOpCString() const;
        void accept(AstNodeVisitor &p_visitor) override;
        void visitChildNodes(AstNodeVisitor &p_visitor) override;
        enumOperator get_op(){return op;}
        Node get_operand(){return operand;}
};
