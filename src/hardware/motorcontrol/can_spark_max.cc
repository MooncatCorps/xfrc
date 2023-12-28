#include "can_spark_max.hh"

#include <algorithm>

namespace xfrc::hardware {

can_spark_max::can_spark_max(settings::can_spark_max_settings settings,
                             std::string                      custom_name)
    : motor_controller("CAN Spark Max", std::move(custom_name))
    , _implementation(settings.id, settings.motor_type)
    , _identifier(settings.id) {
    _implementation.SetIdleMode(settings.idle_mode);
}

auto
can_spark_max::set_power_output(double percentage) -> void {
    if (is_disabled()) {
        return;
    }

    _implementation.Set(std::clamp(
        std::clamp(percentage, NEGATIVE_OUTPUT_LIMIT, POSITIVE_OUTPUT_LIMIT),
        min_output_possible(),
        max_output_possible()));
}

auto
can_spark_max::power_output() -> double {
    return _implementation.Get();
}

auto
can_spark_max::set_inversion_state(bool is_inverted) -> void {
    _implementation.SetInverted(is_inverted);
}

auto
can_spark_max::is_inverted() -> bool {
    return _implementation.GetInverted();
}

auto
can_spark_max::on_enable() -> void {
    _implementation.ClearFaults();
}

auto
can_spark_max::on_disable() -> void {
    set_power_output(0.0);
    _implementation.Disable();
}

auto
can_spark_max::on_reset() -> void {
    _implementation.ClearFaults();
}

auto
can_spark_max::operator->() -> rev::CANSparkMax * {
    return &_implementation;
}

} // namespace xfrc::hardware
