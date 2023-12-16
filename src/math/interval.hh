#ifndef XFRC_MATH_INTERVAL_HH
#define XFRC_MATH_INTERVAL_HH

#include <cstdint>
#include <vector>

namespace xfrc::math {

class floating_point_interval;

class integer_interval {
public:
    explicit integer_interval(std::int32_t start,
                              std::int32_t end,
                              bool         start_inclusive = true,
                              bool         end_inclusive   = true);

    [[nodiscard]] auto
    contains(std::int32_t value) const -> bool;

    [[nodiscard]] auto
    length() const -> unsigned long;

    [[nodiscard]] auto
    midpoint() const -> double;

    [[nodiscard]] auto
    to_vector() const -> std::vector<std::int32_t>;

    [[nodiscard]] auto
    is_start_inclusive() const -> bool;

    [[nodiscard]] auto
    is_start_exclusive() const -> bool;

    auto
    make_start_inclusive() -> void;

    auto
    make_start_exclusive() -> void;

    [[nodiscard]] auto
    is_end_inclusive() const -> bool;

    [[nodiscard]] auto
    is_end_exclusive() const -> bool;

    auto
    make_end_inclusive() -> void;

    auto
    make_end_exclusive() -> void;

    [[nodiscard]] auto
    start() const -> std::int32_t;

    [[nodiscard]] auto
    end() const -> std::int32_t;

    [[nodiscard]] auto
    to_floating_point_interval() const -> floating_point_interval;

private:
    std::int32_t _start;
    std::int32_t _end;

    bool _start_inclusive;
    bool _end_inclusive;
};

class floating_point_interval {
public:
    explicit floating_point_interval(double start,
                                     double end,
                                     bool   start_inclusive = true,
                                     bool   end_inclusive   = true);

    [[nodiscard]] auto
    contains(double value) const -> bool;

    [[nodiscard]] auto
    length() const -> double;

    [[nodiscard]] auto
    midpoint() const -> double;

    [[nodiscard]] auto
    is_start_inclusive() const -> bool;

    [[nodiscard]] auto
    is_start_exclusive() const -> bool;

    auto
    make_start_inclusive() -> void;

    auto
    make_start_exclusive() -> void;

    [[nodiscard]] auto
    is_end_inclusive() const -> bool;

    [[nodiscard]] auto
    is_end_exclusive() const -> bool;

    auto
    make_end_inclusive() -> void;

    auto
    make_end_exclusive() -> void;

    [[nodiscard]] auto
    start() const -> double;

    [[nodiscard]] auto
    end() const -> double;

    [[nodiscard]] auto
    to_integer_interval() const -> integer_interval;

private:
    double _start;
    double _end;

    bool _start_inclusive;
    bool _end_inclusive;
};

} // namespace xfrc::math

#endif
