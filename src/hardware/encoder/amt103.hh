#ifndef XFRC_HARDWARE_ENCODER_AMT_103_HH
#define XFRC_HARDWARE_ENCODER_AMT_103_HH

#include "encoder.hh"
#include "hardware/encoder/encoder.hh"
#include "units/time.h"
#include <cstdint>
#include <frc/Encoder.h>

namespace xfrc::hardware {

template <class unit, class time_unit = units::second>
class amt103 : encoder<unit, time_unit> {
public:
    auto
    get_distance() -> units::unit_t<unit> override;

    auto
    get_velocity() -> units::unit_t<
        units::compound_unit<unit, units::inverse<time_unit>>> override;

    auto
    set_pulses_per_revolution(unsigned int pulses) -> void override;

    auto
    pulses_per_revolution() -> unsigned int override;

    auto
    set_distance_per_revolution(double distance) -> void override;

private:
    frc::Encoder _implementation;
    uint32_t     _resolution;
    double       _dpr = 1.0;
};

} // namespace xfrc::hardware

#define XFRC_HARDWARE_ENCODER_AMT_103_CXX
#include "amt103.cxx"
#undef XFRC_HARDWARE_ENCODER_AMT_103_CXX

#endif
