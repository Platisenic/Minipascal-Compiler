#pragma once
#include "info.h"
#include <stdio.h>
#include <string>

class PrintErrors
{
    public:
    static void print_REDEF_ARG(int line, int col, std::string str) {fprintf(stderr,REDEF_ARG, line, col, str.c_str());}
    /**/static void print_REDEF_FUN(int line, int col, std::string str) {fprintf(stderr,REDEF_FUN, line, col, str.c_str());}
    /**/static void print_REDEF_VAR(int line, int col, std::string str) {fprintf(stderr,REDEF_VAR, line, col, str.c_str());}
    /**/static void print_UNDEC_VAR(int line, int col, std::string str) {fprintf(stderr,UNDEC_VAR, line, col, str.c_str());}
    /**/static void print_UNDEC_FUN(int line, int col, std::string str) {fprintf(stderr,UNDEC_FUN, line, col, str.c_str());}
    /**/static void print_ARITH_TYPE(int line, int col, std::string str){fprintf(stderr,ARITH_TYPE, line, col, str.c_str());}
    /**/static void print_ASSIG_TYPE(int line, int col){fprintf(stderr,ASSIG_TYPE, line, col);}
    /**/static void print_INDEX_TYPE(int line, int col){fprintf(stderr,INDEX_TYPE, line, col);}
    /**/static void print_INDEX_MANY(int line, int col, std::string str){fprintf(stderr,INDEX_MANY, line, col, str.c_str());}
    /**/static void print_WRONG_ARGS(int line, int col, std::string str){fprintf(stderr,WRONG_ARGS, line, col, str.c_str());}
    static void print_RETURN_VAL(int line, int col, std::string str){fprintf(stderr,RETURN_VAL, line, col, str.c_str());}
};

