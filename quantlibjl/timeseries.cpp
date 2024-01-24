#if !defined(BOOST_ALL_NO_LIB) && defined(BOOST_MSVC)
#    include <ql/auto_link.hpp>
#endif

#include <ql/timeseries.hpp>

// include jlcxx after the quantlib includes (see
// https://github.com/boostorg/system/issues/32#issuecomment-462512991)
#include <jlcxx/jlcxx.hpp>
#include <jlcxx/stl.hpp>

namespace jlcxx {}


void timeseries_module(jlcxx::Module& mod) {
    using namespace QuantLib;
    using namespace jlcxx;

    mod.add_type<Parametric<TypeVar<1>>>("TimeSeries").apply<TimeSeries<Real>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        using KeyType = typename WrappedT::key_type;
        using ValueType = typename WrappedT::value_type;
        wrapped.method("TimeSeries",
                       [](const std::vector<KeyType>& d, const std::vector<ValueType>& v) {
                           return TimeSeries<ValueType>(d.begin(), d.end(), v.begin());
                       });
        wrapped.method("dates", &WrappedT::dates);

        wrapped.module().set_override_module(jl_base_module);
        wrapped.method("size", &WrappedT::size);
        wrapped.method("values", &WrappedT::values);
        wrapped.method("getindex", [](const WrappedT& ts, const Date& d) { return ts[d]; });
        wrapped.method("setindex!", [](WrappedT& ts, const ValueType& v, const Date& d) { ts[d] = v; });
        wrapped.module().unset_override_module();
    });
}