#include "Codegen/CodeGenerator.hpp"
#include "Visitor/AstNodeInclude.hpp"
#include "stdio.h"
#include "string.h"
#include <string>
#include <algorithm>

bool CodeGenerator::TypeEqual(type_inf left, type_inf right)
{
    //fprintf(stderr, "%d %d\n", left.dimensions.size(), right.dimensions.size());
    if ((left.s_type == right.s_type && left.dimensions.size() == right.dimensions.size()) || left.s_type == Type_Unknown || right.s_type == Type_Unknown)
    {
        return true;
    }
    return false;
}

void CodeGenerator::filecreate()
{
    this->fp = fopen(filename, "w");
}
void CodeGenerator::fileclose()
{
    fclose(this->fp);
}
void CodeGenerator::poptable()
{
    // SHOW_CLSSCP();
    // SHOW_SYMTAB_HEAD();
    // for (auto tab = tablelist.rbegin(); tab != tablelist.rend(); tab++)
    //     for (auto entr = tab->entries.rbegin(); entr != tab->entries.rend(); entr++)
    //         printf(SYMTAB_ENTRY_FMT, entr->name.c_str(), tab->scope, entr->getTypeString().c_str());
    // SHOW_SYMTAB_TAIL();
    tablelist.pop_back();
    current_scope -= 1;
}

void CodeGenerator::pushentry(SymbolEntry entry)
{
    auto d = tablelist.back().find(entry.name);
    if (d)
    {
        // if(entry.kind == KIND_FUNCTION || entry.kind == KIND_PROCEDURE)
        //     PrintErrors::print_REDEF_FUN(entry.loc.line, entry.loc.col, entry.name);
        // else
        //     PrintErrors::print_REDEF_VAR(entry.loc.line, entry.loc.col, entry.name);
    }
    else
    {
        entry.serialnum = tablelist.back().serialnum++;
        tablelist.back().entries.push_back(entry);
        //SHOW_NEWSYM(entry.name.c_str());
    }
}

void CodeGenerator::pushtable()
{
    //SHOW_NEWSCP();
    tablelist.push_back(SymbolTable(++current_scope));
}

void CodeGenerator::visit(AssignmentNode &p_assignment)
{
    p_assignment.visitChildNodes(*this);
    //return;
    SymbolEntry *entr = nullptr;
    int level = 0;
    for (auto p = tablelist.rbegin(); p != tablelist.rend(); p++)
    {
        entr = (*p).find(((VariableRefNode *)(p_assignment.get_variable_node()))->variable_name);
        if (entr != nullptr)
        {
            level = p->scope;
            break;
        }
    }
    std::string stt;
     switch(entr->type.s_type)
     {
         case Type_int: stt = "i"; break;
         case Type_real : stt = "f" ; break;
         default: printf("  ");
     }
    if (entr->type.dimensions.size() != 0)
    {
        fprintf(fp, "    %sastore\n", stt.c_str());
    }
    else
    {

        if (entr->kind != KIND_FUNCTION && entr->kind != KIND_PROCEDURE)
        {
            if (level == 0)
            {
                fprintf(fp, "    putstatic %s/%s %s\n", classname.c_str(), entr->name.c_str(), entr->type.getTypeinfAssembly().c_str());
            }
            else
            {
                // printf("!FIND!%s!\n", entr->name.c_str());
                fprintf(fp, "    %sstore %d\n",  stt.c_str(),entr->serialnum);
            }
        }
        //else printf("!???!%s!\n", entr->name.c_str());
    }
}

