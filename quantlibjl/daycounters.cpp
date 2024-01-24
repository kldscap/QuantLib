#if !defined(BOOST_ALL_NO_LIB) && defined(BOOST_MSVC)
#    include <ql/auto_link.hpp>
#endif

#include <ql/time/daycounters/all.hpp>


// include jlcxx after the quantlib includes (see
// https://github.com/boostorg/system/issues/32#issuecomment-462512991)
#include "module.hpp"
#include <jlcxx/jlcxx.hpp>

namespace jlcxx {
    template <>
    struct SuperType<QuantLib::Actual360> {
        typedef QuantLib::DayCounter type;
    };
    template <>
    struct SuperType<QuantLib::Actual364> {
        typedef QuantLib::DayCounter type;
    };
    template <>
    struct SuperType<QuantLib::Actual365Fixed> {
        typedef QuantLib::DayCounter type;
    };
    template <>
    struct SuperType<QuantLib::Thirty360> {
        typedef QuantLib::DayCounter type;
    };
    template <>
    struct SuperType<QuantLib::Thirty365> {
        typedef QuantLib::DayCounter type;
    };
    template <>
    struct SuperType<QuantLib::ActualActual> {
        typedef QuantLib::DayCounter type;
    };
    template <>
    struct SuperType<QuantLib::OneDayCounter> {
        typedef QuantLib::DayCounter type;
    };
    template <>
    struct SuperType<QuantLib::SimpleDayCounter> {
        typedef QuantLib::DayCounter type;
    };
    template <>
    struct SuperType<QuantLib::Business252> {
        typedef QuantLib::DayCounter type;
    };
}


void daycounter_module(jlcxx::Module& mod) {
    using namespace QuantLib;

    mod.add_type<DayCounter>("DayCounter")
        .method("dayCount", &DayCounter::dayCount)
        .method("yearFraction", &DayCounter::yearFraction)
        .method("name", &DayCounter::name)
        .STRING(DayCounter);

    mod.set_override_module(jl_base_module);
    mod.BINARY_OP(DayCounter, ==, ==);
    mod.BINARY_OP(DayCounter, !=, !=);
    mod.unset_override_module();

    mod.add_type<Actual360>("Actual360", jlcxx::julia_base_type<DayCounter>()).constructor<bool>();

    mod.add_type<Actual364>("Actual364", jlcxx::julia_base_type<DayCounter>());

    mod.add_bits<Actual365Fixed::Convention>("Actual365FixedConvention",
                                             jlcxx::julia_type("CppEnum"));
    mod.set_const("Actual365Fixed_Standard", Actual365Fixed::Convention::Standard);
    mod.set_const("Actual365Fixed_Canadian", Actual365Fixed::Convention::Canadian);
    mod.set_const("Actual365Fixed_NoLeap", Actual365Fixed::Convention::NoLeap);
    mod.add_type<Actual365Fixed>("Actual365Fixed", jlcxx::julia_base_type<DayCounter>())
        .constructor<Actual365Fixed::Convention>();

    mod.add_bits<Thirty360::Convention>("Thirty360Convention", jlcxx::julia_type("CppEnum"));
    mod.set_const("Thirty360_USA", Thirty360::Convention::USA);
    mod.set_const("Thirty360_BondBasis", Thirty360::Convention::BondBasis);
    mod.set_const("Thirty360_European", Thirty360::Convention::European);
    mod.set_const("Thirty360_EurobondBasis", Thirty360::Convention::EurobondBasis);
    mod.set_const("Thirty360_Italian", Thirty360::Convention::Italian);
    mod.set_const("Thirty360_German", Thirty360::Convention::German);
    mod.add_type<Thirty360>("Thirty360", jlcxx::julia_base_type<DayCounter>())
        .constructor<Thirty360::Convention, Date>();

    mod.add_type<Thirty365>("Thirty365", jlcxx::julia_base_type<DayCounter>());

    mod.add_bits<ActualActual::Convention>("ActualActualConvention", jlcxx::julia_type("CppEnum"));
    mod.set_const("ActualActual_ISMA", ActualActual::Convention::ISMA);
    mod.set_const("ActualActual_Bond", ActualActual::Convention::Bond);
    mod.set_const("ActualActual_ISDA", ActualActual::Convention::ISDA);
    mod.set_const("ActualActual_Historical", ActualActual::Convention::Historical);
    mod.set_const("ActualActual_Actual365", ActualActual::Convention::Actual365);
    mod.set_const("ActualActual_AFB", ActualActual::Convention::AFB);
    mod.set_const("ActualActual_Euro", ActualActual::Convention::Euro);
    mod.add_type<ActualActual>("ActualActual", jlcxx::julia_base_type<DayCounter>())
        .constructor<ActualActual::Convention>();

    mod.add_type<OneDayCounter>("OneDayCounter", jlcxx::julia_base_type<DayCounter>());

    mod.add_type<SimpleDayCounter>("SimpleDayCounter", jlcxx::julia_base_type<DayCounter>());

    mod.add_type<Business252>("Business252", jlcxx::julia_base_type<DayCounter>())
        .constructor<const Calendar&>();
}