#include "motor_controller.hh"

#include <frc/smartdashboard/SmartDashboard.h>

namespace xfrc::hardware {

motor_controller::motor_controller(std::string constant_name,
                                   std::string variable_name)
    : entity(std::move(constant_name), std::move(variable_name)) { }

auto
motor_controller::set_max_output_possible(double output) -> void {
    _max_output_possible = output;
}

auto
motor_controller::max_output_possible() const -> double {
    return _max_output_possible;
}

auto
motor_controller::set_min_output_possible(double output) -> void {
    _min_output_possible = output;
}

auto
motor_controller::min_output_possible() const -> double {
    return _min_output_possible;
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
