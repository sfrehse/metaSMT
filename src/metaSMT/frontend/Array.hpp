#pragma once

#include "../support/SMT_Graph.hpp"
#include "../tags/Array.hpp"
#include "../tags/Logics.hpp"
#include "../impl/_var_id.hpp"
#include "Logic.hpp"
#include <boost/proto/core.hpp>
#include <string>



namespace proto = boost::proto;

namespace metaSMT {

  namespace logic {
    namespace Array {

      struct Array_Grammar;

      // real Grammar
      struct Array_Grammar
      : proto::or_<
          proto::terminal< tag::array_var_tag > 
        , proto::terminal< SMT_Expression > 
        , proto::binary_expr<tag::select_tag, Array_Grammar, Array_Grammar>
        //, proto::ternary_expr<tag::store_tag, Array_Grammar, Array_Grammar, Array_Grammar>
        , proto::nary_expr<tag::store_tag, proto::vararg<proto::_> >
        >
      {};

      template<typename Expr>
      struct Array;

      struct Array_Domain
      : proto::domain<proto::generator<Array>, Array_Grammar>
      {};

      template<typename Expr>
        struct Array
        : proto::extends<Expr, Array<Expr>, Array_Domain >
        {
          typedef proto::extends<Expr, Array<Expr>, Array_Domain > base_type;

          Array(Expr const & expr = Expr())
            : base_type(expr)
          {}
        };

      template<typename Expr> 
      void check (Array<Expr> const & ) {
        BOOST_MPL_ASSERT((proto::matches<Expr, Array_Grammar>));
      }
      template<typename Expr> 
      void check_not (Array<Expr> const & ) {
        BOOST_MPL_ASSERT_NOT((proto::matches<Expr, Array_Grammar>));
      }

    /** 
     * @ingroup Frontend
     * @defgroup Array Array over bit-vectors Frontend
     * @{
     */


      template<typename E1, typename E2>
      typename proto::result_of::make_expr< tag::select_tag, Array_Domain, E1 const &, E2 const & >::type
      select( E1 const &e1, E2 const &e2) {
        return proto::make_expr< tag::select_tag, Array_Domain >(boost::cref(e1), boost::cref(e2));
      }

      template<typename E1, typename E2, typename E3>
      typename proto::result_of::make_expr< tag::store_tag, Array_Domain,
          E1 const &, E2 const &, E3 const &
      >::type
      store( E1 const &e1, E2 const &e2 , E3 const &e3)
      {
        return proto::make_expr< tag::store_tag, Array_Domain >(boost::cref(e1), boost::cref(e2), boost::cref(e3) );
      }

      typedef
      proto::result_of::make_expr< proto::tag::terminal, Array_Domain
        , tag::array_var_tag
      > ::type array;

      inline array
      new_array( unsigned elem_width = 1,
                 unsigned index_width = 1 )
      {
        tag::array_var_tag tag;
        tag.id = impl::new_var_id();
        tag.elem_width = elem_width;
        tag.index_width = index_width;
        return proto::make_expr< proto::tag::terminal, Array_Domain >( tag );
      }
   
      /**@}*/

    } // namespace Array
  } // namepace logic
} // namespace metaSMT

//  vim: ft=cpp:ts=2:sw=2:expandtab
