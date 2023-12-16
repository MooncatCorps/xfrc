#include "hardware_component.hh"

namespace xfrc::hardware {

hardware_component::hardware_component(std::string name)
    : entity(std::move(name))
    , _is_enabled(false) { }

auto
hardware_component::is_enabled() const -> bool {
    return this->_is_enabled;
}

auto
hardware_component::enable() -> void {
    this->_is_enabled = true;
    this->on_disable();
}

auto
hardware_component::disable() -> void {
    this->_is_enabled = false;
    this->on_enable();
}

} // namespace xfrc::hardware
