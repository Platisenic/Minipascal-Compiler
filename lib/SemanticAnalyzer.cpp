#include "Sema/SemanticAnalyzer.hpp"
#include "Visitor/AstNodeInclude.hpp"
#include "info.h"
#include "PrintErrors.hpp"
#include <algorithm>

bool SemanticAnalyzer::TypeEqual(type_inf left, type_inf right)
{
    //fprintf(stderr, "%d %d\n", left.dimensions.size(), right.dimensions.size());
    if ((left.s_type == right.s_type && left.dimensions.size() == right.dimensions.size()) || left.s_type == Type_Unknown || right.s_type == Type_Unknown)
    {
        return true;
    }
    return false;
}

void SemanticAnalyzer::poptable()
{
    SHOW_CLSSCP();
    SHOW_SYMTAB_HEAD();
    for (auto tab = tablelist.rbegin(); tab != tablelist.rend(); tab++)
        for (auto entr = tab->entries.rbegin(); entr != tab->entries.rend(); entr++)
            printf(SYMTAB_ENTRY_FMT, entr->name.c_str(), tab->scope, entr->getTypeString().c_str());
    SHOW_SYMTAB_TAIL();
    tablelist.pop_back();
    current_scope -= 1;
}

void SemanticAnalyzer::pushentry(SymbolEntry entry)
{
    auto d = tablelist.back().find(entry.name);
    if (d)
    {
        if(entry.kind == KIND_FUNCTION || entry.kind == KIND_PROCEDURE)
            PrintErrors::print_REDEF_FUN(entry.loc.line, entry.loc.col, entry.name);
        else
            PrintErrors::print_REDEF_VAR(entry.loc.line, entry.loc.col, entry.name);
    }
    else
    {
        tablelist.back().entries.push_back(entry);
        SHOW_NEWSYM(entry.name.c_str());
    }
}

void SemanticAnalyzer::pushtable()
{
    SHOW_NEWSCP();
    tablelist.push_back(SymbolTable(++current_scope));
}

void SemanticAnalyzer::visit(ProgramNode &p_program)
{

    pushtable();
    pushentry(SymbolEntry(p_program.getLocation(), p_program.program_name, type_inf(p_program.type), KIND_PROGRAM));
    p_program.visitChildNodes(*this);
    S0Stmbol = (&tablelist.back());
    
    //poptable();
}
void SemanticAnalyzer::visit(DeclarationNode &p_declaration)
{
    p_declaration.visitChildNodes(*this);
}
void SemanticAnalyzer::visit(VariableNode &p_variable)
{
    pushentry(SymbolEntry(p_variable.getLocation(), p_variable.variable_name, p_variable.type, KIND_VARIABLE));
    p_variable.visitChildNodes(*this);
}
void SemanticAnalyzer::visit(SubProgramNode &p_subprogram)
{
    std::vector<type_inf> parameter_type;
    for (auto p = p_subprogram.arguments_list->begin(); p != p_subprogram.arguments_list->end(); p++)
    {
        for (auto pp = ((DeclarationNode *)(*p))->VariableNodes->rbegin(); pp != ((DeclarationNode *)(*p))->VariableNodes->rend(); pp++)
        {
            parameter_type.push_back(((VariableNode *)(*pp))->type);
        }
    }
    if(p_subprogram.type == Type_void)
        pushentry(SymbolEntry(p_subprogram.getLocation(), p_subprogram.name, type_inf(p_subprogram.type), KIND_PROCEDURE, parameter_type));
    else
        pushentry(SymbolEntry(p_subprogram.getLocation(), p_subprogram.name, type_inf(p_subprogram.type), KIND_FUNCTION, parameter_type));
    pushtable();
    /*for (auto p = p_subprogram.arguments_list->rbegin(); p!=p_subprogram.arguments_list->rend(); p++) {
        (*p)->accept(*this);
    }
    for (auto p = p_subprogram.declarations_node_list->rbegin(); p!=p_subprogram.declarations_node_list->rend(); p++) {
        //printf("out\n");
        (*p)->accept(*this);
    }*/
    p_subprogram.visitChildNodes(*this);
    SymbolEntry *entr = nullptr;
    for (auto p = tablelist.rbegin(); p != tablelist.rend(); p++)
    {
        entr = (*p).find(p_subprogram.name);
        if (entr != nullptr)
        {
            break;
        }
    }
    if(entr && entr->kind != KIND_PROCEDURE && entr->is_not_assign)
        PrintErrors::print_RETURN_VAL(p_subprogram.getLocation().line, p_subprogram.getLocation().col, p_subprogram.name);
    else
    {
        entr->is_not_assign = true;
        entr->lock = true;
    }
    
    poptable();
}

