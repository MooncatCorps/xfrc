#include "victor_sp.hh"

namespace xfrc::hardware {

victor_sp::victor_sp(settings::victor_sp_settings settings,
                     std::string                  custom_name)
    : motor_controller("Victor SP", std::move(custom_name))
    , _implementation(settings.id)
    , _identifier(settings.id) { }

auto
victor_sp::set_power_output(double percentage) -> void {
    if (is_disabled()) {
        return;
    }

    _implementation.Set(std::clamp(
        std::clamp(percentage, NEGATIVE_OUTPUT_LIMIT, POSITIVE_OUTPUT_LIMIT),
        min_output_possible(),
        max_output_possible()));
}

auto
victor_sp::power_output() -> double {
    return _implementation.Get();
}

auto
victor_sp::set_inversion_state(bool is_inverted) -> void {
    _implementation.SetInverted(is_inverted);
}

auto
victor_sp::is_inverted() -> bool {
    return _implementation.GetInverted();
}

auto
victor_sp::on_enable() -> void { }

auto
victor_sp::on_disable() -> void {
    set_power_output(0.0);
}

auto
victor_sp::on_reset() -> void { }

} // namespace xfrc::hardware
