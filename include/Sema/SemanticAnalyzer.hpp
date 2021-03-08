#ifndef __SEMA_SEMANTIC_ANALYZER_H
#define __SEMA_SEMANTIC_ANALYZER_H

#include "Visitor/AstNodeVisitor.hpp"
#include "Sema/SymbolTable.hpp"
#include <vector>


class SemanticAnalyzer : public AstNodeVisitor {
  public:
    SemanticAnalyzer() = default;
    ~SemanticAnalyzer() = default;

    void pushtable();
    void pushentry(SymbolEntry entry);
    void poptable();
    bool TypeEqual(type_inf left, type_inf right);
    SymbolTable* getS0Stmbol()
    {
      return S0Stmbol;
    }

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

  public:
    std::vector<SymbolTable> tablelist;
    int current_scope = -1;
    bool Error = false;
    SymbolTable* S0Stmbol;
    
};

#endif
