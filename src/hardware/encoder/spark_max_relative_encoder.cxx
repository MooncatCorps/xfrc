#ifndef XFRC_HARDWARE_ENCODER_SPARK_MAX_RELATIVE_ENCODER_CXX
#    include "spark_max_relative_encoder.hh"
#endif

namespace xfrc::hardware {

template <class unit, class time_unit>
spark_max_relative_encoder<unit, time_unit>::spark_max_relative_encoder(
    can_spark_max &from)
    : _implementation(from->GetEncoder()) { }

template <class unit, class time_unit>
auto
spark_max_relative_encoder<unit, time_unit>::get_distance()
    -> units::unit_t<unit> {
    return _implementation.GetPosition();
}

template <class unit, class time_unit>
auto
spark_max_relative_encoder<unit, time_unit>::get_velocity()
    -> units::unit_t<units::compound_unit<unit, units::inverse<time_unit>>> {
    return _implementation.GetVelocity();
}

template <class unit, class time_unit>
auto
spark_max_relative_encoder<unit, time_unit>::set_pulses_per_revolution(
    unsigned int pulses) -> void {
    // Spark Max Encoders don't support this
}

template <class unit, class time_unit>
auto
spark_max_relative_encoder<unit, time_unit>::pulses_per_revolution()
    -> unsigned int {
    return _implementation.GetCountsPerRevolution();
}

template <class unit, class time_unit>
auto
spark_max_relative_encoder<unit, time_unit>::set_distance_per_revolution(
    double distance) -> void {
    _implementation.SetPositionConversionFactor(distance);
}

} // namespace xfrc::hardware
