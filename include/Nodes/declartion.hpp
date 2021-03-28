#pragma once
#include "ast.hpp"
#include "Nodes/variable.hpp"
class DeclarationNode: public ASTNodeBase
{
    private:
        NodeList* VariableNodes;

    public:
        DeclarationNode(int _line_number,
                       int _col_number,
                       NodeList* _VariableNodes);

        ~DeclarationNode()
        {
           
        }
        void accept(AstNodeVisitor &p_visitor) override;
        void visitChildNodes(AstNodeVisitor &p_visitor) override;
        void setisparam()
        {
            for(auto p : *VariableNodes)
            {
                ((VariableNode *)p)->isparam = true;
            }
        
        }
        NodeList* get_VariableNodes(){return VariableNodes;}
};
