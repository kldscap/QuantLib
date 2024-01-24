#if !defined(BOOST_ALL_NO_LIB) && defined(BOOST_MSVC)
#    include <ql/auto_link.hpp>
#endif

#include <ql/quotes/simplequote.hpp>

// include jlcxx after the quantlib includes (see
// https://github.com/boostorg/system/issues/32#issuecomment-462512991)
#include <jlcxx/jlcxx.hpp>
#include <jlcxx/stl.hpp>

namespace jlcxx {
    template <>
    struct SuperType<QuantLib::Quote> {
        typedef QuantLib::Observable type;
    };

    template <>
    struct SuperType<QuantLib::SimpleQuote> {
        typedef QuantLib::Quote type;
    };

    template <typename T>
    struct ConstructorPointerType<QuantLib::Handle<T>> {
        typedef std::shared_ptr<T> type;
    };

}

void marketelements_module(jlcxx::Module& mod) {
    using namespace jlcxx;
    using namespace QuantLib;

    mod.add_type<Quote>("Quote", jlcxx::julia_base_type<Observable>())
        .method("value", &Quote::value)
        .method("isValid", &Quote::isValid);

    mod.add_type<SimpleQuote>("SimpleQuote", jlcxx::julia_base_type<Quote>())
        .constructor<Real>()
        .method("setValue", &SimpleQuote::setValue);

    // jlcxx::stl::apply_stl<SimpleQuote>(mod);

    mod.add_type<Parametric<TypeVar<1>>>("Handle")
        .apply<Handle<SimpleQuote>>([](auto wrapped) {
            typedef typename decltype(wrapped)::type WrappedT;
            using ValueType = typename WrappedT::value_type;
            // wrapped.template constructor<const std::shared_ptr<typename WrappedT::value_type>&, bool>();
            wrapped.constructor([](const ValueType& o) {
                return new Handle<ValueType>(std::make_shared<ValueType>(o));
            });
            wrapped.method("currentLink", &WrappedT::currentLink);
            wrapped.method("empty", &WrappedT::empty);  
            wrapped.module().set_override_module(jl_base_module);
            wrapped.method("==", [](const WrappedT& a, const WrappedT& b) { return a == b; });
            wrapped.method("!=", [](const WrappedT& a, const WrappedT& b) { return a != b; });
            wrapped.method("<", [](const WrappedT& a, const WrappedT& b) { return a < b; });
            wrapped.module().unset_override_module();
        });
}