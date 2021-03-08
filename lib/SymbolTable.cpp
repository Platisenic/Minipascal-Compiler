#include <Sema/SymbolTable.hpp>

// SymbolEntry
SymbolEntry::SymbolEntry(
            Location _loc,
            std::string _name,
            type_inf _type,
            enumKind _kind):
             loc(_loc),
            name(_name),
            type(_type),
            kind(_kind)
            {
                
            }

SymbolEntry::SymbolEntry(
            Location _loc,
            std::string _name,
            type_inf _type,
            enumKind _kind,
            std::vector<type_inf> _parameter_type):
             loc(_loc),
            name(_name),
            type(_type),
            kind(_kind),
            parameter_type(_parameter_type)
            {
                
            }

SymbolEntry::~SymbolEntry(){}

std::string SymbolEntry:: getTypeString()
{
    std::string ret_type;
    ret_type = type.getTypeinf();

    if((kind==KIND_FUNCTION || kind==KIND_PROCEDURE)&& parameter_type.size())
    {
        bool flag = false;
        ret_type += " (";
        for(auto &p :parameter_type)
        {
            if(flag)
                ret_type += ", ";
            else
                flag = true;
            ret_type += p.getTypeinf();
        }
        ret_type += ")";

    }
    return ret_type;
}

std::string SymbolEntry:: getTypeStringAssembly()
{
    std::string ret_type = "";

    if(kind==KIND_FUNCTION || kind==KIND_PROCEDURE)
    {
        
        ret_type += "(";
        for(auto &p :parameter_type)
        {
            ret_type += p.getTypeinfAssembly();
        }
        ret_type += ")";
    }
    

    ret_type += type.getTypeinfAssembly();
    
    return ret_type;
}


//SymbolTable

SymbolTable::SymbolTable(
            int _scope):
            scope(_scope){}

SymbolTable::~SymbolTable(){}

SymbolEntry* SymbolTable::find(std::string name)
{
    for(auto &p :entries)
    {
        if(name==p.name)
            return &p;
    }
    return nullptr;
}