void CodeGenerator::visit(ProgramNode &p_program)
{
    filecreate();
    classname = p_program.program_name;
    fprintf(fp, ".class public %s\n", p_program.program_name.c_str());
    fprintf(fp, ".super java/lang/Object\n");
    for (auto entr = Scope0Symbol->entries.begin(); entr != Scope0Symbol->entries.end(); entr++)
    {
        if (entr->kind != KIND_PROGRAM && entr->kind != KIND_FUNCTION && entr->kind != KIND_PROCEDURE)
        {
            switch (entr->type.s_type)
            {
            case Type_int:
                fprintf(fp, ".field public static %s %s\n", entr->name.c_str(), entr->getTypeStringAssembly().c_str());
                break;
            case Type_real:
                fprintf(fp, ".field public static %s %s\n", entr->name.c_str(), entr->getTypeStringAssembly().c_str());
                break;
            case Type_string:
                fprintf(fp, ".field public static %s Ljava/lang/String;\n", entr->name.c_str());
                break;
            default:
                fprintf(fp, "Error in ProgramNode %s I\n", entr->name.c_str());
                break;
            }
            //fprintf(fp, "KIND is %d\n", entr->kind);
        }
    }

    pushtable();
    pushentry(SymbolEntry(p_program.getLocation(), p_program.program_name, type_inf(p_program.type), KIND_PROGRAM));
    p_program.visitChildNodes(*this);

    fprintf(fp, "    return\n");
    fprintf(fp, ".end method\n");
    // for (auto entr = tablelist.back().entries.rbegin(); entr != tablelist.back().entries.rend(); entr++)
    //     fprintf(fp, "NAME%s\n", entr->name.c_str());

    poptable();
    fileclose();
}
void CodeGenerator::visit(DeclarationNode &p_declaration)
{
    p_declaration.visitChildNodes(*this);
}
void CodeGenerator::visit(VariableNode &p_variable)
{
    auto newtype = p_variable.type;
    std::reverse(newtype.dimensions.begin(), newtype.dimensions.end());
    pushentry(SymbolEntry(p_variable.getLocation(), p_variable.variable_name, newtype, KIND_VARIABLE));
    if (p_variable.isparam)
    {
        tablelist.back().entries.back().isparam = true;
    }

    p_variable.visitChildNodes(*this);
}
void CodeGenerator::visit(SubProgramNode &p_subprogram)
{
    needreturn = 1;
    std::vector<type_inf> parameter_type;
    for (auto p = p_subprogram.arguments_list->begin(); p != p_subprogram.arguments_list->end(); p++)
    {
        for (auto pp = ((DeclarationNode *)(*p))->get_VariableNodes()->rbegin(); pp != ((DeclarationNode *)(*p))->get_VariableNodes()->rend(); pp++)
        {
            parameter_type.push_back(((VariableNode *)(*pp))->type);
        }
    }
    if (p_subprogram.type == Type_void)
        pushentry(SymbolEntry(p_subprogram.getLocation(), p_subprogram.name, type_inf(p_subprogram.type), KIND_PROCEDURE, parameter_type));
    else
        pushentry(SymbolEntry(p_subprogram.getLocation(), p_subprogram.name, type_inf(p_subprogram.type), KIND_FUNCTION, parameter_type));

    std::string retTypeB;
    std::string retTypeS;
    switch (p_subprogram.type)
    {
    case Type_int:
        retTypeB = "I";
        retTypeS = "i";
        break;
    case Type_real:
        retTypeB = "F";
        retTypeS = "f";
        break;
    default: printf("  ");
    }

    for (auto entr = tablelist.back().entries.begin(); entr != tablelist.back().entries.end(); entr++)
    {
        if (p_subprogram.name == entr->name)
        {
            std::string rettype = entr->getTypeStringAssembly();

            fprintf(fp, ".method public static %s%s\n", p_subprogram.name.c_str(), rettype.c_str());
            break;
        }
    }

    fprintf(fp, ".limit locals 50\n");
    fprintf(fp, ".limit stack 50\n");

    pushtable();
    tablelist.back().func_name = p_subprogram.name;
    p_subprogram.visitChildNodes(*this);

    fprintf(fp, "    %sreturn\n", retTypeS.c_str());
    fprintf(fp, ".end method\n");

    poptable();
    needreturn = 0;
}

