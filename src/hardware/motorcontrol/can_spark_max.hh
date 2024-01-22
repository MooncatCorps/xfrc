#ifndef XFRC_HARDWARE_MOTOR_CONTROLLER_CAN_SPARK_MAX_HH
#define XFRC_HARDWARE_MOTOR_CONTROLLER_CAN_SPARK_MAX_HH

#include "motor_controller.hh"
#include <cstdint>
#include <rev/CANSparkMax.h>
#include <string>

namespace xfrc::hardware {

namespace settings {

struct can_spark_max_settings {
    uint8_t                     id;
    rev::CANSparkMax::MotorType motor_type;
    rev::CANSparkMax::IdleMode  idle_mode;
};

} // namespace settings

class can_spark_max : motor_controller {
public:
    explicit can_spark_max(settings::can_spark_max_settings settings,
                           std::string custom_name = "unnamed");

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

    auto
    operator->() -> rev::CANSparkMax *;

private:
    double static constexpr ABSOLUTE_MAX_VOLTAGE = 12;

    rev::CANSparkMax _implementation;
    uint8_t          _identifier;
};

} // namespace xfrc::hardware

#endif
