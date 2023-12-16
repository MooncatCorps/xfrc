#include "motor_controller.hh"

namespace xfrc::hardware {

auto
motor_controller::stop_movement() -> void {
    this->set_power_output_percentage(0);
}

} // namespace xfrc::hardware
