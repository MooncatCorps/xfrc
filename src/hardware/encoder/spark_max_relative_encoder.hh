#ifndef XFRC_HARDWARE_ENCODER_SPARK_MAX_RELATIVE_ENCODER_HH
#define XFRC_HARDWARE_ENCODER_SPARK_MAX_RELATIVE_ENCODER_HH

#include "encoder.hh"
#include "hardware/encoder/encoder.hh"
#include "hardware/motorcontrol/can_spark_max.hh"
#include "units/time.h"
#include <rev/SparkMaxRelativeEncoder.h>

namespace xfrc::hardware {

template <class unit, class time_unit = units::second>
class spark_max_relative_encoder : encoder<unit, time_unit> {
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
    explicit spark_max_relative_encoder(can_spark_max &from);

    rev::SparkMaxRelativeEncoder _implementation;
};

#define XFRC_HARDWARE_ENCODER_SPARK_MAX_RELATIVE_ENCODER_CXX
#include "spark_max_relative_encoder.hh"
#undef XFRC_HARDWARE_ENCODER_SPARK_MAX_RELATIVE_ENCODER_CXX

} // namespace xfrc::hardware

#endif