void CodeGenerator::visit(VariableRefNode &p_variable_ref)
{
    
    if (strcmp(p_variable_ref.variable_name.c_str(), "readlnI") == 0)
    {
        fprintf(fp, "    invokestatic io/readlnI()I\n");
        return;
    }
    if (strcmp(p_variable_ref.variable_name.c_str(), "readlnF") == 0)
    {
        fprintf(fp, "    invokestatic io/readlnF()F\n");
        return;
    }
    //   for (auto tab = tablelist.rbegin(); tab != tablelist.rend(); tab++)
    //     for (auto entr = tab->entries.rbegin(); entr != tab->entries.rend(); entr++)
    //         fprintf(fp,"%s   |  %d   | %s\n", entr->name.c_str(), tab->scope, entr->getTypeString().c_str());
    SymbolEntry *entr = nullptr;
    int level = 0;
    
    for (auto p = tablelist.rbegin(); p != tablelist.rend(); p++)
    {
        entr = (*p).find(p_variable_ref.variable_name);
        if (entr != nullptr)
        {
          
            level = p->scope;
            break;
        }
    }
    
    std::string typp;
    switch (entr->type.s_type)
    {
    case Type_int:
        typp = "i";
        break;
    case Type_real:
        typp = "f";
        break;
    default: printf("  ");
    }

    if (entr->isparam)
    {
        if(entr->type.dimensions.size()==0)
        {
            if (!p_variable_ref.isLeft)
            {
                fprintf(fp, "    %sload  %d\n", typp.c_str(), entr->serialnum);
            }
            else
            {
                fprintf(fp, "    %sstore %d\n", typp.c_str(), entr->serialnum);
            }
            return ;
        }else
        {

        }
        
        
        
    }
    
    if (level == 0)
    {
        if(entr->type.dimensions.size() != 0){
            if (entr->kind != KIND_FUNCTION && entr->kind != KIND_PROCEDURE)
                fprintf(fp, "    getstatic %s/%s %s\n", classname.c_str(), entr->name.c_str(), entr->type.getTypeinfAssembly().c_str());
        }
        else if (!p_variable_ref.isLeft)
        {
            if (entr->kind != KIND_FUNCTION && entr->kind != KIND_PROCEDURE)
                fprintf(fp, "    getstatic %s/%s %s\n", classname.c_str(), entr->name.c_str(), entr->type.getTypeinfAssembly().c_str());
            else if (tablelist.back().func_name != p_variable_ref.variable_name)
            {
                fprintf(fp, "    invokestatic %s/%s%s\n", classname.c_str(), entr->name.c_str(), entr->getTypeStringAssembly().c_str());
                return;
            }
            
        }
        
    }
    else
    {
        if (entr->type.dimensions.size() != 0)
        {
            fprintf(fp, "    aload_%d\n", entr->serialnum);
        }
    }
    std::string typ;
    switch (entr->type.s_type)
    {
    case Type_int:
        typ = "i";
        break;
    case Type_real:
        typ = "f";
        break;
    default: printf("  ");
    }
    if (entr->type.dimensions.size() != 0)
    {
        // Visit ChildNodes
        int index = 0;
        // for(auto p : entr->type.dimensions)
        //     fprintf(fp, "%d ",p.first);
        // fprintf(fp, "\n");
        for (auto p = p_variable_ref.indices->rbegin(); p != p_variable_ref.indices->rend(); p++)
        {
            if (index != 0)
            {
                fprintf(fp, "    aaload\n");
            }
            (*p)->accept(*this);

            fprintf(fp, "    ldc %d\n", entr->type.dimensions[index++].first);
            fprintf(fp, "    isub\n");
        }

        if (!p_variable_ref.isLeft)
        {   
            if(p_variable_ref.indices->size() == 0){}
                
            else if(p_variable_ref.indices->size() < entr->type.dimensions.size())
                fprintf(fp, "    aaload\n");
            else
                fprintf(fp, "    %saload\n", typp.c_str());
        }
    }else
    {
        if (!p_variable_ref.isLeft && current_scope != 0 && level != 0)
        {
            fprintf(fp, "    %sload  %d\n", typp.c_str(), entr->serialnum);
        }
    }
    
}

