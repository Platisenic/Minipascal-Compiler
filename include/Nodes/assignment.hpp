#pragma once
#include "ast.hpp"

class AssignmentNode: public ASTNodeBase
{
    private:
        Node variable_node;
        Node expression_node;

    public:
        AssignmentNode(int _line_number,
                       int _col_number,
                       Node _variable_node,
                       Node _expression_node);
        ~AssignmentNode()
        {
           
        }
        void accept(AstNodeVisitor &p_visitor) override;
        void visitChildNodes(AstNodeVisitor &p_visitor) override;
        void visitExpressionNodes(AstNodeVisitor &p_visitor);
        void visitVariableNodes(AstNodeVisitor &p_visitor);
        Node get_variable_node() {return variable_node;}
        Node get_expression_node() {return expression_node;}
};
