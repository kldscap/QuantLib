#if !defined(BOOST_ALL_NO_LIB) && defined(BOOST_MSVC)
#    include <ql/auto_link.hpp>
#endif

#include <ql/patterns/observable.hpp>

// include jlcxx after the quantlib includes (see
// https://github.com/boostorg/system/issues/32#issuecomment-462512991)
#include <jlcxx/jlcxx.hpp>
#include <jlcxx/stl.hpp>

namespace jlcxx {

}


void observer_module(jlcxx::Module& mod) {
    using namespace QuantLib;

    mod.add_type<Observable>("Observable").method("notifyObservers", &Observable::notifyObservers);
    mod.add_type<Observer>("Observer")
        //.method("registerWith", &Observer::registerWith)
        .method("registerWithObservables", &Observer::registerWithObservables)
        .method("unregisterWith", &Observer::unregisterWith)
        .method("unregisterWithAll", &Observer::unregisterWithAll)
        .method("update", &Observer::update)
        .method("deepUpdate", &Observer::deepUpdate);

}