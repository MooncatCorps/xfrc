#include "function.hh"

#include <cstdlib>

namespace xfrc::math {

template <typename _tp>
auto
sgn(_tp value) -> std::int8_t {
    return value / std::abs(value);
}

} // namespace xfrc::math
