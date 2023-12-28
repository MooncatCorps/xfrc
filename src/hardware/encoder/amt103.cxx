#ifndef XFRC_HARDWARE_ENCODER_AMT_103_CXX
#    include "amt103.hh"
#endif

namespace xfrc::hardware {

template <class unit, class time_unit>
auto
amt103<unit, time_unit>::get_distance() -> units::unit_t<unit> {
    return units::unit_t<unit> { _implementation.GetDistance() * _dpr };
}

template <class unit, class time_unit>
auto
amt103<unit, time_unit>::get_velocity()
    -> units::unit_t<units::compound_unit<unit, units::inverse<time_unit>>> {
    return units::unit_t<unit> { _implementation.GetDistance() * _dpr }
         / units::second_t { 1 };
}

template <class unit, class time_unit>
auto
amt103<unit, time_unit>::set_pulses_per_revolution(unsigned int pulses)
    -> void {
    _implementation.SetDistancePerPulse(1.0 / pulses);
    _resolution = pulses;
}

template <class unit, class time_unit>
auto
amt103<unit, time_unit>::pulses_per_revolution() -> unsigned int {
    return _resolution;
}

template <class unit, class time_unit>
auto
amt103<unit, time_unit>::set_distance_per_revolution(double distance) -> void {
    _dpr = distance;
}

} // namespace xfrc::hardware
