#ifndef XFRC_COMPONENT_ENCODER_ENCODER_HH
#define XFRC_COMPONENT_ENCODER_ENCODER_HH

#include "entity/entity.hh"
#include <units/base.h>
#include <units/time.h>

namespace xfrc::hardware {

template <class unit, class time_unit = units::second>
class encoder : public entity::entity {
    static_assert(units::traits::is_unit<unit>::value,
                  "Encoder unit must be from the units library");

    static_assert(units::traits::is_unit_v<time_unit>,
                  "Encoder time unit must be from the units library");

    static_assert(units::traits::is_time_unit_v<time_unit>,
                  "Encoder time unit must be a time unit");

public:
    explicit encoder();

    virtual auto
    get_distance() -> units::unit_t<unit> = 0;

    virtual auto
    get_velocity() -> units::unit_t<
        units::compound_unit<unit, units::inverse<time_unit>>> = 0;

    virtual auto
    set_pulses_per_revolution(unsigned int pulses) -> void = 0;

    virtual auto
    pulses_per_revolution() -> unsigned int = 0;

    virtual auto
    set_distance_per_revolution(double distance) -> void = 0;
};

} // namespace xfrc::hardware

#endif
