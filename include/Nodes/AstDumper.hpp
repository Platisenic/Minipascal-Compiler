#ifndef __AST_DUMPER_H
#define __AST_DUMPER_H

#include "Visitor/AstNodeVisitor.hpp"

#include <cstdint>

class AstDumper : public AstNodeVisitor {
  public:
    AstDumper() = default;
    ~AstDumper() = default;

    void visit(AssignmentNode &p_assignment) override;
    void visit(BinaryOperatorNode &p_binaryoperator) override;
    void visit(CompoundStatementNode &p_compound_statement) override;
    void visit(ConstantNode &p_constant) override;
    void visit(DeclarationNode &p_declaration) override;
    void visit(IfNode &p_if) override;
    void visit(ProgramNode &p_program) override;
    void visit(SubProgramInvocationNode &p_subprogram_invoc) override;
    void visit(SubProgramNode &p_subprogram) override;
    void visit(UnaryOperatorNode &p_unaryoperator) override;
    void visit(VariableRefNode &p_variable_ref) override;
    void visit(VariableNode &p_variable) override;
    void visit(WhileNode &p_while) override;

  private:
    void incrementIndentation();
    void decrementIndentation();

  private:
    const uint32_t m_indentation_stride = 2u;
    uint32_t m_indentation = 0u;
};

#endif
