#ifndef XFRC_HARDWARE_MOTOR_CONTROLLER_VICTOR_SP_HH
#define XFRC_HARDWARE_MOTOR_CONTROLLER_VICTOR_SP_HH

#include "motor_controller.hh"
#include <cstdint>
#include <frc/motorcontrol/VictorSP.h>
#include <string>

namespace xfrc::hardware {

namespace settings {

struct victor_sp_settings {
    uint8_t id;
};

} // namespace settings

class victor_sp : motor_controller {
public:
    explicit victor_sp(settings::victor_sp_settings settings,
                       std::string                  custom_name = "unnamed");

    auto
    set_power_output(double percentage) -> void override;

    auto
    power_output() -> double override;

    auto
    set_inversion_state(bool is_inverted) -> void override;

    auto
    is_inverted() -> bool override;

    auto
    on_enable() -> void override;

    auto
    on_disable() -> void override;

    auto
    on_reset() -> void override;

private:
    double static constexpr ABSOLUTE_MAX_VOLTAGE = 12;

    frc::VictorSP _implementation;
    uint8_t       _identifier;
};

} // namespace xfrc::hardware

#endif
