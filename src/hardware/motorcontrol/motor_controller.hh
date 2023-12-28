#ifndef XFRC_COMPONENT_MOTORCONTROL_MOTOR_CONTROLLER_HH
#define XFRC_COMPONENT_MOTORCONTROL_MOTOR_CONTROLLER_HH

#include "entity/entity.hh"
#include <string>
#include <units/voltage.h>

namespace xfrc::hardware {

class motor_controller : public entity::entity {
public:
    explicit motor_controller(std::string constant_name,
                              std::string variable_name = "unnamed");

    virtual auto
    set_power_output(double percentage) -> void = 0;

    virtual auto
    power_output() -> double = 0;

    virtual auto
    set_inversion_state(bool is_inverted) -> void = 0;

    virtual auto
    is_inverted() -> bool = 0;

    auto
    set_max_output_possible(double output) -> void;

    [[nodiscard]] auto
    max_output_possible() const -> double;

    auto
    set_min_output_possible(double output) -> void;

    [[nodiscard]] auto
    min_output_possible() const -> double;

    auto
    set_output_multiplier(double multiplier) -> void;

    [[nodiscard]] auto
    output_multiplier() const -> double;

    auto
    stop_movement() -> void;

protected:
    double static constexpr POSITIVE_OUTPUT_LIMIT = +1;
    double static constexpr NEGATIVE_OUTPUT_LIMIT = -1;

private:
    double _max_output_possible = 1.0;
    double _min_output_possible = -1.0;
    double _output_multiplier   = 1.0;
};

} // namespace xfrc::hardware

#endif
