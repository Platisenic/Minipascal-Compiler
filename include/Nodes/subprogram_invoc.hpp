#pragma once
#include "ast.hpp"

class SubProgramInvocationNode: public ASTNodeBase
{
    public:
        std::string name;
        NodeList* args;

    public:
        SubProgramInvocationNode(int _line_number,
                       int _col_number,
                       std::string name,
                       NodeList* args);

        SubProgramInvocationNode(int _line_number,
                       int _col_number,
                       std::string name);

        ~SubProgramInvocationNode()
        {
            
        }
        void accept(AstNodeVisitor &p_visitor) override;
        void visitChildNodes(AstNodeVisitor &p_visitor) override;
        const std::string getNameCString() const;
        std::string get_name(){return name;}
        NodeList* get_args(){return args;}
};
