#if !defined(BOOST_ALL_NO_LIB) && defined(BOOST_MSVC)
#    include <ql/auto_link.hpp>
#endif

#include <ql/currencies/all.hpp>

// include jlcxx after the quantlib includes (see
// https://github.com/boostorg/system/issues/32#issuecomment-462512991)
#include "module.hpp"
#include <jlcxx/jlcxx.hpp>
#include <jlcxx/stl.hpp>

namespace jlcxx {
    template <>
    struct SuperType<QuantLib::ARSCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::ATSCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::AUDCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::BDTCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::BEFCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::BGLCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::BRLCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::BYRCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::CADCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::CHFCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::CLPCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::CNYCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::COPCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::CYPCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::CZKCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::DEMCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::DKKCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::EEKCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::ESPCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::EURCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::FIMCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::FRFCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::GBPCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::GRDCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::HKDCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::HUFCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::IEPCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::IDRCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::ILSCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::INRCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::IQDCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::IRRCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::ISKCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::ITLCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::JPYCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::KRWCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::KWDCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::LTLCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::LUFCurrency> {
        typedef QuantLib::Currency type;
    };
    template <>
    struct SuperType<QuantLib::LVLCurrency> {
        typedef QuantLib::Currency type;
    };
    template <>
    struct SuperType<QuantLib::MTLCurrency> {
        typedef QuantLib::Currency type;
    };
    template <>
    struct SuperType<QuantLib::MXNCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::MYRCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::NLGCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::NOKCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::NPRCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::NZDCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::PEHCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::PEICurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::PENCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::PKRCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::PLNCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::PTECurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::ROLCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::RONCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::RUBCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::SARCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::SEKCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::SGDCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::SITCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::SKKCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::THBCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::TRLCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::TRYCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::TTDCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::TWDCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::USDCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::VEBCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::VNDCurrency> {
        typedef QuantLib::Currency type;
    };

    template <>
    struct SuperType<QuantLib::ZARCurrency> {
        typedef QuantLib::Currency type;
    };
}


void currencies_module(jlcxx::Module& mod) {
    using namespace QuantLib;

    mod.add_type<Currency>("Currency")
        // TODO: add const std::set<std::string>& minorUnitCodes = {} argument
        .constructor<const std::string&, const std::string&, Integer, const std::string&,
                     const std::string&, Integer, const Rounding&, const std::string&,
                     const Currency&>()
        .method("name", &Currency::name)
        .method("code", &Currency::code)
        .method("numericCode", &Currency::numericCode)
        .method("symbol", &Currency::symbol)
        .method("fractionSymbol", &Currency::fractionSymbol)
        .method("fractionsPerUnit", &Currency::fractionsPerUnit)
        .method("rounding", &Currency::rounding)
        .method("format", &Currency::format)
        .method("empty", &Currency::empty)
        .method("triangulationCurrency", &Currency::triangulationCurrency)
        .STRING(Currency);
    //.method("minorUnitCodes", &Currency::minorUnitCodes);

    mod.set_override_module(jl_base_module);
    // mod.method("empty", [](const Currency& c) { return c.empty(); });
    // mod.method("rounding", [](const Currency& c) { return c.rounding(); });
    mod.BINARY_OP(Currency, ==, ==);
    mod.BINARY_OP(Currency, !=, !=);
    mod.unset_override_module();

    mod.add_type<ARSCurrency>("ARSCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<ATSCurrency>("ATSCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<AUDCurrency>("AUDCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<BDTCurrency>("BDTCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<BEFCurrency>("BEFCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<BGLCurrency>("BGLCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<BRLCurrency>("BRLCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<BYRCurrency>("BYRCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<CADCurrency>("CADCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<CHFCurrency>("CHFCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<CLPCurrency>("CLPCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<CNYCurrency>("CNYCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<COPCurrency>("COPCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<CYPCurrency>("CYPCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<CZKCurrency>("CZKCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<DEMCurrency>("DEMCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<DKKCurrency>("DKKCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<EEKCurrency>("EEKCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<ESPCurrency>("ESPCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<EURCurrency>("EURCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<FIMCurrency>("FIMCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<FRFCurrency>("FRFCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<GBPCurrency>("GBPCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<GRDCurrency>("GRDCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<HKDCurrency>("HKDCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<HUFCurrency>("HUFCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<IEPCurrency>("IEPCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<IDRCurrency>("IDRCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<ILSCurrency>("ILSCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<INRCurrency>("INRCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<IQDCurrency>("IQDCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<IRRCurrency>("IRRCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<ISKCurrency>("ISKCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<ITLCurrency>("ITLCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<JPYCurrency>("JPYCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<KRWCurrency>("KRWCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<KWDCurrency>("KWDCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<LTLCurrency>("LTLCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<LUFCurrency>("LUFCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<LVLCurrency>("LVLCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<MTLCurrency>("MTLCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<MXNCurrency>("MXNCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<MYRCurrency>("MYRCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<NLGCurrency>("NLGCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<NOKCurrency>("NOKCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<NPRCurrency>("NPRCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<NZDCurrency>("NZDCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<PEHCurrency>("PEHCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<PEICurrency>("PEICurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<PENCurrency>("PENCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<PKRCurrency>("PKRCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<PLNCurrency>("PLNCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<PTECurrency>("PTECurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<ROLCurrency>("ROLCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<RONCurrency>("RONCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<RUBCurrency>("RUBCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<SARCurrency>("SARCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<SEKCurrency>("SEKCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<SGDCurrency>("SGDCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<SITCurrency>("SITCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<SKKCurrency>("SKKCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<THBCurrency>("THBCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<TRLCurrency>("TRLCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<TRYCurrency>("TRYCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<TTDCurrency>("TTDCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<TWDCurrency>("TWDCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<USDCurrency>("USDCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<VEBCurrency>("VEBCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<VNDCurrency>("VNDCurrency", jlcxx::julia_base_type<Currency>());
    mod.add_type<ZARCurrency>("ZARCurrency", jlcxx::julia_base_type<Currency>());

}