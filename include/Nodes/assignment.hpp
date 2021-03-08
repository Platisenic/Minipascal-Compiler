#pragma once
#include "ast.hpp"

class AssignmentNode: public ASTNodeBase
{
    public:
        Node variable_node;
        Node expression_node;

    public:
        AssignmentNode(int _line_number,
                       int _col_number,
                       Node _variable_node,
                       Node _expression_node);
        ~AssignmentNode()
        {
            //SAFE_DELETE(this->variable_node)
            //SAFE_DELETE(this->expression_node)
        }
        void accept(AstNodeVisitor &p_visitor) override;
        void visitChildNodes(AstNodeVisitor &p_visitor) override;
        void visitExpressionNodes(AstNodeVisitor &p_visitor);
        void visitVariableNodes(AstNodeVisitor &p_visitor);
};
