#define BOOST_TEST_MODULE direct_ExprSolver_SMT2
#include <metaSMT/expression/default_visitation_unrolling_limit.hpp>
#include <metaSMT/DirectSolver_Context.hpp>
#include <metaSMT/backend/SMT2.hpp>
#include <metaSMT/backend/ExpressionSolver.hpp>

using namespace metaSMT::solver;
using namespace metaSMT;
struct Solver_Fixture {
  typedef DirectSolver_Context< ExpressionSolver< SMT2 > > ContextType;
  ContextType ctx ;
};


#include "test_Boolean.cpp"
#include "test_assumption.cpp"
#include "test_QF_BV.cpp"
