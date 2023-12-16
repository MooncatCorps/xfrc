#ifndef XFRC_COMPONENT_MOTORCONTROL_MOTOR_CONTROLLER_HH
#define XFRC_COMPONENT_MOTORCONTROL_MOTOR_CONTROLLER_HH

#include "hardware/hardware_component.hh"
#include <string>

namespace xfrc::hardware {

class motor_controller : public virtual hardware_component {
public:
    explicit motor_controller(std::string name);

    virtual auto
    set_power_output_percentage(double percentage) -> void;
    virtual auto
    power_output_percentage() -> double;

    virtual auto
    set_inversion_state(bool is_inverted) -> void;
    virtual auto
    is_inverted() -> bool;

    auto
    stop_movement() -> void;

private:
    int static const positive_limit_ = +1;
    int static const negative_limit_ = -1;
};

} // namespace xfrc::hardware

#endif
