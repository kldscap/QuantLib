#if !defined(BOOST_ALL_NO_LIB) && defined(BOOST_MSVC)
#  include <ql/auto_link.hpp>
#endif
#include <ql/qldefines.hpp>

#include<ql/termstructures/bootstraphelper.hpp>

// include jlcxx after the quantlib includes (see https://github.com/boostorg/system/issues/32#issuecomment-462512991)
#include <jlcxx/jlcxx.hpp>
#include <jlcxx/stl.hpp>

namespace jlcxx {}


void ratehelpers_module(jlcxx::Module& mod) {
    using namespace QuantLib;

    // TODO
    //mod.add_type<SimpleQuote>("SimpleQuote", jlcxx::julia_base_type<Quote>())
    //    .constructor<Real>()
    //    .method("setValue", &SimpleQuote::setValue);

}