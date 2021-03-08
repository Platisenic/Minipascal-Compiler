#pragma once
#include "ast.hpp"

class ConstantNode : public ASTNodeBase
{
    public:
        
        const_union value;  
        enumType type;

    public:
        ConstantNode(
            int _line_number, 
            int _col_number, 
            enumType _type,
            const_union _value);

        ~ConstantNode()
        {
            // do nothing
        }
        const std::string getConstantValueCString() const;
        void accept(AstNodeVisitor &p_visitor) override;
        void visitChildNodes(AstNodeVisitor &p_visitor) override;
        const std::string getValueCString() const;
};