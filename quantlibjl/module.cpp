#include "module.hpp"

// include jlcxx after the quantlib includes (see
// https://github.com/boostorg/system/issues/32#issuecomment-462512991)
#include <jlcxx/jlcxx.hpp>
#include <jlcxx/stl.hpp>

namespace jlcxx {}


JLCXX_MODULE define_julia_module(jlcxx::Module& mod) {
    time_module(mod);
    observer_module(mod);
    marketelements_module(mod);
    timeseries_module(mod);
    rounding_module(mod);
    currencies_module(mod);
    daycounter_module(mod);

}