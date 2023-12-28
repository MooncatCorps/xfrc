#ifndef XFRC_CONTROL_PID_PID_CONTROLLER_HH
#define XFRC_CONTROL_PID_PID_CONTROLLER_HH

#include "entity/entity.hh"
#include <frc/controller/PIDController.h>
#include <functional>

namespace xfrc::control {

class pid_controller : entity::entity {
public:
    explicit pid_controller(double proportional,
                            double integral,
                            double derivative);

    virtual auto
    set_coefficients(double proportional, double integral, double derivative)
        -> void = 0;

    virtual auto
    set_p(double proportional) -> void = 0;

    virtual auto
    set_i(double integral) -> void = 0;

    virtual auto
    set_d(double derivative) -> void = 0;

    virtual auto
    set_setpoint() -> void = 0;

    virtual auto
    has_reached_setpoint() -> bool = 0;

    virtual auto
    set_tolerance(double tolerance) -> void = 0;

    virtual auto
    on_read_do(std::function<double()> func) -> void = 0;

    virtual auto
    on_feed_do(std::function<void(double)> func) -> void = 0;

    virtual auto
    update() -> void = 0;

    virtual auto
    feed() -> void = 0;

    virtual auto
    update_and_feed() -> void = 0;

    virtual auto
    set_continuous_input_range(double low, double high) -> void = 0;

    virtual auto
    enable_continuous_input_range() -> void = 0;

    virtual auto
    disable_continuous_input_range() -> void = 0;

private:
    std::function<double()>     _on_read;
    std::function<void(double)> _on_feed;
};

} // namespace xfrc::control

#endif
