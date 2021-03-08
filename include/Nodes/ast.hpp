#pragma once
#include <memory>
#include <string>
#include <vector>
#include "Visitor/AstNodeVisitor.hpp"
using namespace std;
#define SAFE_DELETE(NODE)      \
        if((NODE) != nullptr)  \
        {                      \
            delete (NODE);     \
            (NODE) = nullptr;  \
        }                      \

#define NODELIST_PTR_DELETE(NODELIST_PTR)               \
        if((NODELIST_PTR)!=nullptr)                     \
        {                                               \
            for(uint i=0;i<(NODELIST_PTR)->size();i++)  \
            {                                           \
                delete (*(NODELIST_PTR))[i];            \
                (*(NODELIST_PTR))[i] = nullptr;         \
            }                                           \
            delete (NODELIST_PTR);                      \
            (NODELIST_PTR)=nullptr;                     \
        }                                               \

class AstNodeVisitor;

typedef std::vector< class ASTNodeBase* > NodeList;
typedef class ASTNodeBase*           Node;
typedef union {
    int val;
    double dval;
    char* text;
} const_union;
enum enumOperator{
    OP_ASSIGN = 500,
    OP_ADD,
    OP_SUB,
    OP_MUL, 
    OP_DIV, 
    OP_LT, 
    OP_GT, 
    OP_EQ, 
    OP_GET, 
    OP_LET,
    OP_NEQ,
    OP_AND,
    OP_OR,
    OP_NOT,
};

enum enumType{
    Type_int = 400,
    Type_void,
    Type_real,
    Type_string,
    Type_Unknown
};

struct num_const {
    num_const(enumType type, const_union value)
    :type(type), value(value){}
    enumType type;
    const_union value;
};

class id_info
{
    public:
    id_info(std::string name, uint32_t line_number, uint32_t col_number)
    : name(name), line_number(line_number), col_number(col_number) {}
    std::string name;
    uint32_t line_number;
    uint32_t col_number;
};

class type_inf
{
    public:
    type_inf(enumType s_type, std::vector<std::pair<int,int>> dimensions)
    : s_type(s_type), dimensions(dimensions) {}
    type_inf(enumType s_type)
    : s_type(s_type) {}
    type_inf(type_inf* org)
    : s_type(org->s_type), dimensions(org->dimensions) {}
    type_inf()
    : s_type(Type_Unknown){}
    std::string getTypeinf()
    {
        std::string ret_type;
        switch(s_type)
        {
            case Type_int   :  ret_type = "int"; break;
            case Type_real  :  ret_type = "real"; break;
            case Type_string:  ret_type = "string"; break;
            case Type_void  :  ret_type = "void" ; break;
            default: ret_type = "Unknown";
        }
        for(auto &p : dimensions){
            ret_type += "[";
            ret_type += std::to_string(p.first);
            ret_type += "~";
            ret_type += std::to_string(p.second);
            ret_type += "]";
        }
        return ret_type;
    }
    std::string getTypeinfAssembly()
    {
        std::string ret_type = "";
        int a = dimensions.size();
        while(a--)
            ret_type += "[";
        
        switch(s_type)
        {
            case Type_int   :  ret_type += "I"; break;
            case Type_real  :  ret_type += "F"; break;
            case Type_string:  ret_type += "Ljava/lang/String;"; break;
            case Type_void  :  ret_type += "V" ; break;
            default: ret_type += "Unknown";
        }
        
        return ret_type;
    }
    public:
    enumType s_type;
    std::vector<std::pair<int,int>> dimensions;
    
};


struct Location {
    Location(uint32_t line, uint32_t col) : line(line),col(col){}
    uint32_t line;
    uint32_t col;
};
class ASTNodeBase
{
    public:
    virtual void accept(AstNodeVisitor &p_visitor) = 0;
    virtual void visitChildNodes(AstNodeVisitor &p_visitor){};
    //virtual ~AstNodeBase() = 0;
    ASTNodeBase(int line, int col): loc(line,col){}
    ~ASTNodeBase() {}
    const Location &getLocation() const { return loc; }
    protected:
    const Location loc;
    public:
    type_inf TYPE;
};
