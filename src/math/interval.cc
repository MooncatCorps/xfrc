#include "interval.hh"

#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <numeric>
#include <stdexcept>
#include <vector>

//// ii ////

namespace xfrc::math {

integer_interval::integer_interval(std::int32_t start,
                                   std::int32_t end,
                                   bool         start_inclusive,
                                   bool         end_inclusive)
    : _start(start)
    , _end(end)
    , _start_inclusive(start_inclusive)
    , _end_inclusive(end_inclusive) {
    if (_start > _end) {
        throw std::logic_error { "[integer_interval] the starting point cannot "
                                 "be placed after the ending point" };
    }
}

auto
integer_interval::contains(std::int32_t value) const -> bool {
    return (_start_inclusive ? value >= _start : value > _start)
        && (_end_inclusive ? value <= _end : value < _end);
}

auto
integer_interval::length() const -> unsigned long {
    return std::abs(_start - _end);
}

auto
integer_interval::midpoint() const -> double {
    static double constexpr two = 2.0;
    return std::abs(_start - _end) / two;
}

auto
integer_interval::to_vector() const -> std::vector<std::int32_t> {
    unsigned long length = this->length();

    switch (length) {
    case 0 : {
        if (_start_inclusive && _end_inclusive) {
            return std::vector<std::int32_t> { _start };
        }

        return std::vector<std::int32_t> {};
    }

    case 1 : {
        if (! _start_inclusive && ! _end_inclusive) {
            return std::vector<std::int32_t>(0);
        }

        if (! _start_inclusive) {
            return std::vector<std::int32_t> { _end };
        }

        if (! _end_inclusive) {
            return std::vector<std::int32_t> { _start };
        }
    } break;

    case 2 : {
        if (! _start_inclusive && ! _end_inclusive) {
            return std::vector<std::int32_t> { _start + 1 };
        }
    } break;

    default :
        break;
    }

    std::vector<std::int32_t> vec(length - (_start_inclusive ? 0UL : 1UL)
                                  + (_end_inclusive ? 1UL : 0UL));
    std::iota(vec.begin(), vec.end(), (_start_inclusive ? _start : _start + 1));

    return vec;
}

auto
integer_interval::is_start_inclusive() const -> bool {
    return this->_start_inclusive;
}

auto
integer_interval::is_start_exclusive() const -> bool {
    return ! this->_start_inclusive;
}

auto
integer_interval::make_start_inclusive() -> void {
    this->_start_inclusive = true;
}

auto
integer_interval::make_start_exclusive() -> void {
    this->_start_inclusive = false;
}

auto
integer_interval::is_end_inclusive() const -> bool {
    return this->_end_inclusive;
}

auto
integer_interval::is_end_exclusive() const -> bool {
    return ! this->_end_inclusive;
}

auto
integer_interval::make_end_inclusive() -> void {
    this->_end_inclusive = true;
}

auto
integer_interval::make_end_exclusive() -> void {
    this->_end_inclusive = false;
}

auto
integer_interval::start() const -> std::int32_t {
    return this->_start;
}

auto
integer_interval::end() const -> std::int32_t {
    return this->_start;
}

auto
integer_interval::to_floating_point_interval() const
    -> floating_point_interval {
    return floating_point_interval { static_cast<double>(_start),
                                     static_cast<double>(_end),
                                     _start_inclusive,
                                     _end_inclusive };
}

//// fpi ////

floating_point_interval::floating_point_interval(double start,
                                                 double end,
                                                 bool   start_inclusive,
                                                 bool   end_inclusive)
    : _start(start)
    , _end(end)
    , _start_inclusive(start_inclusive)
    , _end_inclusive(end_inclusive) {
    if (_start > _end) {
        throw std::logic_error {
            "[floating_point_interval] the starting point cannot "
            "be placed after the ending point"
        };
    }
}

auto
floating_point_interval::contains(double value) const -> bool {
    return (_start_inclusive ? value >= _start : value > _start)
        && (_end_inclusive ? value <= _end : value < _end);
}

auto
floating_point_interval::length() const -> double {
    return std::abs(_start - _end);
}

auto
floating_point_interval::midpoint() const -> double {
    static double constexpr two = 2.0;
    return std::abs(_start - _end) / two;
}

auto
floating_point_interval::is_start_inclusive() const -> bool {
    return this->_start_inclusive;
}

auto
floating_point_interval::is_start_exclusive() const -> bool {
    return ! this->_start_inclusive;
}

auto
floating_point_interval::make_start_inclusive() -> void {
    this->_start_inclusive = true;
}

auto
floating_point_interval::make_start_exclusive() -> void {
    this->_start_inclusive = false;
}

auto
floating_point_interval::is_end_inclusive() const -> bool {
    return this->_end_inclusive;
}

auto
floating_point_interval::is_end_exclusive() const -> bool {
    return ! this->_end_inclusive;
}

auto
floating_point_interval::make_end_inclusive() -> void {
    this->_end_inclusive = true;
}

auto
floating_point_interval::make_end_exclusive() -> void {
    this->_end_inclusive = false;
}

auto
floating_point_interval::start() const -> double {
    return this->_start;
}

auto
floating_point_interval::end() const -> double {
    return this->_start;
}

auto
floating_point_interval::to_integer_interval() const -> integer_interval {
    return integer_interval { static_cast<std::int32_t>(std::round(_start)),
                              static_cast<std::int32_t>(std::round(_end)),
                              _start_inclusive,
                              _end_inclusive };
}

} // namespace xfrc::math