void CodeGenerator::visit(BinaryOperatorNode &p_binaryoperator)
{
    Stringjava = 1;
    p_binaryoperator.visitChildNodes(*this);
    Stringjava = 0;
    p_binaryoperator.TYPE = p_binaryoperator.get_left_operand()->TYPE;
    std::string typ;

    switch (p_binaryoperator.get_left_operand()->TYPE.s_type)
    {
    case Type_int:
        typ = "i";
        break;
    case Type_real:
        typ = "f";
        break;
    case Type_string:
        fprintf(fp, "invokevirtual java/lang/StringBuffer/toString()Ljava/lang/String;\n");
        break;
    case Type_void:
        typ = "void";
        break;
    case Type_Unknown:
        typ = "unknown";
        break;
    default:
        typ = "???BOnode";
        break;
    }
    if (p_binaryoperator.get_left_operand()->TYPE.s_type != Type_string)
    {
        switch (p_binaryoperator.get_op())
        {
        case OP_ADD:
            fprintf(fp, "    %sadd\n", typ.c_str());
            break;
        case OP_SUB:
            fprintf(fp, "    %ssub\n", typ.c_str());
            break;
        case OP_MUL:
            fprintf(fp, "    %smul\n", typ.c_str());
            break;
        case OP_DIV:
            fprintf(fp, "    %sdiv\n", typ.c_str());
            break;
        case OP_GT:
            if (p_binaryoperator.get_left_operand()->TYPE.s_type == Type_real)
            {
                fprintf(fp, "    fcmpg\n");
                fprintf(fp, "    ldc 1\n");
                fprintf(fp, "    if_icmpeq L%d\n", label++);
            }
            else
            {
                fprintf(fp, "    if_icmpgt L%d\n", label++);
            }
            break;
        case OP_LT:
            if (p_binaryoperator.get_left_operand()->TYPE.s_type == Type_real)
            {
                fprintf(fp, "    fcmpg\n");
                fprintf(fp, "    ldc -1\n");
                fprintf(fp, "    if_icmpeq L%d\n", label++);
            }
            else
            {
                fprintf(fp, "    if_icmplt L%d\n", label++);
            }
            break;
        case OP_EQ:
            if (p_binaryoperator.get_left_operand()->TYPE.s_type == Type_real)
            {
                fprintf(fp, "    fcmpg\n");
                fprintf(fp, "    ldc 0\n");
                fprintf(fp, "    if_icmpeq L%d\n", label++);
            }
            else
            {
                fprintf(fp, "    if_icmpeq L%d\n", label++);
            }
            break;
        case OP_LET:
            if (p_binaryoperator.get_left_operand()->TYPE.s_type == Type_real)
            {
                fprintf(fp, "    fcmpg\n");
                fprintf(fp, "    ldc 1\n");
                fprintf(fp, "    if_icmplt L%d\n", label++);
            }
            else
            {
                fprintf(fp, "    if_icmple L%d\n", label++);
            }
            break;
        case OP_GET:
            if (p_binaryoperator.get_left_operand()->TYPE.s_type == Type_real)
            {
                fprintf(fp, "    fcmpg\n");
                fprintf(fp, "    ldc -1\n");
                fprintf(fp, "    if_icmpgt L%d\n", label++);
            }
            else
            {
                fprintf(fp, "    if_icmpge L%d\n", label++);
            }
            break;
        case OP_NEQ:
            if (p_binaryoperator.get_left_operand()->TYPE.s_type == Type_real)
            {
                fprintf(fp, "    fcmpg\n");
                fprintf(fp, "    ldc 0\n");
                fprintf(fp, "    if_icmpne L%d\n", label++);
            }
            else
            {
                fprintf(fp, "    if_icmpne L%d\n", label++);
            }
            break;
        default: printf("  ");
        }
        
    }

    if (p_binaryoperator.get_op() == OP_GT ||
        p_binaryoperator.get_op() == OP_LT ||
        p_binaryoperator.get_op() == OP_EQ ||
        p_binaryoperator.get_op() == OP_LET ||
        p_binaryoperator.get_op() == OP_GET ||
        p_binaryoperator.get_op() == OP_NEQ)
    {
        fprintf(fp, "    ldc 0\n");
        fprintf(fp, "    goto L%d\n", label);
        fprintf(fp, "L%d:\n", label - 1);
        fprintf(fp, "    ldc 1\n");
        fprintf(fp, "L%d:\n", label++);
    }
}

