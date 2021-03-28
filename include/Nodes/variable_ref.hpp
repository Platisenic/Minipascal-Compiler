#pragma once
#include "ast.hpp"

class VariableRefNode : public ASTNodeBase
{
    public:
        std::string variable_name;
        NodeList* indices;
        bool isLeft = false;
    public:
        VariableRefNode(
            int _line_number, 
            int _col_number, 
            std::string _variable_name,
            NodeList *_indices
        );
        ~VariableRefNode()
        {
            
        }
        const std::string getNameCString() const;
        void accept(AstNodeVisitor &p_visitor) override;
        void visitChildNodes(AstNodeVisitor &p_visitor) override;
};