#ifndef __VISITOR_H
#define __VISITOR_H



// Forward declaration of AST nodes
class AssignmentNode;
class BinaryOperatorNode;
class CompoundStatementNode;
class ConstantNode;
class DeclarationNode;
class IfNode;
class ProgramNode;
class SubProgramInvocationNode;
class SubProgramNode;
class UnaryOperatorNode;
class VariableRefNode;
class VariableNode;
class WhileNode;

class AstNodeVisitor {
  public:
    virtual ~AstNodeVisitor(){};

    virtual void visit(AssignmentNode &p_assignment) {}
    virtual void visit(BinaryOperatorNode &p_binaryoperator) {}
    virtual void visit(CompoundStatementNode &p_compound_statement) {}
    virtual void visit(ConstantNode &p_constant) {}
    virtual void visit(DeclarationNode &p_declaration) {}
    virtual void visit(IfNode &p_if) {}
    virtual void visit(ProgramNode &p_program) {}
    virtual void visit(SubProgramInvocationNode &p_subprogram_invoc) {}
    virtual void visit(SubProgramNode &p_subprogram) {}
    virtual void visit(UnaryOperatorNode &p_unaryoperator) {}
    virtual void visit(VariableRefNode &p_variable_ref) {}
    virtual void visit(VariableNode &p_variable) {}
    virtual void visit(WhileNode &p_while) {}
};

#endif