void CodeGenerator::visit(CompoundStatementNode &p_compound_statement)
{
    if (p_compound_statement.ismain)
    {
        fprintf(fp, ".method public static main([Ljava/lang/String;)V\n");
        fprintf(fp, ".limit locals 50\n");
        fprintf(fp, ".limit stack 50\n");
    }

    if (!tablelist.back().isinit)
    {
        for (auto entr = tablelist.back().entries.begin(); entr != tablelist.back().entries.end(); entr++)
        {
            if (entr->kind != KIND_FUNCTION && !entr->isparam && entr->kind != KIND_PROCEDURE)
            {
                if (tablelist.back().scope == 0)
                {

                    if (entr->type.dimensions.size() == 0)
                    {
                        switch (entr->type.s_type)
                        {
                        case Type_int:
                            fprintf(fp, "    ldc 0\n");
                            fprintf(fp, "    putstatic %s/%s I\n", classname.c_str(), entr->name.c_str());
                            break;
                        case Type_real:
                            fprintf(fp, "    ldc 0.0\n");
                            fprintf(fp, "    putstatic %s/%s F\n", classname.c_str(), entr->name.c_str());
                            break;
                        case Type_string:
                            fprintf(fp, "    ldc \"\"\n");
                            fprintf(fp, "    putstatic %s/%s Ljava/lang/String;\n", classname.c_str(), entr->name.c_str());
                            break;
                        default: printf("  ");
                        }
                    }
                    else
                    {
                        for (auto &a : entr->type.dimensions)
                        {
                            fprintf(fp, "    ldc %d\n", a.second - a.first + 1);
                        }
                        fprintf(fp, "    multianewarray %s %ld\n", entr->type.getTypeinfAssembly().c_str(), entr->type.dimensions.size());
                        fprintf(fp, "    putstatic %s/%s %s\n", classname.c_str(), entr->name.c_str(), entr->type.getTypeinfAssembly().c_str());
                    }
                }
                else
                {
                    if (entr->type.dimensions.size() == 0)
                    {
                        switch (entr->type.s_type)
                        {
                        case Type_int:
                            fprintf(fp, "    ldc 0\n");
                            fprintf(fp, "    istore %d\n", entr->serialnum);
                            break;
                        case Type_real:
                            fprintf(fp, "    ldc 0.0\n");
                            fprintf(fp, "    fstore_%d\n", entr->serialnum);
                            break;
                        default: printf("  ");
                        }
                    }
                    else
                    {
                        for (auto &a : entr->type.dimensions)
                        {
                            fprintf(fp, "    ldc %d\n", a.second - a.first + 1);
                        }
                        fprintf(fp, "    multianewarray %s %ld\n", entr->type.getTypeinfAssembly().c_str(), entr->type.dimensions.size());
                        fprintf(fp, "    astore_%d\n", entr->serialnum);
                    }
                }
            }
        }
        tablelist.back().isinit = true;
    }

    p_compound_statement.visitChildNodes(*this);
}

void CodeGenerator::visit(ConstantNode &p_constant)
{

    if (StringBufferinit == 0 && p_constant.type == Type_string && Stringjava)
    {
        fprintf(fp, "new java/lang/StringBuffer\n");
        fprintf(fp, "dup\n");
        fprintf(fp, "invokespecial java/lang/StringBuffer/<init>()V\n");
        StringBufferinit = 1;
    }
    switch (p_constant.type)
    {
    case Type_int:
        fprintf(fp, "    ldc %d\n", p_constant.value.val);
        break;
    case Type_real:
        fprintf(fp, "    ldc %f\n", p_constant.value.dval);
        break;
    case Type_string:
        fprintf(fp, "    ldc %s\n", p_constant.value.text);
        if (Stringjava == 1)
            fprintf(fp, "invokevirtual java/lang/StringBuffer/append(Ljava/lang/String;)Ljava/lang/StringBuffer;\n");
        break;
    default: printf("  ");
    }
    p_constant.visitChildNodes(*this);
    p_constant.TYPE = type_inf(p_constant.type);
}

