#if !defined(BOOST_ALL_NO_LIB) && defined(BOOST_MSVC)
#    include <ql/auto_link.hpp>
#endif

#include <ql/indexes/all.hpp>

// include jlcxx after the quantlib includes (see
// https://github.com/boostorg/system/issues/32#issuecomment-462512991)
#include "module.hpp"
#include <jlcxx/jlcxx.hpp>
#include <jlcxx/stl.hpp>

namespace jlcxx {
    template <>
    struct SuperType<QuantLib::Index> {
        typedef QuantLib::Observable type;
    };

    template <>
    struct SuperType<QuantLib::InterestRateIndex> {
        typedef QuantLib::Index type;
    };
}


void indexes_module(jlcxx::Module& mod) {
    using namespace QuantLib;

    mod.add_type<Index>("Index", jlcxx::julia_base_type<Observable>())
        .method("name", &Index::name)
        .method("fixingCalendar", &Index::fixingCalendar)
        .method("isValidFixingDate", &Index::isValidFixingDate)
        .method("hasHistoricalFixing", &Index::hasHistoricalFixing)
        .method("fixing", &Index::fixing)
        .method("addFixing", &Index::addFixing)
        .method("timeSeries", &Index::timeSeries)
        .method("clearFixings", &Index::clearFixings)
        .method("fixingCalendar", &Index::fixingCalendar)
        .method("fixingCalendar", &Index::fixingCalendar)
        .method("addFixings", static_cast<void (Index::*)(const TimeSeries<Real>&, bool)>(&Index::addFixings))
        .method("string", [](const Index& x) {
            std::ostringstream stream;
            stream << x.name() << " index";
            return stream.str();
        });

    mod.add_type<InterestRateIndex>("InterestRateIndex", jlcxx::julia_base_type<Index>())
        .method("familyName", &InterestRateIndex::familyName)
        .method("tenor", &InterestRateIndex::tenor)
        .method("fixingDays", &InterestRateIndex::fixingDays)
        .method("fixingDate", &InterestRateIndex::fixingDate)
        .method("currency", &InterestRateIndex::currency)
        .method("dayCounter", &InterestRateIndex::dayCounter)
        .method("maturityDate", &InterestRateIndex::maturityDate)
        .method("valueDate", &InterestRateIndex::valueDate);




}