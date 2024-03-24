
#include <string>

#if !defined(BOOST_ALL_NO_LIB) && defined(BOOST_MSVC)
#  include <ql/auto_link.hpp>
#endif
#include <ql/qldefines.hpp>
#include <ql/time/date.hpp>
#include <ql/time/imm.hpp>
#include <ql/time/calendar.hpp>
#include <ql/time/calendars/all.hpp>
#include <ql/utilities/dataparsers.hpp>

#include "module.hpp"
// include jlcxx after the quantlib includes (see https://github.com/boostorg/system/issues/32#issuecomment-462512991)
#include <jlcxx/jlcxx.hpp>
#include <jlcxx/stl.hpp>



namespace jlcxx {
    template<> struct IsMirroredType<QuantLib::IMM> : std::false_type {};

    template<> struct SuperType<QuantLib::UnitedStates> { typedef QuantLib::Calendar type; };
    template<> struct SuperType<QuantLib::Germany> { typedef QuantLib::Calendar type; };
    template<> struct SuperType<QuantLib::UnitedKingdom> { typedef QuantLib::Calendar type; };
    template<> struct SuperType<QuantLib::China> { typedef QuantLib::Calendar type; };
    template<> struct SuperType<QuantLib::Canada> { typedef QuantLib::Calendar type; };
    template<> struct SuperType<QuantLib::Australia> { typedef QuantLib::Calendar type; };
    template<> struct SuperType<QuantLib::Italy> { typedef QuantLib::Calendar type; };
    template<> struct SuperType<QuantLib::France> { typedef QuantLib::Calendar type; };
    template<> struct SuperType<QuantLib::SouthKorea> { typedef QuantLib::Calendar type; };
    template<> struct SuperType<QuantLib::Singapore> { typedef QuantLib::Calendar type; };
    template<> struct SuperType<QuantLib::Brazil> { typedef QuantLib::Calendar type; };
    template<> struct SuperType<QuantLib::India> { typedef QuantLib::Calendar type; };
    template<> struct SuperType<QuantLib::Mexico> { typedef QuantLib::Calendar type; };
    template<> struct SuperType<QuantLib::HongKong> { typedef QuantLib::Calendar type; };
    template<> struct SuperType<QuantLib::Taiwan> { typedef QuantLib::Calendar type; };

    template<> struct SuperType<QuantLib::Japan> { typedef QuantLib::Calendar type; };
    template<> struct SuperType<QuantLib::NewZealand> { typedef QuantLib::Calendar type; };
    template<> struct SuperType<QuantLib::SouthAfrica> { typedef QuantLib::Calendar type; };
    template<> struct SuperType<QuantLib::Poland> { typedef QuantLib::Calendar type; };
    template<> struct SuperType<QuantLib::Turkey> { typedef QuantLib::Calendar type; };
    template<> struct SuperType<QuantLib::Thailand> { typedef QuantLib::Calendar type; };
    template<> struct SuperType<QuantLib::Norway> { typedef QuantLib::Calendar type; };
    template<> struct SuperType<QuantLib::Sweden> { typedef QuantLib::Calendar type; };
    template<> struct SuperType<QuantLib::Switzerland> { typedef QuantLib::Calendar type; };
    template<> struct SuperType<QuantLib::Hungary> { typedef QuantLib::Calendar type; };

    // template<> struct IsBits<QuantLib::UnitedStates::Market> : std::true_type {};

}

