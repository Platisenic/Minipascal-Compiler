#pragma once
#include "ast.hpp"

class UnaryOperatorNode: public ASTNodeBase
{
    public:
        
        enumOperator op;
        Node operand;

    public:
        UnaryOperatorNode(int _line_number,
                           int _col_number,
                           enumOperator _op, 
                           Node _operand);
        ~UnaryOperatorNode()
        {
            //SAFE_DELETE(this->operand)
        }
        const std::string getOpCString() const;
        void accept(AstNodeVisitor &p_visitor) override;
        void visitChildNodes(AstNodeVisitor &p_visitor) override;
};
