#include <metaSMT/support/disable_warnings.hpp>
#include <boost/proto/debug.hpp>
#include <boost/test/unit_test.hpp>
#include <metaSMT/support/enable_warnings.hpp>
#include <string>

#include <metaSMT/frontend/Logic.hpp>
 
using namespace std;
using namespace metaSMT;
using namespace metaSMT::solver;
using namespace metaSMT::logic;
namespace proto = boost::proto;
using boost::dynamic_bitset;

BOOST_FIXTURE_TEST_SUITE(solver, Solver_Fixture )

BOOST_AUTO_TEST_CASE( simple_unsat )
{
  // unsat
  assertion( ctx, False);
  BOOST_REQUIRE( !solve(ctx) );
}

BOOST_AUTO_TEST_CASE( variable_equality )
{
  predicate x = new_variable();
  predicate y = new_variable();

  bool cmp = (x == x);
  BOOST_CHECK( cmp );

  cmp = (x == y);
  BOOST_CHECK( !cmp );

  cmp = (y == x);
  BOOST_CHECK( !cmp );
}

BOOST_AUTO_TEST_SUITE_END() // Boolean 

