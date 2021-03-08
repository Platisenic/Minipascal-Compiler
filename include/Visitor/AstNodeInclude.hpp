#ifndef __VISITOR_AST_NODE_INCLUDE_H
#define __VISITOR_AST_NODE_INCLUDE_H

// used for all derived classes from base class AstNodeVisitor
// to include in their implementation file

#include "Nodes/assignment.hpp"
#include "Nodes/binary_operator.hpp"
#include "Nodes/compound_statement.hpp"
#include "Nodes/constant.hpp"
#include "Nodes/declartion.hpp"
#include "Nodes/if.hpp"
#include "Nodes/program.hpp"
#include "Nodes/subprogram_invoc.hpp"
#include "Nodes/subprogram.hpp"
#include "Nodes/unary_operator.hpp"
#include "Nodes/variable_ref.hpp"
#include "Nodes/variable.hpp"
#include "Nodes/while.hpp"

#endif
