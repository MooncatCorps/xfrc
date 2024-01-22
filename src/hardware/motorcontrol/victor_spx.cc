#include "victor_spx.hh"

namespace xfrc::hardware {

victor_spx::victor_spx(settings::victor_spx_settings settings,
                       std::string                   custom_name)
    : motor_controller("Victor SPX", std::move(custom_name))
    , _implementation(settings.id)
    , _identifier(settings.id) { }

auto
victor_spx::set_power_output(double percentage) -> void {
    if (is_disabled()) {
        return;
    }

    _implementation.Set(ctremc::ControlMode::PercentOutput,
                        std::clamp(std::clamp(percentage,
                                              NEGATIVE_OUTPUT_LIMIT,
                                              POSITIVE_OUTPUT_LIMIT),
                                   min_output_possible(),
                                   max_output_possible()));
}

auto
victor_spx::power_output() -> double {
    return _implementation.GetMotorOutputPercent();
}

auto
victor_spx::set_inversion_state(bool is_inverted) -> void {
    _implementation.SetInverted(is_inverted);
}

auto
victor_spx::is_inverted() -> bool {
    return _implementation.GetInverted();
}

auto
victor_spx::on_enable() -> void {
    _implementation.ClearStickyFaults();
}

auto
victor_spx::on_disable() -> void {
    set_power_output(0.0);
}

auto
victor_spx::on_reset() -> void {
    _implementation.ClearStickyFaults();
}

} // namespace xfrc::hardware
