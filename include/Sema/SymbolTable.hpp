#pragma once
#include <Nodes/ast.hpp>
#include <vector>
#include <string>



enum enumKind{
    KIND_PROGRAM = 100,
    KIND_FUNCTION,
    KIND_PROCEDURE,
    KIND_PARAMETER,
    KIND_VARIABLE,
    KIND_CONSTANT
};

class SymbolEntry{
    public:
        Location loc;
        std::string name;
        int serialnum = 0;
        type_inf type;
        enumKind kind;  
        std::vector<type_inf> parameter_type;
        bool is_not_assign = true;
        bool lock = false;
        bool isconstant = false;
        bool isparam = false;
    public:
        SymbolEntry(
            Location _loc,
            std::string _name,
            type_inf _type,
            enumKind _kind);
        
        SymbolEntry(
            Location _loc,
            std::string _name,
            type_inf _type,
            enumKind _kind,
            std::vector<type_inf> _parameter_type);
        
        ~SymbolEntry();
        std::string getTypeString();
        std::string getTypeStringAssembly();
};

class SymbolTable{
    public:
        int scope;
        int serialnum = 0;
        std::vector<SymbolEntry> entries;
        static SymbolTable* Scope0Symbol;
        bool isinit = false;
        std::string func_name = "";
    public:
        SymbolTable(
            int _scope
        );
        SymbolTable();
        ~SymbolTable();

         SymbolEntry* find(std::string name);



};

