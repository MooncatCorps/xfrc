#include "motor_controller.hh"

#include <frc/smartdashboard/SmartDashboard.h>

namespace xfrc::hardware {

    motor_controller::motor_controller() = default;

    motor_controller::motor_controller(const motor_controller &) = default;

    motor_controller::~motor_controller() = default;

    auto motor_controller::operator= (const motor_controller &) -> motor_controller& = default;

auto
motor_controller::set_max_output_possible(double output) -> void {
    _max_possible_output = output;
}

auto
motor_controller::max_output_possible() const -> double {
    return _max_possible_output;
}

auto
motor_controller::set_min_output_possible(double output) -> void {
    _min_possible_output = output;
}

auto
motor_controller::min_output_possible() const -> double {
    return _min_possible_output;
}

auto
motor_controller::set_output_multiplier(double multiplier) -> void {
    _output_multiplier = multiplier;
}

auto
motor_controller::output_multiplier() const -> double {
    return _output_multiplier;
}

auto
motor_controller::stop_movement() -> void {
    this->set_power_output(0);
}

} // namespace xfrc::hardware
