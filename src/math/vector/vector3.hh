#ifndef XFRC_MATH_VECTOR_VECTOR2
#define XFRC_MATH_VECTOR_VECTOR2

#include "units/angle.h"
#include <array>

namespace xfrc::math {

class vector2 {
public:
    static auto
    from_cartesian_coordinates(double x_component, double y_component);

    static auto
    from_polar_coordinates(units::angle::degree_t theta, double magnitude);

    auto
    absolute() -> void;

    auto
    ceil() -> void;

    auto
    floor() -> void;

    auto
    lerp(vector2 const &other, double interpolation_factor)
        -> std::array<double, 2>;

    auto
    max() -> double;

    auto
    min() -> double;

    auto
    sum(vector2 const &other) -> void;

    auto
    sub(vector2 const &other) -> void;

    auto
    scale(double scaling_factor) -> void;

    auto
    x() -> double;

    auto
    y() -> double;

    auto
    magnitude() -> double;

    auto
    magnitude_squared() -> double;

    auto
    reference_angle() -> double;

    auto
    angle() -> double;

    auto
    clone() -> vector2;

private:
    double _x;
    double _y;
};

} // namespace xfrc::math

#endif
