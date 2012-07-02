#define BOOST_TEST_MODULE direct_SMT2
#include <metaSMT/expression/default_visitation_unrolling_limit.hpp>
#include <metaSMT/DirectSolver_Context.hpp>
#include <metaSMT/API/Stack.hpp>
#include <metaSMT/backend/SMT2.hpp>

using namespace metaSMT::solver;
using namespace metaSMT;
struct Solver_Fixture
{
  typedef DirectSolver_Context< SMT2 > ContextType;
  ContextType ctx ;
};

#include "test_Boolean.cpp"
#include "test_assumption.cpp"
#include "test_QF_BV.cpp"
#include "test_QF_UF.cpp"
#include "test_annotate.cpp"
#include "test_stack.cpp"
#include "test_Array.cpp"
//#include "test_group.cpp"
//#include "test_unsat.cpp"
//#include "test_lazy.cpp"
#include "test_Types.cpp"
#include "test_cardinality.cpp"
#include "test_expression.cpp"
#include "test_simplify.cpp"
