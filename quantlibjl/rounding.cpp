#if !defined(BOOST_ALL_NO_LIB) && defined(BOOST_MSVC)
#    include <ql/auto_link.hpp>
#endif

#include <ql/math/rounding.hpp>

// include jlcxx after the quantlib includes (see
// https://github.com/boostorg/system/issues/32#issuecomment-462512991)
#include <jlcxx/jlcxx.hpp>
#include <jlcxx/stl.hpp>

namespace jlcxx {
    template <>
    struct SuperType<QuantLib::UpRounding> {
        typedef QuantLib::Rounding type;
    };

    template <>
    struct SuperType<QuantLib::DownRounding> {
        typedef QuantLib::Rounding type;
    };

    template <>
    struct SuperType<QuantLib::ClosestRounding> {
        typedef QuantLib::Rounding type;
    };

    template <>
    struct SuperType<QuantLib::CeilingTruncation> {
        typedef QuantLib::Rounding type;
    };

    template <>
    struct SuperType<QuantLib::FloorTruncation> {
        typedef QuantLib::Rounding type;
    };

}


void rounding_module(jlcxx::Module& mod) {
    using namespace QuantLib;

    // Rounding::Type
    mod.add_bits<Rounding::Type>("RoundingType", jlcxx::julia_type("CppEnum"));
    mod.set_const("RoundingTypeNone", Rounding::Type::None);
    mod.set_const("RoundingTypeUp", Rounding::Type::Up);
    mod.set_const("RoundingTypeDown", Rounding::Type::Down);
    mod.set_const("RoundingTypeClosest", Rounding::Type::Closest);
    mod.set_const("RoundingTypeFloor", Rounding::Type::Floor);
    mod.set_const("RoundingTypeCeiling", Rounding::Type::Ceiling);

    mod.add_type<Rounding>("Rounding")
        .constructor<Integer, Rounding::Type, Integer>()
        .method(&Rounding::operator())
        .method("roundingPrecision", &Rounding::precision)
        .method("roundingType", &Rounding::type)
        .method("roundingDigit", &Rounding::roundingDigit);

    mod.add_type<UpRounding>("UpRounding", jlcxx::julia_base_type<Rounding>())
        .constructor<Integer, Integer>()
        .method(&UpRounding::operator());

    mod.add_type<DownRounding>("DownRounding", jlcxx::julia_base_type<Rounding>())
        .constructor<Integer, Integer>()
        .method(&DownRounding::operator());

    mod.add_type<ClosestRounding>("ClosestRounding", jlcxx::julia_base_type<Rounding>())
        .constructor<Integer, Integer>()
        .method(&ClosestRounding::operator());

    mod.add_type<CeilingTruncation>("CeilingTruncation", jlcxx::julia_base_type<Rounding>())
        .constructor<Integer, Integer>()
        .method(&CeilingTruncation::operator());

    mod.add_type<FloorTruncation>("FloorTruncation", jlcxx::julia_base_type<Rounding>())
        .constructor<Integer, Integer>()
        .method(&FloorTruncation::operator());
}