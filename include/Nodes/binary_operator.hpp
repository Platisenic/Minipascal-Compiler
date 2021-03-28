#pragma once
#include "ast.hpp"

class BinaryOperatorNode: public ASTNodeBase
{
    private:
        enumOperator op;
        Node left_operand;
        Node right_operand;

    public:
        BinaryOperatorNode(int _line_number,
                           int _col_number,
                           enumOperator _op, 
                           Node _left_operand,
                           Node _right_operand);
        ~BinaryOperatorNode()
        {
            
        }
        const std::string getOpCString() const;
        void accept(AstNodeVisitor &p_visitor) override;
        void visitChildNodes(AstNodeVisitor &p_visitor) override;
        enumOperator get_op()   {return op;}
        Node get_left_operand() {return left_operand;}
        Node get_right_operand(){return right_operand;}
};
