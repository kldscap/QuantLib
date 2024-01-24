#ifndef quantlibjl_modules_hpp
#define quantlib_modules_hpp

#define STRING(TYPE)                     \
    method("string", [](const TYPE& x) { \
        std::ostringstream stream;       \
        stream << x;                     \
        return stream.str();             \
    })

#define BINARY_OP(TYPE, FNAME, OP) \
        method(#FNAME, [](const TYPE& a, const TYPE& b) { return a OP b; })
#define UNARY_OP(TYPE, FNAME, OP) method(#FNAME, [](const TYPE& a) { return OP a; })
#include <jlcxx/module.hpp>


void time_module(jlcxx::Module& mod);
void observer_module(jlcxx::Module& mod);
void marketelements_module(jlcxx::Module& mod);
void ratehelpers_module(jlcxx::Module& mod);
void timeseries_module(jlcxx::Module& mod);
void rounding_module(jlcxx::Module& mod);
void currencies_module(jlcxx::Module& mod);
void daycounter_module(jlcxx::Module& mod);

#endif

