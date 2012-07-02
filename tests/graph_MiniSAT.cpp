#define BOOST_TEST_MODULE graph_MiniSAT
#include <metaSMT/GraphSolver_Context.hpp>
#include <metaSMT/backend/SAT_Clause.hpp>
#include <metaSMT/backend/MiniSAT.hpp>
#include <metaSMT/BitBlast.hpp>

using namespace metaSMT::solver;
using namespace metaSMT;
struct Solver_Fixture
{
  typedef GraphSolver_Context< BitBlast < SAT_Clause < MiniSAT > > > ContextType;
  ContextType ctx ;
};

#include "test_Boolean.cpp"
#include "test_assumption.cpp"
#include "test_QF_BV.cpp"
// #include "test_Array.cpp"
// #include "test_group.cpp"
#include "test_unsat.cpp"
#include "test_lazy.cpp"