void time_module(jlcxx::Module& mod) {
    using namespace QuantLib;

    // Enums
    mod.add_bits<BusinessDayConvention>("BusinessDayConvention", jlcxx::julia_type("CppEnum"));
    mod.set_const("Following", Following);
    mod.set_const("ModifiedFollowing", ModifiedFollowing);
    mod.set_const("Preceding", Preceding);
    mod.set_const("ModifiedPreceding", ModifiedPreceding);
    mod.set_const("Unadjusted", Unadjusted);
    mod.set_const("HalfMonthModifiedFollowing", HalfMonthModifiedFollowing);
    mod.set_const("Nearest", Nearest);

    mod.add_bits<TimeUnit>("TimeUnit", jlcxx::julia_type("CppEnum"));
    mod.set_const("Days", Days);
    mod.set_const("Weeks", Weeks);
    mod.set_const("Months", Months);
    mod.set_const("Years", Years);
    mod.set_const("Hours", Hours);
    mod.set_const("Minutes", Minutes);
    mod.set_const("Seconds", Seconds);
    mod.set_const("Milliseconds", Milliseconds);
    mod.set_const("Microseconds", Microseconds);

    mod.add_bits<Frequency>("Frequency", jlcxx::julia_type("CppEnum"));
    mod.set_const("NoFrequency", NoFrequency);
    mod.set_const("Once", Once);
    mod.set_const("Annual", Annual);
    mod.set_const("Semiannual", Semiannual);
    mod.set_const("EveryFourthMonth", EveryFourthMonth);
    mod.set_const("Quarterly", Quarterly);
    mod.set_const("Bimonthly", Bimonthly);
    mod.set_const("Monthly", Monthly);
    mod.set_const("EveryFourthWeek", EveryFourthWeek);
    mod.set_const("Biweekly", Biweekly);
    mod.set_const("Weekly", Weekly);
    mod.set_const("Daily", Daily);
    mod.set_const("OtherFrequency", OtherFrequency);

    mod.add_bits<Month>("Month", jlcxx::julia_type("CppEnum"));
    mod.set_const("January", January);
    mod.set_const("February", February);
    mod.set_const("March", March);
    mod.set_const("April", April);
    mod.set_const("May", May);
    mod.set_const("June", June);
    mod.set_const("July", July);
    mod.set_const("August", August);
    mod.set_const("September", September);
    mod.set_const("October", October);
    mod.set_const("November", November);
    mod.set_const("December", December);
    mod.set_const("Jan", Jan);
    mod.set_const("Feb", Feb);
    mod.set_const("Mar", Mar);
    mod.set_const("Apr", Apr);
    mod.set_const("Jun", Jun);
    mod.set_const("Jul", Jul);
    mod.set_const("Aug", Aug);
    mod.set_const("Sep", Sep);
    mod.set_const("Oct", Oct);
    mod.set_const("Nov", Nov);
    mod.set_const("Dec", Dec);

    mod.add_bits<Weekday>("Weekday", jlcxx::julia_type("CppEnum"));
    mod.set_const("Sunday", Sunday);
    mod.set_const("Monday", Monday);
    mod.set_const("Tuesday", Tuesday);
    mod.set_const("Wednesday", Wednesday);
    mod.set_const("Thursday", Thursday);
    mod.set_const("Friday", Friday);
    mod.set_const("Saturday", Saturday);
    mod.set_const("Sun", Sun);
    mod.set_const("Mon", Mon);
    mod.set_const("Tue", Tue);
    mod.set_const("Wed", Wed);
    mod.set_const("Thu", Thu);
    mod.set_const("Fri", Fri);
    mod.set_const("Sat", Sat);

    // Period 
    mod.add_type<Period>("Period")
        .constructor<Integer, TimeUnit>()
        .constructor<Frequency>()
        .constructor([](const std::string& str) { return new Period(PeriodParser::parse(str)); })  
        .method("length", &Period::length)
        .method("units", &Period::units)
        .method("frequency", &Period::frequency)
        .method("normalize", &Period::normalize)
        .method("normalized", &Period::normalized)
        .STRING(Period);

    // friends of Period
    mod.set_override_module(jl_base_module);
    mod.BINARY_OP(Period, +, +);
    mod.BINARY_OP(Period, -, -);
    mod.BINARY_OP(Period, ==, ==);
    mod.BINARY_OP(Period, !=, !=);
    mod.BINARY_OP(Period, <=, <=);
    mod.BINARY_OP(Period, >=, >=);
    mod.BINARY_OP(Period, <, <);
    mod.BINARY_OP(Period, >, >);
    mod.method("*", [](const Period& p, const Integer& i) { return p * i; });
    mod.method("*", [](const Integer& i, const Period& p) { return i * p; });
    mod.method("/", [](const Period& p, const Integer& i) { return p / i; });
    mod.UNARY_OP(Period, -, -);
    mod.unset_override_module();

    // Date
    // jlcxx::stl::apply_stl<Date>(mod);
    mod.add_type<Date>("Date")
        .constructor<Day, Month, Year>()
        .method("weekday", &Date::weekday)
        .method("dayOfMonth", &Date::dayOfMonth)
        .method("dayOfYear", &Date::dayOfYear)
        .method("month", &Date::month)
        .method("year", &Date::year)
        .method("serialNumber", &Date::serialNumber)
#ifdef QL_HIGH_RESOLUTION_DATE
        .constructor<Day, Month, Year, Hour, Minute, Second, Millisecond, Microsecond>()
        .method("hours", &Date::hours)
        .method("minutes", &Date::minutes)
        .method("seconds", &Date::seconds)
        .method("milliseconds", &Date::milliseconds)
        .method("microseconds", &Date::microseconds)
        .method("fractionOfDay", &Date::fractionOfDay)
        .method("fractionOfSecond", &Date::fractionOfSecond)
        // .method("dateTime", &Date::dateTime)  // ERROR: No appropriate factory for type class boost::posix_time::ptime
        
        
        // .method("ticksPerSecond", &Date::ticksPerSecond)  // ERROR: No appropriate factory for type class boost::posix_time::ptime
#endif
        .STRING(Date);
    mod.method("localDateTime", &Date::localDateTime);
    mod.method("universalDateTime", &Date::universalDateTime);
    mod.method("todaysDate", &Date::todaysDate);
    mod.method("minDate", &Date::minDate);
    mod.method("maxDate", &Date::maxDate);
    mod.method("isLeap", &Date::isLeap);
    mod.method("endOfMonth", &Date::endOfMonth);
    mod.method("isEndOfMonth", &Date::isEndOfMonth);
    mod.method("nextWeekday", &Date::nextWeekday);
    mod.method("nthWeekday", &Date::nthWeekday);

    // friends of Date
    mod.method("daysBetween", &daysBetween);
    mod.set_override_module(jl_base_module);
    mod.method("+", [](const Date& d, const Date::serial_type days) { return d + days; });
    mod.method("-", [](const Date& d, Date::serial_type days) { return d - days; });
    mod.method("+", [](const Date& d, const Period& p) { return d + p; });
    mod.method("-", [](const Date& d, const Period& p) { return d - p; });

    mod.BINARY_OP(Date, -, -);
    mod.BINARY_OP(Date, ==, ==);
    mod.BINARY_OP(Date, !=, !=);
    mod.BINARY_OP(Date, <=, <=);
    mod.BINARY_OP(Date, >=, >=);
    mod.BINARY_OP(Date, <, <);
    mod.BINARY_OP(Date, >, >);
    mod.unset_override_module();


    // IMM
    mod.add_type<IMM>("IMM");
    mod.method("isIMMdate", &IMM::isIMMdate);
    mod.method("isIMMcode", &IMM::isIMMcode);
    mod.method("code", &IMM::code);
    mod.method("date", &IMM::date);
    mod.method("nextDate", static_cast<Date (*)(const Date&, bool)>(&IMM::nextDate));
    mod.method("nextCode", static_cast<std::string (*)(const Date&, bool)>(&IMM::nextCode));
    mod.method("nextCode", static_cast<std::string (*)(const std::string&, bool, const Date&)>(&IMM::nextCode));

    // Calendar
    mod.add_type<Calendar>("Calendar")
        .method("empty", &Calendar::empty)
        .method("name", &Calendar::name)
        // libcxx_wrap doesn not currently support std::set (out of the box) 
        .method("addedHolidays", [](const Calendar& c) {
                    return std::vector<Date>{c.addedHolidays().begin(), c.addedHolidays().end()};
        })
        .method("removedHolidays",
                [](const Calendar& c) {
                return std::vector<Date>{c.removedHolidays().begin(), c.removedHolidays().end()};
                })
        .method("resetAddedAndRemovedHolidays", &Calendar::resetAddedAndRemovedHolidays)
        .method("isBusinessDay", &Calendar::isBusinessDay)
        .method("isHoliday", &Calendar::isHoliday)
        .method("isWeekend", &Calendar::isWeekend)
        .method("isEndOfMonth", &Calendar::isEndOfMonth)
        .method("addHoliday", &Calendar::addHoliday)
        .method("removeHoliday", &Calendar::removeHoliday)
        .method("holidayList", &Calendar::holidayList)
        .method("businessDayList", &Calendar::businessDayList)
        .method("adjust", &Calendar::adjust)
        .method("advance", static_cast<Date (Calendar::*)(const Date&, const Period&, BusinessDayConvention, bool) const>(&Calendar::advance))
        .method("advance", static_cast<Date (Calendar::*)(const Date&, Integer, TimeUnit, BusinessDayConvention, bool) const>(&Calendar::advance))
        .method("businessDaysBetween", &Calendar::businessDaysBetween);

    // UnitedStates Calendar
    mod.add_bits<UnitedStates::Market>("US_Market", jlcxx::julia_type("CppEnum"));
    mod.set_const("US_Settlement", UnitedStates::Settlement);
    mod.set_const("US_NYSE", UnitedStates::NYSE);
    mod.set_const("US_GovernmentBond", UnitedStates::GovernmentBond);
    mod.set_const("US_NERC", UnitedStates::NERC);
    mod.set_const("US_LiborImpact", UnitedStates::LiborImpact);
    mod.set_const("US_FederalReserve", UnitedStates::FederalReserve);
    mod.set_const("US_SOFR", UnitedStates::SOFR);
    mod.add_type<UnitedStates>("UnitedStates", jlcxx::julia_base_type<Calendar>()).constructor<UnitedStates::Market>();

    // Germany Calendar
    mod.add_bits<Germany::Market>("DE_Market", jlcxx::julia_type("CppEnum"));
    mod.set_const("DE_Settlement", Germany::Settlement);
    mod.set_const("DE_FrankfurtStockExchange", Germany::FrankfurtStockExchange);
    mod.set_const("DE_Xetra", Germany::Xetra);
    mod.set_const("DE_Eurex", Germany::Eurex);
    mod.set_const("DE_Euwax", Germany::Euwax);
    mod.add_type<Germany>("Germany", jlcxx::julia_base_type<Calendar>()).constructor<Germany::Market>();

    // United Kingdom Calendar
    mod.add_bits<UnitedKingdom::Market>("UK_Market", jlcxx::julia_type("CppEnum"));
    mod.set_const("UK_Settlement", UnitedKingdom::Settlement);
    mod.set_const("UK_Exchange", UnitedKingdom::Exchange);
    mod.set_const("UK_Metals", UnitedKingdom::Metals);
    mod.add_type<UnitedKingdom>("UnitedKingdom", jlcxx::julia_base_type<Calendar>()).constructor<UnitedKingdom::Market>();

    // China Calendar
    mod.add_bits<China::Market>("CH_Market", jlcxx::julia_type("CppEnum"));
    mod.set_const("CH_SSE", China::SSE);
    mod.set_const("CH_IB", China::IB);
    mod.add_type<China>("China", jlcxx::julia_base_type<Calendar>()).constructor<China::Market>();

    // Canada Calendar
    mod.add_bits<Canada::Market>("CA_Market", jlcxx::julia_type("CppEnum"));
    mod.set_const("CA_Settlement", Canada::Settlement);
    mod.set_const("CA_TSX", Canada::TSX);
    mod.add_type<Canada>("Canada", jlcxx::julia_base_type<Calendar>()).constructor<Canada::Market>();

    // Australia Calendar
    mod.add_bits<Australia::Market>("AU_Market", jlcxx::julia_type("CppEnum"));
    mod.set_const("AU_Settlement", Australia::Settlement);
    mod.set_const("AU_ASX", Australia::ASX);
    mod.add_type<Australia>("Australia", jlcxx::julia_base_type<Calendar>()).constructor<Australia::Market>();

    // Italy Calendar
    mod.add_bits<Italy::Market>("IT_Market", jlcxx::julia_type("CppEnum"));
    mod.set_const("IT_Settlement", Italy::Settlement);
    mod.set_const("IT_Exchange", Italy::Exchange);
    mod.add_type<Italy>("Italy", jlcxx::julia_base_type<Calendar>()).constructor<Italy::Market>();

    // France Calendar
    mod.add_bits<France::Market>("FR_Market", jlcxx::julia_type("CppEnum"));
    mod.set_const("FR_Settlement", France::Settlement);
    mod.set_const("FR_Exchange", France::Exchange);
    mod.add_type<France>("France", jlcxx::julia_base_type<Calendar>()).constructor<France::Market>();

    // SouthKorea Calendar
    mod.add_bits<SouthKorea::Market>("SE_Market", jlcxx::julia_type("CppEnum"));
    mod.set_const("SE_Settlement", SouthKorea::Settlement);
    mod.set_const("SE_KRX", SouthKorea::KRX);
    mod.add_type<SouthKorea>("SouthKorea", jlcxx::julia_base_type<Calendar>()).constructor<SouthKorea::Market>();

    // Singapore Calendar
    mod.add_bits<Singapore::Market>("SX_Market", jlcxx::julia_type("CppEnum"));
    mod.set_const("SX_SGX", Singapore::SGX);
    mod.add_type<Singapore>("Singapore", jlcxx::julia_base_type<Calendar>()).constructor<Singapore::Market>();

    // Brazil Calendar
    mod.add_bits<Brazil::Market>("BZ_Market", jlcxx::julia_type("CppEnum"));
    mod.set_const("BZ_Settlement", Brazil::Settlement);
    mod.set_const("BZ_Exchange", Brazil::Exchange);
    mod.add_type<Brazil>("Brazil", jlcxx::julia_base_type<Calendar>()).constructor<Brazil::Market>();

    // India Calendar
    mod.add_bits<India::Market>("IN_Market", jlcxx::julia_type("CppEnum"));
    mod.set_const("IN_NSE", India::NSE);
    mod.add_type<India>("India", jlcxx::julia_base_type<Calendar>()).constructor<India::Market>();

    // Mexico Calendar
    mod.add_bits<Mexico::Market>("MX_Market", jlcxx::julia_type("CppEnum"));
    mod.set_const("MX_BMV", Mexico::BMV);
    mod.add_type<Mexico>("Mexico", jlcxx::julia_base_type<Calendar>()).constructor<Mexico::Market>();

    // HongKong Calendar
    mod.add_bits<HongKong::Market>("HK_Market", jlcxx::julia_type("CppEnum"));
    mod.set_const("HK_HKEx", HongKong::HKEx);
    mod.add_type<HongKong>("HongKong", jlcxx::julia_base_type<Calendar>()).constructor<HongKong::Market>();

    // Taiwan Calendar
    mod.add_bits<Taiwan::Market>("TA_Market", jlcxx::julia_type("CppEnum"));
    mod.set_const("TA_TSEC", Taiwan::TSEC);
    mod.add_type<Taiwan>("Taiwan", jlcxx::julia_base_type<Calendar>()).constructor<Taiwan::Market>();

    // Japan Calendar
    mod.add_type<Japan>("Japan", jlcxx::julia_base_type<Calendar>()).constructor();
    
    // NewZealand Calendar
    mod.add_type<NewZealand>("NewZealand", jlcxx::julia_base_type<Calendar>()).constructor();

    // SouthAfrica Calendar
    mod.add_type<SouthAfrica>("SouthAfrica", jlcxx::julia_base_type<Calendar>()).constructor();

    // Poland Calendar
    mod.add_type<Poland>("Poland", jlcxx::julia_base_type<Calendar>()).constructor();

    // Turkey Calendar
    mod.add_type<Turkey>("Turkey", jlcxx::julia_base_type<Calendar>()).constructor();

    // Thailand Calendar
    mod.add_type<Thailand>("Thailand", jlcxx::julia_base_type<Calendar>()).constructor();

    // Norway Calendar
    mod.add_type<Norway>("Norway", jlcxx::julia_base_type<Calendar>()).constructor();

    // Sweden Calendar
    mod.add_type<Sweden>("Sweden", jlcxx::julia_base_type<Calendar>()).constructor();

    // Switzerland Calendar
    mod.add_type<Switzerland>("Switzerland", jlcxx::julia_base_type<Calendar>()).constructor();

    // Hungary Calendar
    mod.add_type<Hungary>("Hungary", jlcxx::julia_base_type<Calendar>()).constructor();

}