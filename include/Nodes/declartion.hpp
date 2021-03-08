#pragma once
#include "ast.hpp"
#include "Nodes/variable.hpp"
class DeclarationNode: public ASTNodeBase
{
    public:
        
        NodeList* VariableNodes;

    public:
        DeclarationNode(int _line_number,
                       int _col_number,
                       NodeList* _VariableNodes);

        ~DeclarationNode()
        {
            //NODELIST_PTR_DELETE(VariableNodes)
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
};
