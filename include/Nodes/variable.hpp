#pragma once
#include "ast.hpp"

class VariableNode : public ASTNodeBase
{
    public:
        std::string variable_name;
        type_inf type;
        bool isparam = false;

    public:
        VariableNode(
            int _line_number, 
            int _col_number, 
            std::string _variable_name,
            type_inf* _type);

        ~VariableNode()
        {
            // do nothing
        }

        std::string getType();
        const std::string getNameCString() ;
        const std::string getTypeCString() ;
        void accept(AstNodeVisitor &p_visitor) override;
        void visitChildNodes(AstNodeVisitor &p_visitor) override;
        
};