void CodeGenerator::visit(IfNode &p_if)
{
    p_if.get_condition()->accept(*this);
    // int  nowlabel = label;
    // if (p_if.get_body_else())
    // {
        fprintf(fp, "    ifne L%d\n", label++);
        int nowlabel = label;
        label++;
        if(p_if.get_body_else())p_if.get_body_else()->accept(*this);
        fprintf(fp, "    goto L%d\n", nowlabel);
        fprintf(fp, "L%d:\n", nowlabel - 1);
    // }

    // if (p_if.get_body_then())
    // {
        if(p_if.get_body_then())p_if.get_body_then()->accept(*this);
        fprintf(fp, "    goto L%d\n", nowlabel);
        fprintf(fp, "L%d:\n", nowlabel);
    // }
}

void CodeGenerator::visit(SubProgramInvocationNode &p_subprogram_invoc)
{
    

    p_subprogram_invoc.visitChildNodes(*this);

    if (strcmp(p_subprogram_invoc.name.c_str(), "writelnI") == 0)
    {
        fprintf(fp, "    invokestatic io/writelnI(I)V\n");
    }
    else if (strcmp(p_subprogram_invoc.name.c_str(), "writelnR") == 0)
    {
        fprintf(fp, "    invokestatic io/writelnR(F)V\n");
    }
    else if (strcmp(p_subprogram_invoc.name.c_str(), "writelnS") == 0)
    {
        fprintf(fp, "    invokestatic io/writelnS(Ljava/lang/String;)V\n");
    }
    else
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
        if (!entr)
        {
            //  
        }
        else if (entr->kind == KIND_FUNCTION|| entr->kind == KIND_PROCEDURE) 
        {
            std::string rettype = entr->getTypeStringAssembly();
            switch (entr->type.s_type)
            {
            case Type_int:
                fprintf(fp, "    invokestatic %s/%s%s\n", classname.c_str(), entr->name.c_str(), rettype.c_str());
                break;
            case Type_real:
                fprintf(fp, "    invokestatic %s/%s%s\n", classname.c_str(), entr->name.c_str(), rettype.c_str());
                break;
            case Type_void:
                fprintf(fp, "    invokestatic %s/%s%s\n", classname.c_str(), entr->name.c_str(), rettype.c_str());
                break;
            case Type_string:
                fprintf(fp, "??? variablerefnode\n");
                break;
            default: printf("  ");
            }
        }
    }
}

void CodeGenerator::visit(UnaryOperatorNode &p_unaryoperator)
{
    p_unaryoperator.visitChildNodes(*this);
    p_unaryoperator.TYPE = p_unaryoperator.get_operand()->TYPE;
    std::string typ;
    switch (p_unaryoperator.TYPE.s_type)
    {
    case Type_int:
        typ = "i";
        break;
    case Type_real:
        typ = "f";
        break;
    default:
        typ = "???UnaryON";
        break;
    }
    if (p_unaryoperator.get_op() == OP_NOT)
    {
        fprintf(fp, "    ifne L%d\n", label++);
        fprintf(fp, "    ldc 1\n");
        fprintf(fp, "    goto L%d\n", label);
        fprintf(fp, "L%d:\n", label - 1);
        fprintf(fp, "    ldc 0\n");
        fprintf(fp, "L%d:\n", label++);
    }
    else if (p_unaryoperator.get_op() == OP_SUB)
    {
        fprintf(fp, "    %sneg\n", typ.c_str());
    }
}

void CodeGenerator::visit(WhileNode &p_while)
{
    int toplabel = label;
    int secondlabel;
    fprintf(fp, "L%d:\n", label++);
    p_while.get_condition()->accept(*this);
    secondlabel = label;
    fprintf(fp, "    ifeq L%d\n", label++);
    p_while.get_body()->accept(*this);
    fprintf(fp, "    goto L%d\n", toplabel);
    fprintf(fp, "L%d:\n", secondlabel);
}
