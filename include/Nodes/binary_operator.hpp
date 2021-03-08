#pragma once
#include "ast.hpp"

class BinaryOperatorNode: public ASTNodeBase
{
    public:
        
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
            //SAFE_DELETE(this->left_operand);
            //SAFE_DELETE(this->right_operand);
        }
        const std::string getOpCString() const;
        void accept(AstNodeVisitor &p_visitor) override;
        void visitChildNodes(AstNodeVisitor &p_visitor) override;
};
