#ifndef XFRC_COMPONENT_MOTORCONTROL_MOTOR_CONTROLLER_HH
#define XFRC_COMPONENT_MOTORCONTROL_MOTOR_CONTROLLER_HH

#include "component/component.hh"

namespace xfrc {

class motor_controller : public component {
public:
    explicit motor_controller();

    motor_controller(const motor_controller &) = default;
    motor_controller(motor_controller &&)      = delete;

    auto
    operator= (const motor_controller &) -> motor_controller & = default;
    auto
    operator= (motor_controller &&) -> motor_controller & = delete;

    virtual ~motor_controller() = default;

    virtual auto
    set_operation_percentage() -> void;

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

} // namespace xfrc

#endif