void SemanticAnalyzer::visit(VariableRefNode &p_variable_ref)
{
    SymbolEntry *entr = nullptr;
    for (auto p = tablelist.rbegin(); p != tablelist.rend(); p++)
    {
        entr = (*p).find(p_variable_ref.variable_name);
        if (entr != nullptr)
        {
            break;
        }
    }

    if (!entr)
    {
        p_variable_ref.TYPE = type_inf(Type_Unknown);
        PrintErrors::print_UNDEC_VAR(p_variable_ref.getLocation().line, p_variable_ref.getLocation().col, p_variable_ref.variable_name);
    }
    else
    {
        p_variable_ref.visitChildNodes(*this);
        if (entr->type.dimensions.size() < p_variable_ref.indices->size() && p_variable_ref.indices->size())
        {
            PrintErrors::print_INDEX_MANY(p_variable_ref.getLocation().line, p_variable_ref.getLocation().col, p_variable_ref.variable_name);
            p_variable_ref.TYPE = type_inf(Type_Unknown);
        }
        else if (p_variable_ref.indices->size())
        {
            bool flag = false;
            auto ds=entr->type;
            std::reverse(ds.dimensions.begin(),ds.dimensions.end());
            for (auto &p : *p_variable_ref.indices)
            {
                if (!TypeEqual(p->TYPE, type_inf(Type_int)))
                {
                    PrintErrors::print_INDEX_TYPE(p->getLocation().line, p->getLocation().col);
                    p_variable_ref.TYPE = type_inf(Type_Unknown);
                    flag = true;
                    
                }
                ds.dimensions.pop_back();
            }
            if (!flag){
                std::reverse(ds.dimensions.begin(),ds.dimensions.end());
                p_variable_ref.TYPE = ds;
            }
        }
        else
        {
            p_variable_ref.TYPE = entr->type;
        }
    }
}

void SemanticAnalyzer::visit(AssignmentNode &p_assignment)
{
    p_assignment.visitChildNodes(*this);
    SymbolEntry *entr = nullptr;
    for (auto p = tablelist.rbegin(); p != tablelist.rend(); p++)
    {
        entr = (*p).find(((VariableNode *)(p_assignment.variable_node))->variable_name);
        if (entr != nullptr)
        {
            break;
        }
            
    }
    if(entr && entr->kind == KIND_FUNCTION && !entr->lock)
        entr->is_not_assign = false;
    if(entr && entr->kind == KIND_FUNCTION && entr->lock)
         PrintErrors::print_ASSIG_TYPE(p_assignment.variable_node->getLocation().line, p_assignment.variable_node->getLocation().col);
    //fprintf(stderr, "%s, %s\n", p_assignment.variable_node->TYPE.getTypeinf().c_str(), p_assignment.expression_node->TYPE.getTypeinf().c_str());
    else if (!TypeEqual(p_assignment.variable_node->TYPE, p_assignment.expression_node->TYPE))
    {
        PrintErrors::print_ASSIG_TYPE(p_assignment.variable_node->getLocation().line, p_assignment.variable_node->getLocation().col);
    }
}
void SemanticAnalyzer::visit(BinaryOperatorNode &p_binaryoperator)
{
    p_binaryoperator.visitChildNodes(*this);
    if (!TypeEqual(p_binaryoperator.left_operand->TYPE, p_binaryoperator.right_operand->TYPE))
    {
        PrintErrors::print_ARITH_TYPE(p_binaryoperator.getLocation().line, p_binaryoperator.getLocation().col, p_binaryoperator.getOpCString());
        p_binaryoperator.TYPE = type_inf(Type_Unknown);
    }
    else
        p_binaryoperator.TYPE = p_binaryoperator.left_operand->TYPE;
}

void SemanticAnalyzer::visit(CompoundStatementNode &p_compound_statement)
{
    p_compound_statement.visitChildNodes(*this);
}

void SemanticAnalyzer::visit(ConstantNode &p_constant)
{
    p_constant.visitChildNodes(*this);
    p_constant.TYPE = type_inf(p_constant.type);
}

void SemanticAnalyzer::visit(IfNode &p_if)
{
    p_if.visitChildNodes(*this);
}



void SemanticAnalyzer::visit(SubProgramInvocationNode &p_subprogram_invoc)
{
    SymbolEntry *entr = nullptr;
    for (auto p = tablelist.rbegin(); p != tablelist.rend(); p++)
    {
        entr = (*p).find(p_subprogram_invoc.name);
        if (entr != nullptr)
        {
            break;
        }
            
    }
    p_subprogram_invoc.visitChildNodes(*this);
    if (!entr)
    {
        PrintErrors::print_UNDEC_FUN(p_subprogram_invoc.getLocation().line, p_subprogram_invoc.getLocation().col, p_subprogram_invoc.name);
        p_subprogram_invoc.TYPE = type_inf(Type_Unknown);
    }
    else
    {
        p_subprogram_invoc.TYPE = type_inf(entr->type.s_type);
        if(p_subprogram_invoc.args){
            if((p_subprogram_invoc.args->size() == entr->parameter_type.size()))
            {
                for(size_t p=0;p<p_subprogram_invoc.args->size();p++)
                {
                    if((*(p_subprogram_invoc.args))[p]->TYPE.s_type != entr->parameter_type[entr->parameter_type.size()-1-p].s_type){
                        
                        PrintErrors::print_WRONG_ARGS(p_subprogram_invoc.getLocation().line, p_subprogram_invoc.getLocation().col, p_subprogram_invoc.name);
                        
                    }//fprintf(stderr,"%s,%s\n", (*(p_subprogram_invoc.args))[p]->TYPE.getTypeinf().c_str(),entr->parameter_type[entr->parameter_type.size()-1-p].getTypeinf().c_str());
                }
            }else
            {
                PrintErrors::print_WRONG_ARGS(p_subprogram_invoc.getLocation().line, p_subprogram_invoc.getLocation().col, p_subprogram_invoc.name);
            }
        }
        
    }
    
}

void SemanticAnalyzer::visit(UnaryOperatorNode &p_unaryoperator)
{
    p_unaryoperator.visitChildNodes(*this);
}

void SemanticAnalyzer::visit(WhileNode &p_while)
{
    p_while.visitChildNodes(*this);
}

