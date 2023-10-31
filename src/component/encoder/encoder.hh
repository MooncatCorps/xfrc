#ifndef XFRC_COMPONENT_ENCODER_ENCODER_HH
#define XFRC_COMPONENT_ENCODER_ENCODER_HH

#include "component/component.hh"
#include <units/base.h>
#include <units/time.h>

namespace xfrc {

template <class unit>
class encoder : public component {
    static_assert(units::traits::is_unit<unit>::value,
                  "Encoder unit must be from the units library");

public:
    explicit encoder();

    virtual auto
    get_distance() -> units::unit_t<unit>;
    virtual auto
    get_velocity() -> units::unit_t<
        units::compound_unit<unit, units::inverse<units::second>>>;
    virtual auto
    get_acceleration() -> units::unit_t<
        units::compound_unit<unit,
                             units::inverse<units::squared<units::second>>>>;

    virtual auto
    set_pulses_per_revolution() -> void;
    auto
    set_revolutions_per_pulse() -> void;

    virtual auto
    set_distance_per_revolution() -> void;

private:
};

} // namespace xfrc

#endif
